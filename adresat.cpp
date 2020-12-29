#include <iostream>
#include "adresat.h"

using namespace std;

Adresat::Adresat() {
    idAdresata = 0;
    idUzytkownika = 0;
    imie = "";
    nazwisko = "";
    numerTelefonu = "";
    email = "";
    adres = "";
}

Adresat::~Adresat() {
    ;
}

int Adresat::pobierzIdAdresata() {
    return idAdresata;
}

int Adresat::pobierzIdUzytkownika() {
    return idUzytkownika;
}

string Adresat::pobierzImie() {
    return imie;
}

string Adresat::pobierzNazwisko() {
    return nazwisko;
}

string Adresat::pobierzNrTelefonu() {
    return numerTelefonu;
}

string Adresat::pobierzEmail() {
    return email;
}

string Adresat::pobierzAdres() {
    return adres;
}

void Adresat::ustawIdAdresata(int idAdresata) {
    this->idAdresata = idAdresata;
}

void Adresat::ustawIdUzytkownika(int idUzytkownika) {
    this->idUzytkownika = idUzytkownika;
}

void Adresat::ustawImie(string imie) {
    this->imie = imie;
}

void Adresat::ustawNazwisko(string nazwisko){
    this->nazwisko = nazwisko;
}

void Adresat::ustawNrTelefonu(string numerTelefonu) {
    this->numerTelefonu = numerTelefonu;
}

void Adresat::ustawEmail(string email) {
    this->email = email;
}

void Adresat::ustawAdres(string adres) {
    this->adres = adres;
}
