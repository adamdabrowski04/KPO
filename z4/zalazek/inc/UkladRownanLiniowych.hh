#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cmath>
#include "../inc/rozmiar.h"
#include "../inc/Wektor.hh"
#include "../inc/Macierz.hh"
#include "../inc/rozmiar.h"
 /*!
 * \brief Definicja klasy Uklad Rownan
 *
 *Klasa Modeluje pojecie Ukladu rownan zawiera macierz Wzpolczynnikow i macierz wyrazow owlnych
 *
 *
 */
template <class TYP, int ROZMIAR>
class UkladRownanLiniowych {


  public:
  Wektor<int, ROZMIAR> PI;
    Macierz<TYP, ROZMIAR> Mac_A, LU;
  Wektor<TYP, ROZMIAR>  Wek_b, Wek_X;
/*!
 * \brief Wylicza rozkład macierzy LUP
 *
 *Wylicza rozkład macierzy LUP oparty o algorytm z  książki
 *"Introduction to Algorithms" Cormena
 *
 *
 * Watunki wstępne:
 * \pre Macierz musi posiadać niezerowy wyznacznik
 *
 * Warunki końcowe:
 * \post Zostaje policzaony rozkład macierzy LUP w miejscu
 *
 * Zwracana wartość:
 * \return Wyliczona Macierz LU
 *
 */
  Macierz<TYP, ROZMIAR> Rozklad_LUP();
/*!
 * \brief Oblicza uklad rownan w oparci ma macierz LUP
 *
 *Wylicza uklad rownan w oparciu o macierz LUP algorytm z  książki
 *"Introduction to Algorithms" Cormena
 *
 *
 * Watunki wstępne:
 * \pre Brak
 *
 * Warunki końcowe:
 * \post Zostaje policzaony Wynik ukladu rownan
 *
 * Zwracana wartość:
 * \return Wektor wynikowy *
 */
  Wektor<TYP, ROZMIAR> Rozwiaz_LUP(void);
/*!
 * \brief Oblicza blad popelniony dla danego rozwiazania ukladu rownan
 *
 * \param[in] WekRozw - Wektor rozwiazan danej macierzy
 *
 * Watunki wstępne:
 * \pre BRAK
 *
 * Warunki końcowe:
 * \post Zostaje obliczony blad śreni kwadratowy dla danego rozwiazania
 *
 * Zwracana wartość:
 * \return Wartość typu TYP
 *
 */
  TYP ObliczBlad(Wektor<TYP, ROZMIAR> WekRozw);
  protected:

  private:

};


 /*!
 * \brief Wczytuje liczbę danych do Macierzy określoną w zmiennej ROZMIAR
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * parametr 1 - Strm referencja do strumienia z jakiego wczytujemy dane
 * parametr 2 - referencja do struktury danych do ktroej wczytujemy liczby
 *
 *
 * Watunki wstępne:
 * Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * Warunki końcowe:
 * Do macierzy i wektora wyrazow wolnych zostają wczytane liczby
 *
 * Zwracana wartość:
 * Referencja do strumienia, z którego wczytujemy dane
 *
 */
 template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

/*!
 * \brief Wypisuje do danego strumienia Macierz danych i wektor wyrazow wolnych
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
 * Na dane wyjście zostaje wypisana Macierz danych i wektor wyrazow owlnych
 *
 * Zwracana wartość:
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
 template <class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<TYP, ROZMIAR>    &UklRown
                          );


#endif
