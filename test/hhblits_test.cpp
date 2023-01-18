#define CATCH_CONFIG_MAIN
#ifdef OPENMP

#include <omp.h>

#endif

#include <catch2/catch.hpp>
#include "hhhmm.h"
#include "hhblits.h"

TEST_CASE("Test HMM 1", "[hmm]") {
    HMM *hmm = new HMM(MAXSEQDIS, 1000);
    REQUIRE(hmm != NULL);

    Parameters param(1, NULL);
    std::vector<HHblitsDatabase *> databases;
    HHblits::prepareDatabases(param, databases);
    HHblits blits(param, databases);
    std::string fastaPath = "../../data/tp53.faa";
    FILE *queryFile = fopen(fastaPath.c_str(), "r");
    char input_format = 0;
    char use_global_weight = 0;
    Alignment *queryAlign = new Alignment(param.maxseq, param.maxres);
    HMM *queryHmm = new HMM(MAXSEQDIS, param.maxres);
    char infile[NAMELEN];
    strcpy(infile, fastaPath.c_str());
    ReadQueryFile(param, queryFile, input_format, use_global_weight, queryHmm, queryAlign, infile, blits.pb, blits.S,
                  blits.Sim);
    REQUIRE(queryHmm != NULL);
    REQUIRE(queryAlign->X != NULL);
    REQUIRE(queryAlign->X[0][0] == 0x14);
}

TEST_CASE("Test HHBlitsDatabase1", "[hhblitsDatabase]") {
    std::string dbPath = "../../database/uniclust30_2018_08/uniclust30_2018_08";
    HHblitsDatabase *db = new HHblitsDatabase(dbPath.c_str(), true);
    REQUIRE(db->cs219_database != NULL);
    REQUIRE(db->query_database == db->a3m_database);
}

