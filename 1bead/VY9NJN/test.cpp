#include "test.h"

#ifdef TEST_H_INCLUDED

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "madar.h"
#include "read.h"

using namespace std;

//kulso tetel

TEST_CASE("intervallum hossza 0", "nincs madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be11.txt", adat);
    CHECK(!madar(adat));
}

TEST_CASE("intervallum hossza 1", "van '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be12.txt", adat);
    CHECK(!madar(adat));
}

TEST_CASE("intervallum hossza 1 ", "nincs '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be13.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("intervallum hossza tobb", "nincs '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be14.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("intervallum eleje", "elso varos mind madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be15.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("intervallum vege", "utolso varos mind madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be16.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("tobb varos, tobb madar", "mindbe mind")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be17.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("tobb varos, tobb madar ", "csak egybe mind")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be18.txt", adat);
    CHECK(madar(adat));
}

TEST_CASE("tobb varos tobb madar  ", "nincs mind madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be19.txt", adat);
    CHECK(!madar(adat));
}

//belso tetel

TEST_CASE(" intervallum hossza 0", "nincs madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be21.txt", adat);
    CHECK(mind(adat[0]));
}

TEST_CASE(" intervallum hossza 1", "egy '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be22.txt", adat);
    CHECK(!mind(adat[0]));
}

TEST_CASE(" intervallum hossza 1 ", "egy nem '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be23.txt", adat);
    CHECK(mind(adat[0]));
}

TEST_CASE(" intervallum hossza tobb", "nincs '0' madar")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be24.txt", adat);
    CHECK(mind(adat[0]));
}

TEST_CASE(" intervallum eleje", "csak az elso '0'")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be25.txt", adat);
    CHECK(!mind(adat[0]));
}

TEST_CASE(" intervallum vege", "csak az utolso '0'")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be26.txt", adat);
    CHECK(!mind(adat[0]));
}

TEST_CASE(" tobb madar", "mind nem '0'")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be27.txt", adat);
    CHECK(mind(adat[0]));
}

TEST_CASE("  tobb madar ", "egy '0'")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be28.txt", adat);
    CHECK(!mind(adat[0]));
}

TEST_CASE("   tobb madar  ", "tobb '0'")
{
    vector<vector<int> > adat;
    int n,m;

    from_file("../Tesztesetek/be29.txt", adat);
    CHECK(!mind(adat[0]));
}

#endif // TEST_H_INCLUDED
