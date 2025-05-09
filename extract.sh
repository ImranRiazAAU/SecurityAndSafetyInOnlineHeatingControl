#!/bin/bash

D="DATA"

P="$1"
echo "Extracting for $P"
if [ -z "$P" ] ; then
	echo "Missing Path"
fi

if [ ! -d "$P" ] ; then
	echo "Not a folder $P"
fi

B=$(basename $P)
D="$D/$B/"

mkdir -p $D
for START in $(ls $P ) ; do
	echo $START
	FP="$P/$START"
	for W in $(ls $FP ) ; do
		echo "	$W"
		WFP="$FP/$W"
		for R in $(ls $WFP) ; do
			#echo "		$R"
			RFP="$WFP/$R"
			OF="$D/$START.$R.$W"
			truncate -s 0 $OF
			for J in $(ls $RFP ) ; do 
				#echo "				$J"
				RES="$RFP/$J/Result.txt"
				if [ -f $RES ] ; then
					MEAN=$(grep -oP "(?<=mean=)[0-9]+(\.[0-9]+)?" $RES)
					COMCOST=$(cat $RFP/$J/cost_and_discomfort_values.txt | paste -sd, -)
					echo "$MEAN,$COMCOST" >> $OF
				fi
			done
		done
	done
done

