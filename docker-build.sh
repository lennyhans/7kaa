CONTAINER_NAME=7kaa
CONTAINER_VERSION=dev
CONTAINER=${CONTAINER_NAME}:${CONTAINER_VERSION}

FILE=$1 || dockerfile
echo $FILE
# CONTAINER_TAG_NAME=$(echo $FILE | awk '{print $2$3}' FS='.')
docker build . -t ${CONTAINER} -f $FILE && \
docker cp \
  $(docker create --rm $CONTAINER):/app/ \
. && \
#rm -rf app/dest/
ls app/dest
