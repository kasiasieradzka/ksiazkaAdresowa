#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat{
private:
    int idAdresata;
    int idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    Adresat();
    virtual ~Adresat();

    int pobierzIdAdresata();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNrTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    void ustawIdAdresata(int idAdresata);
    void ustawIdUzytkownika(int idUzytkownika);
    void ustawImie(string imie);
    void ustawNazwisko(string nazwisko);
    void ustawNrTelefonu(string numerTelefony);
    void ustawEmail(string email);
    void ustawAdres(string adres);
};

#endif
