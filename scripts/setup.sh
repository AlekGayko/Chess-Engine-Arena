#!/bin/bash
set -e

if [ ! -d "./vcpkg" ]; then
  git clone https://github.com/microsoft/vcpkg.git
fi

cd vcpkg
./bootstrap-vcpkg.sh
cd ..
./vcpkg/vcpkg install

mkdir -p third-party
cd third-party

if [ ! -d "./chess-library" ]; then
  git clone https://github.com/Disservin/chess-library.git
fi

cd ..