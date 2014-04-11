#ifndef DZIALANIA_H_INCLUDED
#define DZIALANIA_H_INCLUDED

#include<iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla Symboli  a, b, c, d, e.
*/
enum Symbol {e, a ,b, c, d};


/*
  Deklaracja funkcji: Dodaj, OdwrotnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
/*!
 *\brief Funkcja sumująca dwa elementy
 *
 * PRE: brak
 * POST: funkcja zwraca element typu Symbol
 * Funkcja dodaje dwa elementy zwracajac odpowiedni element
 * z tablicy dodawania
 *
 */
Symbol dodaj(Symbol pierwszy, Symbol drugi);

/*!
 *\brief Funkcja odejmujaca dwa elementy
 *
 * PRE: brak
 * POST: funkcja zwraca element typu Symbol
 * Funkcja odejmuje dwa elementy dodajac do elementu pierwszego odwrotność
 * elementu drugie względem operacji dodawania
 *
 */
Symbol odejmij(Symbol pierwszy, Symbol drugi);

 /*!
 *\brief Funkcja mnożąca dwa elementy
 * PRE: brak
 * POST: funkcja zwraca element typu Symbol
 * Funkcja mnoży dwa elementy zwracajac odpowiedni element z tablicy mnożenia
 *
 */
Symbol mnoz(Symbol pierwszy, Symbol drugi);

/*!
 *\brief Funkcja dzieląca dwa elementy
 *
 * PRE: brak
 * POST: funkcja zwraca element typu Symbol, jezeli dzielnik jest zerowy
 *        zwraca zerowy element nie wykonujac zadnych operacji
 * Funkcja dzieli pierwszy element przez drugi mnożąc element pierwszy przez odwrotność
 * elementu drugie względem operacji mnożenia
 *
 */
Symbol dziel(Symbol dzielna, Symbol dzielnik);


/*
  Deklaracja przeciążeń operatorów
*/

/*!
 *\brief Przeciążenie operatora mnożenia
 *
 * Funkcja wywołuje funkcje mnoz i zwraca jej wynik
 */
Symbol operator*(Symbol pierwszy, Symbol drugi);

/*!
 *\brief Przeciążenie operatora dzielenia
 *
 * Funkcja wywołuje funkcje dziel i zwraca jej wynik
 */
Symbol operator/(Symbol dzielna, Symbol dzielnik);

/*!
 *\brief Przeciążenie operatora dodawania
 *
 * Funkcja wywołuje funkcje dodaj i zwraca jej wynik
 */
Symbol operator+(Symbol pierwszy, Symbol drugi);

/*!
 *\brief Przeciążenie operatora odejmowania
 *
 * Funkcja wywołuje funkcje odejmij i zwraca jej wynik
 */
Symbol operator-(Symbol pierwszy, Symbol drugi);

/*!
 *\brief Przeciążenie operatora elementu odwrotnego
 *
 * Funkcja zwraca element odwrotny wzgledem operacji dodawania
 */
Symbol operator-(Symbol element);

/*!
 *\brief Zwraca sumę tych samych elementów-czyli elementy z przekątnej tabeli dodawania
 *
 */
void sumaTychSamych(void);

/*!
 *\brief Przeciążenie operatora wypisywania na standardowe wyjście
 *
 */
ostream& operator<<(ostream& strm, Symbol a);

void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun);


#endif // DZIALANIA_H_INCLUDED
