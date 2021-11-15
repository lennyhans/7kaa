FROM debian:bullseye-slim
# MAINTAINER NAME EMAIL

ARG DEBIAN_FRONTEND=noninteractive
ENV DEBIAN_FRONTEND noninteractive
ENV DEBIAN_PRIORITY critical
ENV DEBCONF_NOWARNINGS yes
ENV BASE_DIR=/app/build

WORKDIR /app

RUN apt-get -y update && \
apt-get -y upgrade && \
  apt-get install -y build-essential  && \
  apt-get install -y \
  libsdl2-dev \
  libenet-dev \
  libopenal-dev \
  #libcurl-dev \
  libcurl4-openssl-dev \
  gettext \
  autoconf \
  pkg-config \
  bash \
  autopoint \
  make \
  binutils \
  gcc

COPY missing .
COPY . ./

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
RUN make -j$(nproc)
# Where NAME is your full name and EMAIL is your email address.
