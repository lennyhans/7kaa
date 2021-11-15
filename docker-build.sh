CONTAINER_NAME=7kaa
CONTAINER_VERSION=0.1.0
CONTAINER=${CONTAINER_NAME}:${CONTAINER_VERSION}
BIN_PATH=src/7kaa

sudo docker build . -t ${CONTAINER} -f debian-bullseye.dockerfile && \
  sudo docker cp \
    $(sudo docker create --rm $CONTAINER):/app/${BIN_PATH} \
  .