#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H

#include <iostream>
#include <vector>
#include "uzytkownik.h"

using namespace std;

class PlikUzytkownicy {
private:
    Uzytkownik pobierzDaneUzytkownika(string linia);

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy);
    void wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy);
};

#endif
