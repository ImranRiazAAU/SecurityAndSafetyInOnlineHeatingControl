
#!/bin/bash

N=10
export L='7'
export I='24'
export IT='5'
export OFF='0'
export FREQUENCY='24'
export SENSOR1='1'
export SENSOR2='1'
export SENSOR3='1'
export SENSOR4='1'
export STRATEGY='0'
export READING='1'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM

#running feb week
export MONTH='2'
export DAY='4'

#exit
export C=1
for R in 1 ; do
export  RUNS="$R"
for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done

done
done
