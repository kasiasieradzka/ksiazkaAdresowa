#ifndef PLIKADRESACI_H
#define PLIKADRESACI_H

#include <iostream>
#include <vector>
#include "adresat.h"

using namespace std;

class PlikAdresaci{
private:
    Adresat pobierzDaneAdresata(string linia);
    string konwerjsaIntNaString(int liczba);

public:
    int pobierzIdAdresataZpliku();
    void dopiszAdresataDoPliku(Adresat adresat);
    void wczytajAdresatowZpliku(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
    void zapisDanychDoPlikuPoUsunieciuAdresata(vector<Adresat> &adresaci, int idUsuwanegoAdresata);
    void zapisEdytwanychAdresatowDoPliku(vector <Adresat> &adresaci, int idWybranegoAdresata);
};

#endif
