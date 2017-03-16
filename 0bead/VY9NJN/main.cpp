//K�sz�tette:    B�rdosi Bence
//D�tum:         2017. 03. 06.
//NEPTUN k�d:    VY9NJN
//mail:          bardosi.bence@gmail.com
//csoport:       A csoport
//Feladat:       0.beadand�/4.feladat
//               m�rt�nk 0 Celsius fokot �gy, hogy m�snap fagypont alatti h�m�rs�klet volt?

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

        // Adatok beolvas�sa.
        if(!ReadData(argc, argv, t))
            continue;

        // Megadott t�mb ki�r�sa olvashat� form�ban
        WriteVector(t);

        // Ki�rt�kel�s �s ki�rat�s
        cout << CountDays(t)
             << " alkalommal kovetett fagypont alatti nap fagypontit.";

        // �jra futtat�s
        cout << endl << "Futtassam ujra? (I/N) ";
        cin  >> ch;
        argc = 1;
    } while(ch!='n' && ch!='N');

    return 0;
}

//Feladat:      Adatbeolvas�s lekoordin�l�sa
//Tev�kenys�g:  Megk�rdezi a felhaszn�l�t�l, hogy milyen m�don k�v�nja az adatokat bevinni.
//              Ha fileb�l, akkor leellen?rzi, hogy nem lett-e a f�jl neve param�terk�nt megadva a futtat�s sor�n.
//Bemen� adat:  int argc - fut�si param�terek sz�ma
//              char **argv - fut�si param�terek
//Kimen� adat:  vector<float> t
//              bool ok - siker�lt-e a beolvas�s (visszat�r�si �rt�kk�nt)
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
            //beolvas�s fileb�l
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
            // beolvas�s console-r�l
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

//Feladat:      Val�s sz�mokat tartalmaz� t�mb (vector) felt�lt�se sz�veges �llom�nyb�l
//Tev�kenys�g:  Megnyitja a megadott sz�veges �llom�nyt (sikertelen k�s�rlet eset�n hib�t jelez)
//              majd a f�jlb�l egym�s ut�n beolvassa az �sszes elv�laszt�jelekkel hat�rolt h�m�rs�klet�rt�ket
//              �s elhelyezi azokat egy t�mbben (vector-ban)
//Bemen� adat:  string fname - sz�veges �llom�ny neve
//Kimen� adat:  vector<float> t
//              bool ok - siker�lt-e az �llom�ny megnyit�sa (visszat�r�si �rt�kk�nt)
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
    // Ha nem volt az utols� sor v�g�n sorv�ge jel:
    if (!x.fail()) t.push_back(degree);
    return true;
}

//Feladat:      Val�s sz�mokat tartalmaz� t�mb (vector) felt�lt�se consoler�l
//Tev�kenys�g:  Megnyitja a megadott sz�veges �llom�nyt (sikertelen k�s�rlet eset�n hib�t jelez)
//              majd a f�jlb�l egym�s ut�n beolvassa az �sszes elv�laszt�jelekkel hat�rolt h�m�rs�klet�rt�ket
//              �s elhelyezi azokat egy t�mbben (vector-ban)
//Kimen� adat:  vector<float> t
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

//Feladat:      Ki�rja az adatokat tartalmaz� vektort olvashat� form�ban a console-ra
//Bemen� adat:  vector<float> t
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

//Feladat:      Megsz�molja h�nyszor k�vetett 0�C-ot negat�v �rt�k
//Tev�kenys�g:  Megsz�ml�l�s seg�ts�g�vel, megadja, hogy az adott t�mbben h�nyszor fordul el� a felt�telnek megfelel� napp�ros
//Bemen� adat:  vector<float> t
//Kimen� adat:  int c - a v�lasz visszat�r�si �rt�kk�nt
int CountDays(const vector<float> &t)
{
    int c=0;
    for(int i=1; i<(int)t.size(); ++i)
        if(t[i]<0 && t[i-1]==0)
            ++c;
    return c;
}
