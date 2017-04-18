#include "test.h"

#ifdef TEST_H_INCLUDED

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "madar.h"
#include "read.h"

using namespace std;

TEST_CASE("intervallum hossza 0", "nincs tantargy")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/t0.txt", adat);
    CHECK(!madar(adat));
}

#endif // TEST_H_INCLUDED
