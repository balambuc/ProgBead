//Készítette:    Bárdosi Bence
//Dátum:         2017. 03. 06.
//NEPTUN kód:    VY9NJN
//mail:          bardosi.bence@gmail.com
//csoport:       A csoport
//Feladat:       0.beadandó/4.feladat
//               mértünk 0 Celsius fokot úgy, hogy másnap fagypont alatti hömérséklet volt?

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool ReadData(int argc, char *argv[], vector<float> &t);
bool ReadFromFile(const string &fname, vector<float> &t);
void ReadFromConsole(vector<float> &t);
void WriteVector(vector<float> &t);
int CountDays(const vector<float> &t);

int main(int argc, char *argv[])
{
    char ch;
    do {
        vector<float> t;

        // Adatok beolvasása.
        if(!ReadData(argc, argv, t))
            continue;

        // Megadott tömb kiírása olvasható formában
        WriteVector(t);

        // Kiértékelés és kiíratás
        cout << CountDays(t)
             << " alkalommal kovetett fagypont alatti nap fagypontit.";

        // Újra futtatás
        cout << endl << "Futtassam ujra? (I/N) ";
        cin  >> ch;
        argc = 1;
    } while(ch!='n' && ch!='N');

    return 0;
}

//Feladat:      Adatbeolvasás lekoordinálása
//Tevékenység:  Megkérdezi a felhasználótól, hogy milyen módon kívánja az adatokat bevinni.
//              Ha fileból, akkor leellen?rzi, hogy nem lett-e a fájl neve paraméterként megadva a futtatás során.
//Bemenõ adat:  int argc - futási paraméterek száma
//              char **argv - futási paraméterek
//Kimenõ adat:  vector<float> t
//              bool ok - sikerült-e a beolvasás (visszatérési értékként)
bool ReadData(int argc, char *argv[], vector<float> &t)
{
    char ch;
    bool ready = true;
    do {
        cout << "Fajlbol, vagy console-rol olvassuk be az adatokat? (F/C) ";
        cin >> ch;

        switch(ch) {
        case 'F':
        case 'f': {
            //beolvasás fileból
            string fname;
            if(argc>1)
                fname = argv[1];
            else {
                cout << "Adja meg a szoveges fajl nevet: ";
                cin >> fname;
            }
            if (!ReadFromFile(fname, t)) return false;
        }
        break;
        case 'C':
        case 'c': {
            // beolvasás console-ról
            ReadFromConsole(t);
        }
        break;
        default:
            cout << "Nincs ilyen opcio!";
            ready = false;
            break;
        }
    } while(!ready);
    return true;
}

//Feladat:      Valós számokat tartalmazó tömb (vector) feltöltése szöveges állományból
//Tevékenység:  Megnyitja a megadott szöveges állományt (sikertelen kísérlet esetén hibát jelez)
//              majd a fájlból egymás után beolvassa az összes elválasztójelekkel határolt hömérsékletértéket
//              és elhelyezi azokat egy tömbben (vector-ban)
//Bemenõ adat:  string fname - szöveges állomány neve
//Kimenõ adat:  vector<float> t
//              bool ok - sikerült-e az állomány megnyitása (visszatérési értékként)
bool ReadFromFile(const string &fname, vector<float> &t)
{
    ifstream x(fname.c_str());
    if(x.fail()) {
        cout << "Hibas fajlnev!"<< endl;
        return false;
    }

    float degree;
    x >> degree;
    while(!x.eof()) {
        t.push_back(degree);
        x >> degree;
    }
    // Ha nem volt az utolsó sor végén sorvége jel:
    if (!x.fail()) t.push_back(degree);
    return true;
}

//Feladat:      Valós számokat tartalmazó tömb (vector) feltöltése consoleról
//Tevékenység:  Megnyitja a megadott szöveges állományt (sikertelen kísérlet esetén hibát jelez)
//              majd a fájlból egymás után beolvassa az összes elválasztójelekkel határolt hömérsékletértéket
//              és elhelyezi azokat egy tömbben (vector-ban)
//Kimenõ adat:  vector<float> t
void ReadFromConsole(vector<float> &t)
{
    cout << "Kerem adja meg a napokon mert Celsius fok ertekeket szokozzel, vagy enterrel elvalasztva, majd adjon meg barmilyen nem szam karaktert, ezzel jelezve az adatfeltoltes veget!" << endl;
    float degree;
    cin >> degree;
    while(!cin.fail()) {
        t.push_back(degree);
        cin >> degree;
    }

    cin.clear();
    cin.ignore(10000,'\n');
}

//Feladat:      Kiírja az adatokat tartalmazó vektort olvasható formában a console-ra
//Bemenõ adat:  vector<float> t
void WriteVector(vector<float> &t)
{
    cout << endl << "A megadott homersekleteken (<";
    if((int)t.size() >0) {
        cout << t[0];
        for(int i=1; i< (int)t.size(); ++i)
            cout << ", " << t[i];
    }

    cout << ">) ";
}

//Feladat:      Megszámolja hányszor követett 0°C-ot negatív érték
//Tevékenység:  Megszámlálás segítségével, megadja, hogy az adott tömbben hányszor fordul elö a feltételnek megfelelö nappáros
//Bemenõ adat:  vector<float> t
//Kimenõ adat:  int c - a válasz visszatérési értékként
int CountDays(const vector<float> &t)
{
    int c=0;
    for(int i=1; i<(int)t.size(); ++i)
        if(t[i]<0 && t[i-1]==0)
            ++c;
    return c;
}
