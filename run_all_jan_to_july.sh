
#!/bin/bash

N=10
export L='7'
export I='24'
export IT='5'

#running Jan week
export MONTH='1'
export DAY='10'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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


#running Feb week
export MONTH='2'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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


#running Mar week
export MONTH='3'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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




#running Apr week
export MONTH='4'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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


#running may week
export MONTH='5'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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


# running Jun week
export MONTH='6'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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

# running Jul week
export MONTH='7'
export DAY='4'
export OFF='0'
E=1 #0 for Th,Te from EM; 1 for Th,Te from LM


export C=0
for R in 300 600; do
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

