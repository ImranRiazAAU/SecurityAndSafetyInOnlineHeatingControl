#!/bin/bash

g++ -std=c++17 -fPIC -shared connectUPPAALCTRL.cpp  -o connectUPPAALCTRL.so
g++ -std=c++17 -fPIC -shared data_reader.cpp -o data_reader.so
g++ -std=c++17 -fPIC -shared -I./libstrategy/install/include -I./libstrategy/build/external/include/ useStrategy.cpp ./libstrategy/build/lib/libstrategy.a -o useStrategy.so
g++ -std=c++17 -fPIC -shared libParam.cpp  -o libParam.so
g++ -std=c++17 -fPIC -shared start_em.cpp  -o start_em.so
g++ -std=c++17 -fPIC -shared weights.cpp  -o weights.so
g++ -std=c++17 -fPIC -shared store_data.cpp  -o store_data.so

