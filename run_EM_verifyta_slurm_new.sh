#!/bin/bash 
#SBATCH --time=600:05:00
#SBATCH --partition=rome,naples
#SBATCH --exclude=rome07,naples09
#SBATCH --mem=4000

YEAR='2018'
WEEK_BACK_DATE=$(date -d "$MONTH/$DAY/$YEAR-7 days")
WEEK_BACK_MONTH=$(date -d "$WEEK_BACK_DATE" '+%m')
WEEK_BACK_DAY=$(date -d "$WEEK_BACK_DATE" '+%d')

echo "calculating normalization factor"

export START_DATA="$WEEK_BACK_MONTH $WEEK_BACK_DAY $OFF $L $I 1"
export WEIGHT_VALUES="1.0 1.0 1.0"
export SET_RUNS="1 $IT"

export TEMPDIR=/scratch/xv40pa/
NORMDIR=normalization_factor/$WEEK_BACK_MONTH$WEEK_BACK_DAY/$SLURM_JOB_ID

export STRATEGY_DIR=$TEMPDIR/$SLURM_JOB_ID-NORM

trap "mv -v $TEMPDIR/$SLURM_JOB_ID-NORM $(pwd)/$NORMDIR ; echo terminated-with-move-1 ; exit" 0 # we trap the to make sure we cleanup

mkdir -p $STRATEGY_DIR
mkdir -p $(pwd)/normalization_factor/$WEEK_BACK_MONTH$WEEK_BACK_DAY/

echo "Running with normalization directory $STRATEGY_DIR"
RES=$(./uppaal/bin/verifyta -s -D 0.1 ./models/EM.xml 2>&1 )
echo "$RES" > $STRATEGY_DIR/Result.txt
comfort=$(sed '1q;d' $STRATEGY_DIR/cost_and_discomfort_values.txt)
cost=$(sed '2q;d' $STRATEGY_DIR/cost_and_discomfort_values.txt)
echo "$comfort is comfort"
echo "$cost is cost"
Norm=$(bc <<< "scale=4; $comfort / $cost")
echo "$Norm is the normalization factor "

echo "using normalization factor in full setup"

export START_DATA="$MONTH $DAY $OFF $L $I $C $FREQUENCY $STRATEGY $READING $SENSOR1 $SENSOR2 $SENSOR3 $SENSOR4"
echo "$START_DATA is start data"
export WEIGHT_VALUES="$A $G $Norm"
WEIGHTS_FOR_PATH="$A $G"
echo "$WEIGHT_VALUES is weight_values"
export SET_RUNS="$RUNS $IT"
echo "$SET_RUNS is set runs"

GH=$(git rev-parse --short HEAD)
START=$(eval "printf \"M%dD%dH%dP%dI%dC%dF%dS%dR%dS1%dS2%dS3%dS4%d\" $START_DATA")
WEIGHT=$(eval "printf \"A%0.2fG%0.2f\" $WEIGHTS_FOR_PATH")
OPTS=$(eval "printf \"R%dI%d\" $SET_RUNS")

export STRATEGY_DIR=$TEMPDIR/$SLURM_JOB_ID-STRATEGY
SDIR=results/$GH/$START/$WEIGHT/$OPTS/$SLURM_JOB_ID
trap "mv -v $TEMPDIR/$SLURM_JOB_ID-NORM $(pwd)/$NORMDIR ; mv -v $TEMPDIR/$SLURM_JOB_ID-STRATEGY $(pwd)/$SDIR ; echo terminated-with-move-2 ; exit" 0 # we trap the to make sure we cleanup
echo "Running with strategy directory $STRATEGY_DIR"
mkdir -p $STRATEGY_DIR
mkdir -p $(pwd)/results/$GH/$START/$WEIGHT/$OPTS

cp ./intial_th_ti_for_LM/* $STRATEGY_DIR
RAND=$(od -A n -t dL -N 4 /dev/urandom)
export LM_SEED=$(od -A n -t dL -N 4 /dev/urandom)
RES=$(./uppaal/bin/verifyta --seed $RAND -s -D 0.1 ./models/EM.xml 2>&1 )
echo "$RES" > $STRATEGY_DIR/Result.txt

echo "Done"
