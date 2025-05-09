
#!/bin/bash

#reuse 24--------------------------------------------

N=10
export L='7'
export I='24'
export IT='5'


#running Jan week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 1200; do
export  RUNS="$R"

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done


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
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done

done
done

#reuse 18--------------------------------------------

export L='7'
export I='18'
export IT='5'


#running Jan week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600 1200; do
export  RUNS="$R"

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done


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
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done

done
done



#reuse 12---------------------------------------

export L='7'
export I='12'
export IT='5'


#running Jan week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600 1200; do
export  RUNS="$R"

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done


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
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done

done
done

#reuse 6----------------------------------------

export L='7'
export I='6'
export IT='5'


#running Jan week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600 1200; do
export  RUNS="$R"

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done


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
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done

done
done

#reuse 3-----------------------------------------

export L='7'
export I='3'
export IT='5'


#running feb week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600 1200; do
export  RUNS="$R"

for i in $(seq 0 10 ) ; do
        export A=$(echo "$i/10" | bc -l)
        export G=$(echo "1-$A" | bc -l)
        export LOAD_ESTIMATED_TH_TE="$E"
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done


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
        for i in $(seq 1 $N); do sbatch run_EM_verifyta_slurm.sh ; done

done
done

