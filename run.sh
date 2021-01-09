#!/bin/bash

SRC_DIR="src"
LIB_PATH="lib/cryptopp/libcryptopp.a"

mkdir -p bin
g++ -Iinclude ${SRC_DIR}/*.cpp ${LIB_PATH} -o bin/main && \
./bin/main > res/keys_output