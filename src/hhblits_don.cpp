//
// Created by don on 4/01/23.
//

#include <iostream>
#include "hhblits_don.h"
#include "hash.h"
#include "hhhit.h"
#include "hhhmmsimd.h"

int main(int argc, const char **argv) {
    std::cout << "Hi hhblits_don" << std::endl;
    const int nslot = 1631;
    Hit hit_cur;
    Hash<Hit> * hits = new Hash<Hit>(nslot, hit_cur);
    std::cout << hits->Size();
    int max_states = 20001;
    HMM* hmm = new HMM(MAXSEQDIS, max_states);
    HMMSimd hmm_vec(max_states);
//    hmm->
    FILE *file = fopen("../../data/query.seq", "r");
    std::unique_ptr<char[]> line_ptr(new char[LINELEN]);
    char *line = line_ptr.get();
//    if(!fgetline(line, LINELEN, inf)) {
//
//    }
}