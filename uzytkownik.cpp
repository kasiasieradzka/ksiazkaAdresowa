#include <iostream>
#include "uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik() {
    id = 0;
    login = "";
    haslo = "";
}

Uzytkownik::~Uzytkownik() {
    ;
}

int Uzytkownik::pobierzId() {
    return id;
}

string Uzytkownik::pobierzLogin() {
    return login;
}

string Uzytkownik::pobierzHaslo() {
    return haslo;
}

void Uzytkownik::ustawId(int id) {
    this->id = id;
}

void Uzytkownik::ustawLogin(string login) {
    this->login = login;
}

void Uzytkownik::ustawHaslo(string haslo) {
    this->haslo = haslo;
}
