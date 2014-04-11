#ifndef WYRAZENIEALGEB_HH
#define WYRAZENIEALGEB_HH

#include "../inc/Symbol.hh"
#include "../inc/Statystyka.hh"
using namespace std;

struct WyrazenieAlgeb
{
    Symbol Pierwszy, Drugi, WczytanyWynik, ObliczonyWynik;
    ZnakDzial ZnakDzialania;
    bool TabBledow[5];
};


/*!
 * \brief Przeciążenie operatora wczytywania dla Wyrażenia algebraicznego
 *
 *  strmWe - strumień z którego wczytujemy dane
 *  &Wyrazenie - referencja do zmiennej, w której zapiszemy dane
 *
 * Watunki wstępne:
 *  Dane muszą byś wpisane w podowiedni sposób czyli:
 *  Symbol znak operacji symbol = wynik
 *   np a + a = b - znaki białe nie mają tu większego znaczenia
 *
 * Warunki końcowe:
 *  W zmiennej &Wyrazenie zostaje zapisany wczytany wynik
 *
 * Zwracana wartość - referencja do strumienia z kŧórego wczytujemy
 */

istream& operator>> (istream & strmWe, WyrazenieAlgeb &Wyrazenie);

/*!
 * \brief Przeciążenie operatora wypisywania dla Wyrażenia algebraicznego
 *
 *  strmWy - strumień do którego wysyłamy dane
 *  &Wyrazenie - referencja do zmiennej, któreą wypisujemy
 *
 * Watunki wstępne:
 * BRAK
 *
 * Warunki końcowe:
 *  W zmiennej &Wyrazenie zostaje wypisane do właściwego strumienia
 *
 * Zwracana wartość - referencja do strumienia do którego wypisujemy dane
 */
ostream& operator<< (ostream & strmWy, const WyrazenieAlgeb &Wyrazenie);

/*!
 * \brief Funkcja oblicza wyrażenie
 *
 *  WyrazenieAlgeb& - referencja do zmiennej, w której jst zapisane wyrażenie
 *
 * Watunki wstępne:
 *   BRAK
 *
 * Warunki końcowe:
 *  funkcja wykona odpowiednie obliczenia zapisze wynik w zmiennej Obliczony wynik w tej strukturze danych i zwróci wynik
 *
 * Zwracana wartość - wynik wybranej operacji
 */
Symbol Oblicz(WyrazenieAlgeb&, Statystyka&);


#endif
