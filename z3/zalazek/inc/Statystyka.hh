#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include<iostream>
#include<iomanip>
using namespace std;
struct Statystyka
{

    unsigned int DobreOdpowiedzi, ZleOdpowiedzi, IloscWszystkichWyrazen;
    unsigned int OdejmowanieDodawanie, MnozenieDzielenie;
    Statystyka();
};

/*!
 * \brief Przeciążenie operatora Wypisywania dla struktury statystyka
 *
 *  strm - strumień do którego wysyłamy dane
 *  Statystyka - obiekt dla którego wypisujemy dane
 *
 * Watunki wstępne:
 *  BRAK
 *
 * Warunki końcowe:
 *  Na ekran zostają wypisane statystyki
 *
 * Zwracana wartość - referencja do strumienia do którego wysyłmay dane
 */
ostream& operator<<(ostream& strm, const Statystyka& );

//void WyiszStatystyki(Statystyka);


#endif
