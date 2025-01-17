FROM ubuntu

RUN apt update && apt install -y build-essential cmake && rm -rf /var/lib/apt/lists/*

WORKDIR /src/build
