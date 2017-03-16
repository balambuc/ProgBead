//Készítette:    Bárdosi Bence
//Dátum:         2017.03.16.
//neptun kód:    VY9NJN
//mail:          bardosi.bence@gmail.com
//Feladat:       Volt-e olyan település, ahol mindegyik madárfaj előfordult?

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "read.h"
#include "madar.h"
#include "test.h"

using namespace std;

void kiir (const vector<vector<int> > &adat);

#ifndef TEST_H_INCLUDED
int main()
{
    //Ékezetes karakterek megjelenítése
    system("chcp 65001");

    vector<vector<int> > adat;
    char c;

    do {

        //Cimke
        system("cls");
        cout << "       Volt-e olyan település, ahol mindegyik madárfaj előfordult? " << endl << endl;

        //Beolvasás
        while (!read(adat))
            cout << endl;

        //Adatok olvasható formában való kiírása
        cout << endl << "A megadott adatokra:" << endl;
        kiir(adat);

        //Megoldás
        if(madar(adat))
            cout << "Volt olyan település, ahol mindegyik madárfaj előfordult.";
        else
            cout << "Nem volt olyan település, ahol mindegyik madárfaj előfordult.";

        //Újra futtatás
        cout << endl << "Futtassam újra? (I/N) ";
        cin >> c;

    } while (c == 'i' || c == 'I');

    return 0;
}
#endif // TEST_H_INCLUDED

//Feladat:      Kiírja az adatokat tartalmazó vektort olvasható formában a console-ra
//Bemenõ adat:  vector<vector<int>>adat
void kiir (const vector<vector<int> > &adat)
{
    for (unsigned int i = 0; i < adat.size(); ++i ) {
        cout << " " << (i+1) << ". város: < ";

        for (unsigned int j = 0; j < adat[i].size(); ++j )
            cout << adat[i][j] << " " ;

        cout << ">" << endl;
    }

    cout << endl;
}
