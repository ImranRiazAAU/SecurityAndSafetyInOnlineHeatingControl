
#!/bin/bash

N=10
export L='7'
export I='24'
export IT='5'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM

#running feb week
export MONTH='2'
export DAY='4'

export C=0
for R in 300 1200 2400 4800 9600; do
export  RUNS="$R" 

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm_new.sh ; done


done
done
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
