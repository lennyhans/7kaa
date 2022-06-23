CONTAINER_NAME=7kaa-debian-build
CONTAINER_VERSION=0.1.0
CONTAINER=${CONTAINER_NAME}:${CONTAINER_VERSION}

if [ -z $1 ]
then
FILE=dockerfile.packaging.bullseye 
else
FILE=$1
fi

CONTAINER_TAG_NAME=$(echo $FILE | awk '{print $2-$3}' FS='.')
docker build . -t ${CONTAINER}-${CONTAINER_TAG_NAME} -f $FILE && \
docker cp \
  $(docker create --rm $CONTAINER-${CONTAINER_TAG_NAME}):/app/ \
 output 
