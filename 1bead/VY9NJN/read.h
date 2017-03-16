//Készítette:    Bárdosi Bence
//Dátum:         2017.03.16.
//Feladat:       Beolvasást elvégző függvények deklarációja
//Főfeladat:     lsd.: main.cpp

#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

bool read (vector<vector<int> > &adat);
bool from_file (const string fname, vector<vector<int> > &adat);
bool from_console (vector<vector<int> > &adat);
bool safecin (int &s, string msg);

#endif // READ_H_INCLUDED
