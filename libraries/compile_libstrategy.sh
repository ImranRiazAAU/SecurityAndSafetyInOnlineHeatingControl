#!/bin/bash

cd libstrategy
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DLIBSTRATEGY_OnlyLibrary=ON -DCMAKE_INSTALL_PREFIX=../install
make
make install

