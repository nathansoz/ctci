#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -d ${SCRIPT_DIR}/build ] ; then
  rm -rf ${SCRIPT_DIR}/build
fi

mkdir ${SCRIPT_DIR}/build
pushd ${SCRIPT_DIR}/build
cmake ..
make
popd