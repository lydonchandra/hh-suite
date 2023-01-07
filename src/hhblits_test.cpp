#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "hhhmm.h"
#include "hhblits.h"

TEST_CASE("Test HMM 1", "[hmm]") {
    HMM *hmm = new HMM(MAXSEQDIS, 1000);
    REQUIRE(hmm != NULL);

    Parameters par(1, NULL);
    std::vector<HHblitsDatabase *> databases;
    HHblits::prepareDatabases(par, databases);
    HHblits blits(par, databases);
}

