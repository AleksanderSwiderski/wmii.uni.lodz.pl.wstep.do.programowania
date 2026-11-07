#include <iostream>

using namespace std;

/* 
Program ma za zadanie wczytac od uzytkownika dwie daty w ustalonym formacie nastepnie po wykonaniu obliczen 
podac liczbe dni dzielacych te dwie wybrane daty
*/

int main()
{
    // 1 Wczytanie dat
    int result = 0;
    const int BAD_DATE_INSERTED = 144;
    const int BAD_DATE_ORDER = 204;

    int rokPoczatek, miesiacPoczatek, dzienPoczatek;
    int rokKoniec, miesiacKoniec, dzienKoniec;

    cout << "Podaj kolejno rok miesiac i dzien daty poczatkowej oddzielone enterami\n";

    cout << ">";
    cin >> rokPoczatek;
    cout << ">";
    cin >> miesiacPoczatek;
    cout << ">";
    cin >> dzienPoczatek;

    cout << "Podaj teraz kolejnosc rok miesiac i dzien daty koncowej (oddzielone enterami)\n";

    cout << ">";
    cin >> rokKoniec;
    cout << ">";
    cin >> miesiacKoniec;
    cout << ">";
    cin >> dzienKoniec;

    // 1.1. Walidacja danych wejściowych
    // a - czy daty sa poprawne
    if ( (rokPoczatek <= 0) || (rokKoniec <=0) )
        return BAD_DATE_INSERTED;

    if ( (miesiacPoczatek  < 1 )  || (miesiacPoczatek > 12) || (miesiacKoniec < 1) || (miesiacKoniec > 12) )
        return BAD_DATE_INSERTED;

    bool czyPrzestepny;
    int dniWMiesiacu;

    // sprawdzmy przestepnosc
    if (rokPoczatek % 400 == 0) // lata podzielne przez 400 sa przestepne
        czyPrzestepny = true;
    else if (rokPoczatek % 100 == 0) // lata podzielne przez 100 nie sa przestepne
        czyPrzestepny = false;
    else if (rokPoczatek % 4 ==0) // lata podzielne przez 4 sa przestepne
        czyPrzestepny = true;
    else // reszta nie jest przestepna
        czyPrzestepny = false;
    // sprawdzamy ile dni ma miesiac
    if (miesiacPoczatek == 2 && czyPrzestepny) 
    {
        // luty zalezy od przestepnosci roku
        dniWMiesiacu = 29;
    }
    else if (miesiacPoczatek == 2)
    {
        dniWMiesiacu = 28;
    }
    else if ( (miesiacPoczatek == 4) || (miesiacPoczatek == 6) || (miesiacPoczatek == 9) || (miesiacPoczatek == 11))
    {
        dniWMiesiacu = 30;
    }
    else {
        dniWMiesiacu = 31;
    }
    if ( (dzienPoczatek< 1) || (dzienPoczatek > dniWMiesiacu) )
        return BAD_DATE_INSERTED;

    // sprawdzmy przestepnosc
    if (rokKoniec % 400 == 0) // lata podzielne przez 400 sa przestepne
        czyPrzestepny = true;
    else if (rokKoniec % 100 == 0) // lata podzielne przez 100 nie sa przestepne
        czyPrzestepny = false;
    else if (rokKoniec % 4 ==0) // lata podzielne przez 4 sa przestepne
        czyPrzestepny = true;
    else // reszta nie jest przestepna
        czyPrzestepny = false;
    // sprawdzamy ile dni ma miesiac
    if (miesiacKoniec == 2 && czyPrzestepny) 
    {
        // luty zalezy od przestepnosci roku
        dniWMiesiacu = 29;
    }
    else if (miesiacKoniec == 2)
    {
        dniWMiesiacu = 28;
    }
    else if ( (miesiacKoniec == 4) || (miesiacKoniec == 6) || (miesiacKoniec == 9) || (miesiacKoniec == 11))
    {
        dniWMiesiacu = 30;
    }
    else {
        dniWMiesiacu = 31;
    }
    if ( (dzienKoniec< 1) || (dzienKoniec > dniWMiesiacu) )
        return BAD_DATE_INSERTED;

    // b - czy daty sa w poprawnej kolejnosci

    // wykryc ze daty sa w zlej kolejnosci

    bool czyZamienione = false;
    if (rokKoniec < rokPoczatek)
        czyZamienione = true;
    else if ((rokKoniec == rokPoczatek) && (miesiacKoniec < miesiacPoczatek))
        czyZamienione = true;
    else if ((rokKoniec == rokPoczatek) && (miesiacKoniec == miesiacPoczatek) && dzienKoniec < dzienPoczatek)
        czyZamienione = true;

    // jesli sa - wymienic kolejnoscia
    if (czyZamienione)
    {
        int tempRok, tempMiesiac, tempDzien;
        tempRok = rokKoniec;
        tempMiesiac = miesiacKoniec;
        tempDzien = dzienKoniec;

        rokKoniec = rokPoczatek;
        miesiacKoniec = miesiacPoczatek;
        dzienKoniec = dzienPoczatek;

        rokPoczatek = tempRok;
        miesiacPoczatek = tempMiesiac;
        dzienPoczatek = tempDzien;
    }
    // 2 Rachunek dat

    int rok = rokPoczatek;
    int miesiac = miesiacPoczatek;
    int dzien = dzienPoczatek;
    int licznikDni = 0;
    const int MIESIECY_W_ROKU = 12;
    while ( !( (rokKoniec == rok) && (miesiacKoniec == miesiac) && (dzienKoniec == dzien) ) )
    {
        // idziemy do nastepnego dnia
        licznikDni++;
        dzien++;

        // sprawdzmy przestepnosc
        if (rok % 400 == 0) // lata podzielne przez 400 sa przestepne
            czyPrzestepny = true;
        else if (rok % 100 == 0) // lata podzielne przez 100 nie sa przestepne
            czyPrzestepny = false;
        else if (rok % 4 ==0) // lata podzielne przez 4 sa przestepne
            czyPrzestepny = true;
        else // reszta nie jest przestepna
            czyPrzestepny = false;
        
        
        
        // sprawdzamy ile dni ma miesiac
        if (miesiac == 2 && czyPrzestepny) 
        {
            // luty zalezy od przestepnosci roku
            dniWMiesiacu = 29;
        }
        else if (miesiac == 2)
        {
            dniWMiesiacu = 28;
        }
        else if ( (miesiac == 4) || (miesiac == 6) || (miesiac == 9) || (miesiac == 11))
        {
            dniWMiesiacu = 30;
        }
        else {
            dniWMiesiacu = 31;
        }

        // jesli przekroczylismy liczbe dni
        if (dzien > dniWMiesiacu)
        {
            dzien = 1;
            miesiac++;
        }
        // jesli przekroczylismy granice rok
        if (miesiac > MIESIECY_W_ROKU)
        {
            miesiac = 1;
            rok++;
        }

    }

    // 3. Prezentacja wyniku
    cout    << "Pomiędzy datami\n"
            << rokPoczatek<<"-"<<miesiacPoczatek<<"-"<<dzienPoczatek
            << "\na\n"
            << rokKoniec<<"-"<<miesiacKoniec<<"-"<<dzienKoniec
            << "\njest dokladnie " << licznikDni <<" dni\n";

    return 0;
}
