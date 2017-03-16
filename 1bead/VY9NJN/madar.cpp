//Készítette:    Bárdosi Bence
//Dátum:         2017.03.16.
//Feladat:       A főfeladatot elvégző függvények implementációja
//Főfeladat:     lsd.: main.cpp

#include "madar.h"
#include <vector>

using namespace std;

//Feladat:      Megadja, hogy van-e olyan város ahol minden madár előfordult-e
//Tevékenység:  Lineáris keresés segítségével, megadja, hogy az adott mátrixban létezik-e megfelelő tulajdonságú nap
//Bemenõ adat:  vector<vector<int>> adat
//Kimenõ adat:  bool l - a válasz visszatérési értékként
bool madar(const vector<vector<int> > &adat)
{
    bool l = false;
    unsigned int i = 0;

    while(!l && i < adat.size()) {
        l=mind(adat[i]);
        ++i;
    }

    return l;
}

//Feladat:      Megadja, hogy az adott városban előfordult-e minden madárfajból
//Tevékenység:  Optimista lineáris keresés segítségével, megadja, hogy az adott tömbben minden madárfajból előfordul-e legalább 1
//Bemenõ adat:  vector<vector<int>> adat
//Kimenõ adat:  bool l - a válasz visszatérési értékként
bool mind(const vector<int> &sor)
{
    bool l = true;
    unsigned int i = 0;

    while(l && i < sor.size()) {
        l = (sor[i] > 0);
        ++i;
    }

    return l;
}
