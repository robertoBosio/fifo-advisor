# Dockerfile - dev image for fifo-advisor / LightningSim development
FROM ubuntu:22.04

# allow noninteractive apt operations
ARG DEBIAN_FRONTEND=noninteractive
ENV DEBIAN_FRONTEND=${DEBIAN_FRONTEND}

# Build args / defaults (override at build time)
ARG HOST_UID=1001
ARG HOST_GID=1001
ARG USERNAME=developer
ARG CONDA_ENV_NAME=fifo-advisor

# ---------------------------
# Basic packages
# ---------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
    bash curl ca-certificates bzip2 \
    locales \
    libtinfo5 libxrender1 libxrandr2 libxi6 libxtst6 libxcursor1 libxinerama1 libgtk2.0-0 libnss3 \
    build-essential make cmake pkg-config \
    python3 python3-distutils \
    zip unzip gzip vim mpich git \
    && rm -rf /var/lib/apt/lists/*

# Locale (fixes some Vitis HLS issues)
RUN sed -i 's/# *en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    locale-gen && \
    update-locale LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8
ENV LANG=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8 \
    LANGUAGE=en_US:en

# ---------------------------
# Create non-root user up-front (so CONDA_DIR can live in their home)
# ---------------------------
# Create group/user with specified UID/GID and a real home directory
RUN groupadd --gid ${HOST_GID} ${USERNAME} || true && \
    useradd --uid ${HOST_UID} --gid ${HOST_GID} --create-home --shell /bin/bash ${USERNAME} || true

# Create workspace mount point and set ownership to the user
RUN mkdir -p /workspace && chown -R ${HOST_UID}:${HOST_GID} /workspace

# ---------------------------
# Install Miniconda into the user's home (fast and permissions-friendly)
# ---------------------------
ENV CONDA_DIR=/home/${USERNAME}/conda
ENV PATH=${CONDA_DIR}/bin:${PATH}

# Download and install Miniconda into ${CONDA_DIR}
RUN curl -fsSL https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -o /tmp/m.sh \
    && bash /tmp/m.sh -b -p "${CONDA_DIR}" \
    && rm -f /tmp/m.sh

SHELL ["/bin/bash", "-lc"]

# prefer conda-forge and avoid `defaults` channel (configure the installation)
RUN "${CONDA_DIR}/bin/conda" config --system --remove channels defaults || true && \
    "${CONDA_DIR}/bin/conda" config --system --add channels conda-forge && \
    "${CONDA_DIR}/bin/conda" config --system --set channel_priority strict

# Make sure the conda tree is owned by the target user so later operations don't create root-owned files
RUN chown -R ${HOST_UID}:${HOST_GID} "${CONDA_DIR}"

# ---------------------------
# Create the conda env as the non-root user
# ---------------------------
# Copy environment.yml into the image (must be in build context)
COPY environment.yml /tmp/environment.yml

# Create the environment while running as the non-root user so files are owned by them
RUN su - ${USERNAME} -c "${CONDA_DIR}/bin/conda env create -f /tmp/environment.yml" && \
    su - ${USERNAME} -c "${CONDA_DIR}/bin/conda clean -afy"

# After creating the env, ensure the conda tree is owned by the user (safe)
RUN chown -R ${HOST_UID}:${HOST_GID} "${CONDA_DIR}" /home/${USERNAME}

# ---------------------------
# Entrypoint: activate-env.sh
# - Sources conda
# - Activates the environment (if present)
# - Optionally sources VITIS_HLS_SETTINGS if provided at runtime
# ---------------------------
RUN tee /usr/local/bin/activate-env.sh > /dev/null <<'EOF'
#!/usr/bin/env bash
set -eo pipefail

# if CONDA_DIR is set and conda.sh exists, source it
if [ -n "${CONDA_DIR:-}" ] && [ -f "${CONDA_DIR}/etc/profile.d/conda.sh" ]; then
  # shellcheck disable=SC1090
  . "${CONDA_DIR}/etc/profile.d/conda.sh"
fi

# activate the env if it exists
if [ -n "${CONDA_ENV_NAME:-}" ]; then
  if "${CONDA_DIR}/bin/conda" env list | awk '{print $1}' | grep -qx "${CONDA_ENV_NAME}"; then
    conda activate "${CONDA_ENV_NAME}"
  else
    echo "Warning: conda environment '${CONDA_ENV_NAME}' not found; continuing without activation."
  fi
fi

# optionally source Vitis settings if provided by the user at runtime
if [ -n "${VITIS_HLS_SETTINGS:-}" ] && [ -f "${VITIS_HLS_SETTINGS}" ]; then
  # shellcheck disable=SC1090
  . "${VITIS_HLS_SETTINGS}"
fi

# exec the passed command
exec "$@"
EOF

RUN chmod +x /usr/local/bin/activate-env.sh

# ---------------------------
# Final runtime defaults
# ---------------------------
# ensure workspace owned by user
RUN chown -R ${HOST_UID}:${HOST_GID} /workspace

WORKDIR /workspace

# Run as the mapped non-root user by default
USER ${USERNAME}

# expose the env name to runtime (can be overridden with --env)
ENV CONDA_ENV_NAME=${CONDA_ENV_NAME}
ENV CONDA_DIR=${CONDA_DIR}
ENV PATH=${CONDA_DIR}/bin:${PATH}

ENTRYPOINT ["/usr/local/bin/activate-env.sh"]
CMD ["bash"]

