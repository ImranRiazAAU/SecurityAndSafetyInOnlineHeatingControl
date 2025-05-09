
#!/bin/bash

N=10
export L='7'
export I='24'
export IT='5'
export OFF='0'
export FREQUENCY='12'
export SENSOR1='-8'
export SENSOR2='-8'
export SENSOR3='-8'
export SENSOR4='-8'
export STRATEGY='0'
export READING='1'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM

#running feb week
export MONTH='2'
export DAY='4'

export C=0
for R in 600; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done


done
done
#exit

export FREQUENCY='6'
export C=0
for R in 600; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done


done
done

#exit

export FREQUENCY='3'
export C=0
for R in 600; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done


done
done

#exit

export FREQUENCY='1'
export C=0
for R in 600; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done


done
done
