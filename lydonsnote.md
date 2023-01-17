"/home/don/miniconda3/envs/alphafold/bin/hhsearch -i /tmp/tmp3x9_4884/query.a3m -o /tmp/tmp3x9_4884/output.hhr -maxseq
1000000 -d /media/don/alphafold/pdb70/pdb70"

todo:

1. add tests for viterbi hmm

cmake-build-debug/lib/ffindex/src/ffindex_from_fasta -s data/don_prot1.ffdata data/don_prot1.ffindex data/tp53.faa

## Building Custom Database

1. `cmake-build-debug/lib/ffindex/src/ffindex_from_fasta -s tp53_fas.ff{data,index} data/tp53.faa`

2. Now, to build an MSA with HHblits for each sequence in <db>_fas.ff{data,index}, run
   `mpirun -np 2 cmake-build-debug/src/hhblits_mpi -i tp53_fas -d database/uniclust30_2018_08/uniclust30_2018_08 -oa3m
   tp53_a3m_wo_ss2 -n 2 -cpu 1 -v 0`

3. Computing hidden markov models
   `mpirun -np 2 cmake-build-debug/lib/ffindex/src/ffindex_apply_mpi tp53_a3m.ff{data,index} -i tp53_hhm.ffindex -d tp53_hhm.ffdata -- cmake-build-debug/src/hhmake -i stdin -o stdout -v 0`

4. Computing context states for prefiltering

5. mpirun -np 2 cmake-build-debug/src/cstranslate_mpi -f -x 0.3 -c 4 -I a3m -i tp53_a3m -o tp53_cs219

6. sort -k3 -n -r tp53_cs219.ffindex | cut -f1 > sorting.dat
7. cmake-build-debug/lib/ffindex/src/ffindex_order sorting.dat tp53_hhm.ff{data,index} tp53_hhm_ordered.ff{data,index}
8. cmake-build-debug/lib/ffindex/src/ffindex_order sorting.dat tp53_a3m.ff{data,index} tp53_a3m_ordered.ff{data,index}

