//Készítette:    Bárdosi Bence
//Dátum:         2017.03.16.
//Feladat:       Beolvasást elvégző függvények implementációja
//Főfeladat:     lsd.: main.cpp

#include "read.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Feladat:      Adatbeolvasás lekoordinálása
//Tevékenység:  Megkérdezi a felhasználótól, hogy milyen módon kívánja az adatokat bevinni.
//Kimenõ adat:  vector<vector<int>> adat
//              bool ok - sikerült-e a beolvasás (visszatérési értékként)
bool read (vector<vector<int> > &adat)
{
    cout << "Fájlból (f), vagy consoleról (c) olvassuk be az adatokat? ";

    char c;
    cin >> c;

    if (c == 'f' || c == 'F') {
        string fname;

        cout << "Fájl neve? ";
        cin >> fname;
        return from_file(fname, adat);
    }


    else if (c == 'c' || c == 'C')
        return from_console(adat);

    return false;

}

//Feladat:      Természetes számokat tartalmazó mátrix (vector<vector>) feltöltése szöveges állományból
//Tevékenység:  Megnyitja a megadott szöveges állományt (sikertelen kísérlet esetén hibát jelez)
//              majd a fájlból beolvassa a városok, a faok, majd az egyedek számát
//Kimenõ adat:  vector<vector<int>> adat
//              bool ok - sikerült-e az állomány megnyitása (visszatérési értékként)
bool from_file (const string fname, vector<vector<int> > &adat)
{
    int n, m, s;

    ifstream file(fname.c_str());

    if(file.fail()) {
        cout << "Hibas fajlnev!\n";
        return false;
    }

    file >> n >> m;

    adat.resize(n);

    for ( int i = 0; i < n; ++i)
        for ( int j = 0; j < m; ++j) {
            file >> s;
            adat[i].push_back(s);
        }

    return true;
}

//Feladat:      Természetes számokat tartalmazó mátrix (vector<vector>) feltöltése consoleról
//Tevékenység:  Bekéri a felhasználótól a városok és a megfigyelt fajok számát (nem helyes érték esetén hibát jelez)
//              majd a mért egyedszámokat
//Kimenõ adat:  vector<vector<int>> adat
//              bool ok - sikerült-e az állomány megnyitása (visszatérési értékként)
bool from_console (vector<vector<int> > &adat)
{
    int n, m, s;

    cout << "Városok száma? ";
    if(!safecin(n, "városszám")) return false;

    cout << "Madárfajok száma? ";
    if(!safecin(m, "fajszám")) return false;

    adat.resize(n);

    for ( int i = 0; i < n; ++i) {
        cout << (i+1) << ". városban megfigyelt:" << endl;

        for ( int j = 0; j < m; ++j) {
            cout << "   " << (j+1) << ". faj egyedeinek száma: ";
            if(!safecin(s, "egyedszám")) return false;
            adat[i].push_back(s);
        }
    }

    return true;
}

//Feladat:      Console-os beolvasásnál beolvassa és leellenőrzi, hogy a kapott adat természetes szám-e
//              Hiba esetén értesíti a felhasználót
//Bemenõ adat:  string msg - hiba szövege
//Kimenő adat:  int s - a beolvasott érték
//              bool ok - sikereses beolvasás (visszatérési érték)
bool safecin (int &s, string msg)
{
    cin >> s;

    if(cin.fail() || s < 0) {
        cout << "HIBA (" << msg << ")" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        return false;
    }

    return true;
}
