#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cmath>
#include "../inc/rozmiar.h"
#include "../inc/Wektor.hh"
#include "../inc/Macierz.hh"
#include "../inc/rozmiar.h"
 /*!
 * \brief Modeluje Układ równań
 *
 *Klasa Modeluje pojecie Ukladu rownan zawiera macierz Wzpolczynnikow, macierz wyrazow owlnych,
 *macierz LU i wektor przekształceń powstałych z rozkładu LUP
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
 *Wylicza rozkład LUP macierzy oparty o algorytm z  książki
 *"Introduction to Algorithms"  Thomas H. Cormen
 *
 *
 * \pre Macierz musi posiadać niezerowy wyznacznik
 *
 * \post Zostaje policzaony rozkład macierzy LUP w miejscu  i zapisany w \link UkladRownanLiniowych::LU \endlink
 *
 * \return Wyliczona Macierz LU
 *
 */
  Macierz<TYP, ROZMIAR> Rozklad_LUP();
/*!
 * \brief Oblicza uklad rownan w oparci ma macierz LUP
 *
 *Oblicza wynik ukladu rownan w oparciu o macierz LUP algorytm z  książki
 *"Introduction to Algorithms" Thomas H. Cormen
 *
 *
 * \pre Brak
 *
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
 * \pre BRAK
 *
 * \post Zostaje obliczony blad śreni kwadratowy dla danego rozwiazania
 *
 * \return Wartość typu TYP -obliczony blad
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
 * \param[in] Strm - referencja do strumienia z jakiego wczytujemy dane
 * \param[out] UklRown - referencja do struktury danych do ktroej wczytujemy liczby
 *
 * \pre Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * \post Do macierzy i wektora wyrazow wolnych zostają wczytane liczby
 *
 * \return Referencja do strumienia, z którego wczytujemy dane
 *
 */

 template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

/*!
 * \brief Wypisuje do danego strumienia Macierz danych i wektor wyrazow wolnych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[in] Strm - strumień, do którego wypisujemy dane
 * \param[out] UklRown - Macierz danych do wypisania
 *
 *
 * \pre
 * BRAK
 *
 * \post
 * Na dane wyjście zostaje wypisana Macierz danych i wektor wyrazow owlnych
 *
 * \return
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
 template <class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<TYP, ROZMIAR>    &UklRown
                          );



#endif
