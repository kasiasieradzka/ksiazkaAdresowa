#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "plikAdresaci.h"

using namespace std;

Adresat PlikAdresaci::pobierzDaneAdresata(string linia) {
    Adresat adresat;
    string wyrazPomocniczy = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int i = 0; i < linia.size(); i++) {
        if (linia[i] != '|') {
            wyrazPomocniczy += linia[i];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawIdAdresata(atoi(wyrazPomocniczy.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(wyrazPomocniczy.c_str()));
            case 3:
                adresat.ustawImie(wyrazPomocniczy);
                break;
            case 4:
                adresat.ustawNazwisko(wyrazPomocniczy);
                break;
            case 5:
                adresat.ustawNrTelefonu(wyrazPomocniczy);
                break;
            case 6:
                adresat.ustawEmail(wyrazPomocniczy);
                break;
            case 7:
                adresat.ustawAdres(wyrazPomocniczy);
                break;
            }
            wyrazPomocniczy = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikAdresaci::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();

    return str;
}

int PlikAdresaci::pobierzIdAdresataZpliku() {
    fstream plik;
    string liniaZDanymiAdresata, numerId;
    int idAdresata;

    plik.open("KsiazkaAdresowa.txt", ios::in);
    if(plik.good() == true) {
        while(getline(plik, liniaZDanymiAdresata)) {
                int i = 0;
            while(liniaZDanymiAdresata[i] != '|') {
                numerId += liniaZDanymiAdresata[i];
                i++;
            }
            idAdresata = atoi(numerId.c_str());
            numerId = "";
        }
        plik.close();
        return idAdresata + 1;
    }
    return 1;
}


void PlikAdresaci::dopiszAdresataDoPliku(Adresat adresat) {
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);

    if (plik.good() == true) {
        plik << adresat.pobierzIdAdresata() << "|";
        plik << adresat.pobierzIdUzytkownika() << "|";
        plik << adresat.pobierzImie() << "|";
        plik << adresat.pobierzNazwisko() << "|";
        plik << adresat.pobierzNrTelefonu() << "|";
        plik << adresat.pobierzEmail() << "|";
        plik << adresat.pobierzAdres() << "|" << endl;
        plik.close();
    } else {
        cout << "Nie mozna otworzyc pliku i zapisac w nim danych." << endl;
        system("pause");
    }
}

void PlikAdresaci::wczytajAdresatowZpliku(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika) {
    Adresat adresat;
    string linia = "";
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);
    if (plik.good() == true) {
        while (getline(plik, linia)) {
            adresat = pobierzDaneAdresata(linia);
            if(adresat.pobierzIdUzytkownika() == idZalogowanegoUzytkownika) {
                adresaci.push_back(adresat);
            }
        }
        plik.close();
    }
}

void PlikAdresaci::zapisDanychDoPlikuPoUsunieciuAdresata(vector<Adresat> &adresaci, int idUsuwanegoAdresata) {
    fstream plik, plikTymczasowy;
    string liniaZDanymiAdresata, numerId;
    int idAdresata;

    plik.open("KsiazkaAdresowa.txt", ios::in);
    plikTymczasowy.open("KsiazkaAdresowa_tymczasowa.txt", ios::out);
    if(plik.good() == true && plikTymczasowy.good() == true) {
        while(getline(plik, liniaZDanymiAdresata)) {
            int i = 0;
            while(liniaZDanymiAdresata[i] != '|') {
                numerId += liniaZDanymiAdresata[i];
                i++;
            }
            idAdresata = atoi(numerId.c_str());
            numerId = "";

            if(idAdresata != idUsuwanegoAdresata) {
                plikTymczasowy << liniaZDanymiAdresata << endl;
            }
        }
    }
    plik.close();
    plikTymczasowy.close();
    remove("KsiazkaAdresowa.txt");
    rename("KsiazkaAdresowa_tymczasowa.txt", "KsiazkaAdresowa.txt");
}

void PlikAdresaci::zapisEdytwanychAdresatowDoPliku(vector <Adresat> &adresaci, int idWybranegoAdresata) {
    fstream plik, plikTymczasowy;
    string liniaZDanymiAdresata, numerId;
    int idAdresata;

    plik.open("KsiazkaAdresowa.txt", ios::in);
    plikTymczasowy.open("KsiazkaAdresowa_tymczasowa.txt", ios::out);
    if(plik.good() == true && plikTymczasowy.good() == true) {
        while(getline(plik, liniaZDanymiAdresata)) {
            int i = 0;
            while(liniaZDanymiAdresata[i] != '|') {
                numerId += liniaZDanymiAdresata[i];
                i++;
            }
            idAdresata = atoi(numerId.c_str());
            numerId = "";

            if(idAdresata != idWybranegoAdresata) {
                plikTymczasowy << liniaZDanymiAdresata << endl;
            } else {
                for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
                    if(itr -> pobierzIdAdresata() == idWybranegoAdresata) {
                        liniaZDanymiAdresata = "";
                        liniaZDanymiAdresata += konwerjsaIntNaString(itr -> pobierzIdAdresata()) + "|";
                        liniaZDanymiAdresata += konwerjsaIntNaString(itr -> pobierzIdUzytkownika()) + "|";
                        liniaZDanymiAdresata += itr -> pobierzImie() + "|";
                        liniaZDanymiAdresata += itr -> pobierzNazwisko() + "|";
                        liniaZDanymiAdresata += itr -> pobierzNrTelefonu() + "|";
                        liniaZDanymiAdresata += itr -> pobierzEmail() + "|";
                        liniaZDanymiAdresata += itr -> pobierzAdres() + "|";

                        plikTymczasowy << liniaZDanymiAdresata << endl;
                        liniaZDanymiAdresata = "";
                    }
                }
            }
        }
    }
    plik.close();
    plikTymczasowy.close();
    remove("KsiazkaAdresowa.txt");
    rename("KsiazkaAdresowa_tymczasowa.txt", "KsiazkaAdresowa.txt");
}
