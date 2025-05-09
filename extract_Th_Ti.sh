#!/bin/bash

D="ThTe"

P="$1"
echo "Extracting for $P"
if [ -z "$P" ]; then
  echo "Missing Path"
fi

if [ ! -d "$P" ]; then
  echo "Not a folder $P"
fi

B=$(basename $P)
D="$D/$B/"
mkdir -p $D
for START in $(ls $P); do
  echo $START
  last=${START: -1}
  FP="$P/$START"
  if [ $last -le 0 ]; then
    for W in $(ls $FP); do
      WFP="$FP/$W"
      for R in $(ls $WFP); do
        RFP="$WFP/$R"
        OF="$D/$START.$R.$W"
        mkdir $OF
        for J in $(ls $RFP); do
          cp $RFP/$J/EM_floor_temp_log.txt $OF
          cp $RFP/$J/LM_floor_temp_log.txt $OF
          cp $RFP/$J/EM_envelop_temp_log.txt $OF
          cp $RFP/$J/LM_envelop_temp_log.txt $OF
        done
      done
    done
  fi
done
