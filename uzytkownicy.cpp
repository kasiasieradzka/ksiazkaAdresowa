#include <iostream>
#include <windows.h>
#include <fstream>
#include "uzytkownicy.h"

using namespace std;

Uzytkownicy::Uzytkownicy() {
    plikUzytkownicy.wczytajUzytkownikowZPliku(uzytkownicy);
}

Uzytkownicy::~Uzytkownicy() {
    ;
}

bool Uzytkownicy::czyIstniejeLogin(string login) {
    for(vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if(itr->Uzytkownik::pobierzLogin() == login) {
            cout << "Istnieje uzytkownik o takim loginie. Podaj inny login." << endl;
            return true;
        }
    }
    return false;
}

void Uzytkownicy::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik;
    int id;
    string login = "", haslo = "";

    system("cls");
    cout << ">>> REJESTROWANIE NOWEGO UZYTKOWNIKA <<<" << endl;
    cout << "Rozmiar vectora: "<< uzytkownicy.size() << endl;

    //ustawianie id
    if(uzytkownicy.empty() == true) {
        id = 1;
    } else {
        id = uzytkownicy.back().pobierzId() + 1;
    }
    uzytkownik.ustawId(id);

    //dodawanie loginu
    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        cin.ignore();
    } while (czyIstniejeLogin(login) == true);
    uzytkownik.ustawLogin(login);

    //dodawanie hasla
    cout << "Podaj haslo (minimum 3 znaki): ";
    cin >> haslo;
    cin.ignore();
    uzytkownik.ustawHaslo(haslo);

    // dodawanie uzytkownika do vectora
    uzytkownicy.push_back(uzytkownik);

    // zapis uzytkownika do pliku
    plikUzytkownicy.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(1500);
}

int Uzytkownicy::logowanieUzytkownika() {
    string login, haslo;

    system("cls");
    cout << ">>> LOGOWANIE UZYTKOWNIKA <<<" << endl;
    cout << "Rozmiar vectora: "<< uzytkownicy.size() << endl;
    cout << endl << "Podaj login: ";
    cin >> login;
    while(1) {
        for(vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            if(itr -> Uzytkownik::pobierzLogin() == login) {
                for(int proby = 0; proby < 3; proby++) {
                    cout << "Podaj haslo. Pozostalo Ci: " << 3 - proby << " prob ";
                    cin >> haslo;
                    if(itr -> Uzytkownik::pobierzHaslo() == haslo) {
                        cout << endl << "Zalogowales sie." << endl;
                        Sleep(1500);
                        return itr -> Uzytkownik::pobierzId();
                    }
                }
                cout << endl;
                cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba" << endl;
                Sleep(3000);
                itr = uzytkownicy.begin() - 1;
            }
        }
        cout << endl;
        cout << "Nie ma uzytkownika z takim loginem. Sproboj jeszcze raz" << endl;
        Sleep(1500);
        return 0;
    }
}

void Uzytkownicy::zmianaHasla(int idZalogowanegoUzytkownika){
    string haslo;

    system("cls");
    cout << ">>> EDYCJA HASLA UZYTKOWNIKA <<<" << endl << endl;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;

    for(vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if(itr -> Uzytkownik::pobierzId() == idZalogowanegoUzytkownika) {
            itr -> Uzytkownik::ustawHaslo(haslo);
        }
    }
    cout << endl;
    plikUzytkownicy.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    cout << "Haslo zostalo zmienione" << endl;
    Sleep(1500);
}
