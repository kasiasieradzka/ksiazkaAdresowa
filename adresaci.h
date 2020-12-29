#ifndef ADRESACI_H
#define ADRESACI_H

#include <iostream>
#include <vector>
#include "plikAdresaci.h"

using namespace std;

class Adresaci{
private:
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    PlikAdresaci plikAdresaci;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

public:
    Adresaci(int idZalogowanegoUzytkownika);
    virtual ~Adresaci();

    void wyswietlAdresatow();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void usuwanieWybranegoAdresata();
    void edycjaWybranegoAdresata();
};

#endif
