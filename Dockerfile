# Dockerfile - dev image for fifo-advisor / LightningSim development
# - Creates a user matching host UID/GID (pass --build-arg HOST_UID / HOST_GID)
# - Builds the conda environment from environment.yml copied into the build context
# - Does NOT pip-install the GitHub repo (you can mount your working tree at /workspace)
# - Provides /usr/local/bin/activate-env.sh which sources conda, activates the env and (optionally) sources VITIS_HLS_SETTINGS
FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive
ENV DEBIAN_FRONTEND=${DEBIAN_FRONTEND}

# ---------------------------
# Basic tools & dependencies
# ---------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
    bash curl ca-certificates bzip2 \
    locales \
    libtinfo5 libxrender1 libxrandr2 libxi6 libxtst6 libxcursor1 libxinerama1 libgtk2.0-0 libnss3 \
    build-essential make cmake pkg-config \
    python3 python3-distutils \
    zip unzip gzip vim mpich git \
    && rm -rf /var/lib/apt/lists/*

# Locale (fixes Vitis HLS crash)
RUN sed -i 's/# *en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    locale-gen && \
    update-locale LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8
ENV LANG=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8 \
    LANGUAGE=en_US:en

# ---------------------------
# Miniconda
# ---------------------------
ENV CONDA_DIR=/opt/conda
ENV PATH=${CONDA_DIR}/bin:${PATH}

RUN curl -fsSL https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -o /tmp/m.sh \
    && bash /tmp/m.sh -b -p "${CONDA_DIR}" \
    && rm -f /tmp/m.sh

SHELL ["/bin/bash", "-lc"]

# prefer conda-forge and avoid `defaults`
RUN conda config --system --remove channels defaults || true && \
    conda config --system --add channels conda-forge && \
    conda config --system --set channel_priority strict

# ---------------------------
# Conda env: copy env file & create environment
# ---------------------------
# environment.yml must be in the build context (same dir as Dockerfile or a subdir)
COPY environment.yml /tmp/environment.yml

# Default env name; override with --build-arg CONDA_ENV_NAME=<name> if your environment.yml names another env.
ARG CONDA_ENV_NAME=fifo-advisor
ENV CONDA_ENV_NAME=${CONDA_ENV_NAME}

RUN conda env create -f /tmp/environment.yml && \
    conda clean -afy

# Make the conda installation usable by non-root (read & execute)
RUN chmod -R a+rX "${CONDA_DIR}" || true

# ---------------------------
# User mapping (so files written inside the container are owned by host user)
# ---------------------------
# Pass your host UID/GID at build time:
#   docker build --build-arg HOST_UID=$(id -u) --build-arg HOST_GID=$(id -g) ...
ARG HOST_UID=1001
ARG HOST_GID=1001
ARG USERNAME=developer

# Create group/user and home directory
RUN groupadd --gid ${HOST_GID} ${USERNAME} || true && \
    useradd --uid ${HOST_UID} --gid ${HOST_GID} --create-home --shell /bin/bash ${USERNAME} || true

# Workspace directory (this will be the mount point for your repo)
RUN mkdir -p /workspace && chown -R ${HOST_UID}:${HOST_GID} /workspace

WORKDIR /workspace

# ---------------------------
# Entrypoint script: activate environment and optionally source Vitis
# ---------------------------
# Script name: activate-env.sh (clear, descriptive)
RUN tee /usr/local/bin/activate-env.sh > /dev/null <<'EOF'
#!/usr/bin/env bash
set -euo pipefail

# If CONDA_DIR is set, source conda
if [ -n "${CONDA_DIR:-}" ] && [ -f "${CONDA_DIR}/etc/profile.d/conda.sh" ]; then
  # shellcheck disable=SC1090
  . "${CONDA_DIR}/etc/profile.d/conda.sh"
fi

# Activate environment if name provided
if [ -n "${CONDA_ENV_NAME:-}" ]; then
  # `conda activate` can fail if env name is wrong; we print a helpful message
  if conda env list | awk '{print $1}' | grep -qx "${CONDA_ENV_NAME}"; then
    conda activate "${CONDA_ENV_NAME}"
  else
    echo "Warning: conda environment '${CONDA_ENV_NAME}' not found. Proceeding without activation."
  fi
fi

# Optionally source Vitis settings if the env var points to a valid file
if [ -n "${VITIS_HLS_SETTINGS:-}" ] && [ -f "${VITIS_HLS_SETTINGS}" ]; then
  # shellcheck disable=SC1090
  . "${VITIS_HLS_SETTINGS}"
fi

# Exec the requested command
exec "$@"
EOF

RUN chmod +x /usr/local/bin/activate-env.sh

# ---------------------------
# Expose, user, entrypoint
# ---------------------------

# Default to the mapped non-root user
USER ${USERNAME}

# Make CONDA_ENV_NAME available at runtime
ENV CONDA_ENV_NAME=${CONDA_ENV_NAME}

ENTRYPOINT ["/usr/local/bin/activate-env.sh"]
CMD ["bash"]

