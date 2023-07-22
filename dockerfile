# FROM debian:bullseye-slim
FROM buildpack-deps:bullseye
# MAINTAINER NAME EMAIL

ARG DEBIAN_FRONTEND=noninteractive
ENV DEBIAN_FRONTEND noninteractive
ENV DEBIAN_PRIORITY critical
ENV DEBCONF_NOWARNINGS yes
ENV BASE_DIR=/app/build

WORKDIR /app

RUN apt-get -y update && \
  # apt-get -y upgrade && \
  # apt-get install -y build-essential  && \
  apt-get install -y \
  libsdl2-dev \
  libenet-dev \
  libopenal-dev \
  #libcurl-dev \
  libcurl4-openssl-dev \
  gettext \
  #autoconf \
  autoconf-archive \
  pkg-config \
  bash \
  autopoint \
  #make \
  binutils 
#gcc

RUN addgroup --gid 1000 devcontainer
RUN adduser --disabled-password --gecos '' --uid 1000 --gid 1000 devcontainer

COPY missing .
COPY . ./

RUN chown devcontainer:devcontainer -R .
USER devcontainer
ENV PATH=/usr/local/bin:/usr/bin:/bin:

RUN /app/autogen.sh
RUN ./configure \
  #--prefix=/app/build \
  #--bindir=games \
  #--datarootdir=share \
  #--datarootdir=share/games \
  #--mandir=share/man \
  #--infodir=share/info \
  --disable-silent-rules 
#CFLAGS="$(CFLAGS)" \
#LDFLAGS="$(LDFLAGS)"
# RUN make -j$(nproc)
# Where NAME is your full name and EMAIL is your email address.
RUN /usr/bin/make -j$(nproc)