FROM ubuntu

RUN apt update && apt install -y build-essential cmake clang-tidy python3-venv && rm -rf /var/lib/apt/lists/*
RUN python3 -m venv /venv && /venv/bin/pip install conan
ENV PATH="$PATH:/venv/bin"
RUN conan profile detect

WORKDIR /src
