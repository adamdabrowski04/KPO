#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "../inc/rozmiar.h"
#include "../inc/Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <class TYP, int ROZMIAR>
class Macierz{

  public:
  Wektor<Wektor<TYP, ROZMIAR>, ROZMIAR > A;

  Macierz();
   ~Macierz();
  protected:
  private:



};


 /*!
 * \brief Wczytuje liczbę danych do Macierzy określoną w zmiennej ROZMIAR
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - Strm referencja do strumienia z jakiego wczytujemy dane
 * parametr 2 - referencja do macierzy do której wpisujemy dane
 *
 *
 * Watunki wstępne:
 * Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * Warunki końcowe:
 * Do macierzy zostają wczytane liczby
 *
 * Zwracana wartość:
 * Referencja do strumienia, z którego wczytujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &Mac);


 /*!
 * \brief Wypisuje do danego strumienia Macierz danych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - strumień, do którego wypisujemy dane
 * parametr 2 - Macierz danych do wypisania
 *
 *
 * Watunki wstępne:
 * BRAK
 *
 * Warunki końcowe:
 * Na dane wyjście zostaje wypisana Macierz danych
 *
 * Zwracana wartość:
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP, ROZMIAR> &Mac);


#endif
