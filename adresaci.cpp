#include <iostream>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include "adresaci.h"
#include "uzytkownicy.h"

using namespace std;

Adresaci::Adresaci(int idZalogowanegoUzytkownika) {
    if(idZalogowanegoUzytkownika == 0) {
        exit(0);
    } else {
        this->idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
    }

    plikAdresaci.wczytajAdresatowZpliku(adresaci, idZalogowanegoUzytkownika);
}

Adresaci::~Adresaci() {
    ;
}

string Adresaci::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void Adresaci::wyswietlAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        for (vector <Adresat>:: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            cout << "Id:                 " << itr -> pobierzIdAdresata() << endl;
            cout << "Imie:               " << itr -> pobierzImie() << endl;
            cout << "Nazwisko:           " << itr -> pobierzNazwisko() << endl;
            cout << "Numer telefonu:     " << itr -> pobierzNrTelefonu() << endl;
            cout << "Email:              " << itr -> pobierzEmail() << endl;
            cout << "Adres:              " << itr -> pobierzAdres() << endl << endl;
        }
        cout << endl;
    } else {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void Adresaci::dodajAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    int idAdresata = 0;
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";

    system("cls");
    cout << ">>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    cout << "Rozmiar vectora: "<< adresaci.size() << endl;

    idAdresata = plikAdresaci.pobierzIdAdresataZpliku();
    adresat.ustawIdAdresata(idAdresata);

    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << endl << "Podaj dane nowego adresata" << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, numerTelefonu);
    adresat.ustawNrTelefonu(numerTelefonu);

    cout << "Podaj adres emial: ";
    cin >> email;
    adresat.ustawEmail(email);

    cout << "Podaj adres (podaj w jednej linijce): ";
    cin.sync();
    getline(cin, adres);
    adresat.ustawAdres(adres);

    adresaci.push_back(adresat);

    //zapis adresata do pliku
    plikAdresaci.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat zostal dodany" << endl << endl;
    Sleep(1500);
}

void Adresaci::wyszukajAdresataPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Podaj poszukiwane imie: ";
        cin >> imiePoszukiwanegoAdresata;
        imiePoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                cout << endl;
                cout << "Id:                 " << itr -> pobierzIdAdresata() << endl;
                cout << "Imie:               " << itr -> pobierzImie() << endl;
                cout << "Nazwisko:           " << itr -> pobierzNazwisko() << endl;
                cout << "Numer Telefonu:     " << itr -> pobierzNrTelefonu() << endl;
                cout << "Nr Email:           " << itr -> pobierzEmail()<< endl;
                cout << "Adres:              " << itr -> pobierzAdres() << endl;
                iloscAdresatow++;
            }
        }
        if (iloscAdresatow == 0) {
            cout << endl << "Nie ma adresatow z tym imieniem w ksiazce adresowej" << endl;
        } else {
            cout << endl << "Ilosc adresatow z imieniem: >>> " << imiePoszukiwanegoAdresata << " <<<";
            cout << " w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    } else {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void Adresaci::wyszukajAdresataPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Podaj poszukiwane nazwisko: ";
        cin >> nazwiskoPoszukiwanegoAdresata;
        nazwiskoPoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                cout << endl;
                cout << "Id:                 " << itr -> pobierzIdAdresata() << endl;
                cout << "Imie:               " << itr -> pobierzImie() << endl;
                cout << "Nazwisko:           " << itr -> pobierzNazwisko() << endl;
                cout << "Numer Telefonu:     " << itr -> pobierzNrTelefonu() << endl;
                cout << "Nr Email:           " << itr -> pobierzEmail()<< endl;
                cout << "Adres:              " << itr -> pobierzAdres() << endl;
                iloscAdresatow++;
            }
        }
        if (iloscAdresatow == 0) {
            cout << endl << "Nie ma adresatow z tym imieniem w ksiazce adresowej" << endl;
        } else {
            cout << endl << "Ilosc adresatow z imieniem: >>> " << nazwiskoPoszukiwanegoAdresata << " <<<";
            cout << " w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    } else {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void Adresaci::usuwanieWybranegoAdresata() {
    int idUsuwanegoAdresata = 0;
    char znak;
    bool czyIstniejeAdresat = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> USUWANIE WYBRANEJ OSOBY <<<" << endl << endl;
        cout << "Podaj numer ID adresata ktorego chcesz USUNAC: ";
        cin >> idUsuwanegoAdresata;

        if (cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl;
            cin.clear();
            cin.sync();
        } else {
            for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
                if (itr -> pobierzIdAdresata() == idUsuwanegoAdresata) {
                    czyIstniejeAdresat = true;
                    cout << endl << endl << "Potwierdz naciskajac klawisz 't': ";
                    cin >> znak;
                    if (znak == 't') {
                        itr = adresaci.erase(itr);
                        cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                        plikAdresaci.zapisDanychDoPlikuPoUsunieciuAdresata(adresaci, idUsuwanegoAdresata);
                        break;
                    } else {
                        cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                        break;
                    }
                }
            }
            if (czyIstniejeAdresat == false) {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            }
        }
    } else {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    system("pause");
}

void Adresaci::edycjaWybranegoAdresata() {
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
    int idWybranegoAdresata = 0;
    char wybor;
    bool czyIstniejeAdresat = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
        cout << "Podaj numer ID adresata u ktorego chcesz zmienic dane: ";
        cin >> idWybranegoAdresata;

        if (cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl << endl;
            cin.clear();
            cin.sync();
        } else {
            for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
                if (itr -> pobierzIdAdresata() == idWybranegoAdresata) {
                    czyIstniejeAdresat = true;

                    cout << endl << "Ktore dane zaktualizowac: " << endl;
                    cout << "1 - Imie" << endl;
                    cout << "2 - Nazwisko" << endl;
                    cout << "3 - Numer telefonu" << endl;
                    cout << "4 - Email" << endl;
                    cout << "5 - Adres" << endl;
                    cout << "6 - Powrot " << endl;
                    cout << endl << "Wybierz 1-6: ";
                    cin >> wybor;

                    switch (wybor) {
                    case '1':
                        cout << "Podaj nowe imie: ";
                        cin >> imie;
                        imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                        itr -> ustawImie(imie);
                        cout << endl << "Imie zostalo zmienione" << endl << endl;
                        plikAdresaci.zapisEdytwanychAdresatowDoPliku(adresaci, idWybranegoAdresata);
                        break;
                    case '2':
                        cout << "Podaj nowe nazwisko: ";
                        cin >> nazwisko;
                        nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                        itr -> ustawNazwisko(nazwisko);
                        cout << endl << "Nazwisko zostalo zmienione" << endl << endl;
                        plikAdresaci.zapisEdytwanychAdresatowDoPliku(adresaci, idWybranegoAdresata);
                        break;
                    case '3':
                        cout << "Podaj nowy numer telefonu: ";
                        cin.sync();
                        getline(cin, numerTelefonu);
                        itr -> ustawNrTelefonu(numerTelefonu);
                        cout << endl << "Numer telefonu zostal zmieniony" << endl << endl;
                        plikAdresaci.zapisEdytwanychAdresatowDoPliku(adresaci, idWybranegoAdresata);
                        break;
                    case '4':
                        cout << "Podaj nowy email: ";
                        cin.sync();
                        getline(cin, email);
                        itr -> ustawEmail(email);
                        cout << endl << "Email zostal zmieniony" << endl << endl;
                        plikAdresaci.zapisEdytwanychAdresatowDoPliku(adresaci, idWybranegoAdresata);
                        break;
                    case '5':
                        cout << "Podaj nowy adres zamieszkania: ";
                        cin.sync();
                        getline(cin, adres);
                        itr -> ustawAdres(adres);
                        cout << endl << "Adres zostal zmieniony" << endl << endl;
                        plikAdresaci.zapisEdytwanychAdresatowDoPliku(adresaci, idWybranegoAdresata);
                        break;
                    case '6':
                        cout << endl << "Powrot do menu glownego" << endl << endl;
                        break;
                    default:
                        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu glownego." << endl << endl;
                        break;
                    }
                }
            }
            if (czyIstniejeAdresat == false) {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej." << endl << endl;
            }
        }
    } else {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
