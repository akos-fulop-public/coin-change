FROM ubuntu

RUN apt update && apt install -y build-essential cmake libgtest-dev clang-tidy && rm -rf /var/lib/apt/lists/*

WORKDIR /src/build
