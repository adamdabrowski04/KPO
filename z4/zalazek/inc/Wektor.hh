#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "../inc/rozmiar.h"
#include <iostream>
#include<vector>

using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <class TYP, int ROZMIAR>
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:

/*!
 * \brief Konstruktor z parametrem domniemanym klasy Wektor
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - rozmiar tablicy dla jakiej alokujemy pamięć
 *
 * Warunki wstępne:
 * BRAK
 *
 * Warunki końcowe:
 * Konstruktor alokuje pamięć dla tablicy, o którą oparta jest cała klasa wektor
 *
 * Zwracana wartość:
 * BRAK
 */
  Wektor();
    Wektor(Wektor & Wzor);
    Wektor& operator=(const Wektor<TYP, ROZMIAR>&);
/*!
 * \brief Destruktor klasy Wektor
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * BRAK
 *
 * Watunki wstępne:
 * Wskaźnik pTab musi pokazywać na początek dynamicznej tablicy danych
 *
 * Warunki końcowe:
 * Zostaje zwolniona pamięć na jaką pokazuje wskaźnik pTab
 *
 * Zwracana wartość:
 * BRAK
 */
   ~Wektor();

/*!
 * \brief Operator indeksujacy do tablicy
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - nr indeksu danego elementu
 *
 *
 * Watunki wstępne:
 * Nie jest sprawdzane indeksowanie tablicy - mozna wyjsc poza zakres
 *
 * Warunki końcowe:
 *  Zwraca referencję do elementu tablicy o danym indeksie licząc od 0
 *
 * Zwracana wartość:
 * Zwraca  referencję do elementu tablicy o danym indeksie
 *
 */
inline TYP& operator[](unsigned int i);

/*!
 * \brief Dodaje dwa wektory
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - drugi wektor
 *
 *
 * Watunki wstępne:
 *  Wektory musza być tej samej długości
 *
 * Warunki końcowe:
 *  Dodaje dwa wektory
 *
 * Zwracana wartość:
 *  Wektor wynikowy będący sumą dwóch wektorów
 *
 */
Wektor operator+( Wektor)const;

/*!
 * \brief Odejmuje dwa wektory
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - drugi wektor
 *
 *
 * Watunki wstępne:
 *  Wektory musza być tej samej długości
 *
 * Warunki końcowe:
 *  Odejmuje dwa wektory
 *
 * Zwracana wartość:
 *  Wektor wynikowy będący różnicą dwóch wektorów
 *
 */
Wektor operator-( Wektor)const;

/*!
 * \brief Iloczyn Skalarny dwóch wektorów
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - jeden  ze składników iloczynu
 *
 *
 * Watunki wstępne:
 *  Wektory tej samej długości
 *
 * Warunki końcowe:
 *  funkcja wykonuje iloczyn skalarny dwóch wektorów
 *
 * Zwracana wartość:
 *  Dana będący wynikiem iloczynu skalarnego dwóch we wktorów
 *
 */
 TYP operator*(Wektor)const;

/*!
 * \brief Funkcja mnoząca wektor przez pewien współczynnik
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - współczynnik przez który mnożymy
 *
 *
 * Watunki wstępne:
 *  BRAK
 *
 * Warunki końcowe:
 *  Funkcja mnozy wektor przez podaną daną
 *
 * Zwracana wartość:
 *  Przeskalowany wektor
 *
 */
Wektor operator*(TYP)const;

/*!
 * \brief Funkcja dzieląca wektor przez pewien współczynnik
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - współczynnik przez który dzielimy
 *
 *
 * Watunki wstępne:
 *  operacja dzielenia musi być wykonalna- współczynnik różny od 0
 *
 * Warunki końcowe:
 *  Funkcja dzieli wektor przez podana dana
 *
 * Zwracana wartość:
 *  Przeskalowany wektor
 *
 */
Wektor operator/(TYP)const;

/*!
 * \brief Wskaźnik pokazujący na tablicę danych
 *
 */
 TYP *pTab;

  protected:

  private:
};



 /*!
 * \brief Wczytuje liczbę danych do Wektora określoną w zmiennej ROZMIAR
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - Strm referencja do strumienia z jakiego wczytujemy dane
 * parametr 2 - referencja do wektora do którego wpisujemy dane
 *
 *
 * Watunki wstępne:
 * Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * Warunki końcowe:
 * Do wektora zostają wczytane liczby
 *
 * Zwracana wartość:
 * Referencja do strumienia, z którego wczytujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek);


 /*!
 * \brief Wypisuje do danego strumienia wektor danych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - strumień, do którego wypisujemy dane
 * parametr 2 - wektro danych do wypisania
 *
 *
 * Watunki wstępne:
 * BRAK
 *
 * Warunki końcowe:
 * Na dane wyjście zostaje wypisany wektor danych
 *
 * Zwracana wartość:
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek);

#endif
