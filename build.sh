docker build -t fifo-advisor-dev \
  --build-arg HOST_UID=$(id -u) \
  --build-arg HOST_GID=$(id -g) \
  --build-arg USERNAME="$(id -un)" \
  --build-arg CONDA_ENV_NAME=fifo-advisor \
  .
