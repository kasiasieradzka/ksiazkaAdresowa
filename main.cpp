#include <iostream>
#include <windows.h>
#include "uzytkownicy.h"
#include "adresaci.h"

using namespace std;

int main() {
    Uzytkownicy uzytkownik;
    int idZalogowanegoUzytkownika = 0;
    char wybor;

    while(true) {
        if(idZalogowanegoUzytkownika == 0) {
            system("cls");
            cout << " >>> KSIAZKA ADRESOWA <<<" << endl << endl;
            cout << "ID ZALOGOWANEGO UZYTKOWNIKA: " << idZalogowanegoUzytkownika << endl << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << endl << "Wybor: ";
            cin >> wybor;

            switch (wybor) {
            case '1':
                uzytkownik.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = uzytkownik.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else if(idZalogowanegoUzytkownika > 0) {
            Adresaci ksiazkaAdresowa(idZalogowanegoUzytkownika);

            do {
                system("cls");
                cout << " >>> KSIAZKA ADRESOWA <<<" << endl << endl;
                cout << "ID ZALOGOWANEGO UZYTKOWNIKA: " << idZalogowanegoUzytkownika << endl << endl;
                cout << "1. Dodaj adresata" << endl;
                cout << "2. Wyszukaj adresata" << endl;
                cout << "3. Wyswietl wszystkich adresatow" << endl;
                cout << "4. Usuwanie wybranego adresata" << endl;
                cout << "5. Edycja danych wybranego adresata" << endl;
                cout << "6. Zmiana hasla" << endl;
                cout << "7. Wylogowanie" << endl;
                cout << "9. Zakoncz program" << endl;
                cout << endl << "Wybor: ";
                cin >> wybor;

                switch (wybor) {
                case '1':
                    ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
                    break;
                case '2':
                    cout << "1. Wyszukaj po imieniu" << endl;
                    cout << "2. Wyszukaj po nazwisku" << endl;
                    cin >> wybor;
                    if (wybor == '1') {
                        ksiazkaAdresowa.wyszukajAdresataPoImieniu();
                    } else if (wybor == '2') {
                        ksiazkaAdresowa.wyszukajAdresataPoNazwisku();
                    }
                    break;
                case '3':
                    ksiazkaAdresowa.wyswietlAdresatow();
                    break;
                case '4':
                    ksiazkaAdresowa.usuwanieWybranegoAdresata();
                    break;
                case '5':
                    ksiazkaAdresowa.edycjaWybranegoAdresata();
                    break;
                case '6':
                    uzytkownik.zmianaHasla(idZalogowanegoUzytkownika);
                    break;
                case '7':
                    idZalogowanegoUzytkownika = 0;
                    //adresaci.clear();
                    break;
                case '9':
                    exit(0);
                    break;
                }
            } while(wybor != '7');
        }
    }
    return 0;
}
