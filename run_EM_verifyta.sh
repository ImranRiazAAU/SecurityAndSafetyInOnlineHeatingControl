#!/bin/bash 

export STRATEGY_DIR=$(pwd)/results/$RANDOM
echo "Running with strategy directory $STRATEGY_DIR"
mkdir -p $STRATEGY_DIR
cp ./intial_th_ti_for_LM/* $STRATEGY_DIR
./uppaal/bin/verifyta -s -D 0.1 ./models/EM.xml > $STRATEGY_DIR/Result.txt
