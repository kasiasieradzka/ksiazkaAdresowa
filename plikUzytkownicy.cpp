#include <iostream>
#include <fstream>
#include <windows.h>
#include "plikUzytkownicy.h"


using namespace std;

Uzytkownik PlikUzytkownicy::pobierzDaneUzytkownika(string linia) {
    Uzytkownik uzytkownik;
    string wyrazPomocniczy = "";
    int numerPojedynczejDanejAdresata = 1;

    for(int i = 0; i < linia.size(); i++) {
        if(linia[i] != '|') {
            wyrazPomocniczy += linia[i];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                uzytkownik.ustawId(atoi(wyrazPomocniczy.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(wyrazPomocniczy);
                break;
            case 3:
                uzytkownik.ustawHaslo(wyrazPomocniczy);
                break;
            }
            wyrazPomocniczy = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return uzytkownik;
}

void PlikUzytkownicy::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    fstream plik;
    plik.open("PlikUzytkownikow.txt", ios::out | ios::app);
    if(plik.good() == true) {
        plik << uzytkownik.pobierzId() << "|";
        plik << uzytkownik.pobierzLogin() << "|";
        plik << uzytkownik.pobierzHaslo() << "|" << endl;
        plik.close();
    } else {
        cout << "Nie mozna otworzyc pliku i zapisac w nim danych" << endl;
        Sleep(1500);
        exit(0);
    }
}

void PlikUzytkownicy::zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy) {
    fstream plik;
    plik.open("PlikUzytkownikow.txt", ios::out);
    if(plik.good() == true) {
        for(vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            plik << itr -> Uzytkownik::pobierzId() << "|";
            plik << itr -> Uzytkownik::pobierzLogin() << "|";
            plik << itr -> Uzytkownik::pobierzHaslo() << "|" << endl;
        }
        plik.close();
    } else {
        cout << "Nie mozna otworzyc pliku i zapisac w nim danych" << endl;
        Sleep(1500);
        exit(0);
    }
}

void PlikUzytkownicy::wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy) {
    Uzytkownik uzytkownik;
    fstream plik;
    string linia = "";
    plik.open("PlikUzytkownikow.txt", ios::in);
    if(plik.good() == true) {
        while(getline(plik,linia)) {
            uzytkownik = pobierzDaneUzytkownika(linia);
            uzytkownicy.push_back(uzytkownik);
        }
        plik.close();
    }
}
