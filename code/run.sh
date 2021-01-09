#!/bin/bash

SRC_DIR="src"
LIB_PATH="lib/cryptopp/libcryptopp.a"

g++ -Iinclude ${SRC_DIR}/*.cpp ${LIB_PATH} -o bin/main && \
./bin/main > res/output.txt