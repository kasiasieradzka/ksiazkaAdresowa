#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <iostream>
#include <vector>
#include "plikUzytkownicy.h"

using namespace std;

class Uzytkownicy {
private:
    vector<Uzytkownik> uzytkownicy;
    PlikUzytkownicy plikUzytkownicy;
    bool czyIstniejeLogin(string login);

public:
    Uzytkownicy();
    virtual ~Uzytkownicy();

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void zmianaHasla(int idZalogowanegoUzytkownika);
};

#endif
