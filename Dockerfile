FROM ubuntu

RUN apt update && apt install -y build-essential cmake libgtest-dev && rm -rf /var/lib/apt/lists/*

WORKDIR /src/build
