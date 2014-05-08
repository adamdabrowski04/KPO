#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "../inc/rozmiar.h"
#include "../inc/Wektor.hh"
#include <iostream>


/*!
 *\file
 *\brief Definicja szblonu klasy Macierz
 *
 * Plik zawiera definicję szablonu klasy Macierz i deklaracje jej funkcji składowych
 *
 */

/*!
 *\brief Modeluje macierz
 *
 * Szabon klasy modeluje pojęcie macierzy kawadratowj o określonej wielkości(parametr szablonu) dla obiektów dwolnego typu.
 * Głównym elementem klasy jest szablony klasy Wektro którego parametrem jest drugi szablon klasy wektor
 */

template <class TYP, int ROZMIAR>
class Macierz{

  public:
  /*!
   *\brief Kwadratowa macierz danych
   */
  Wektor<Wektor<TYP, ROZMIAR>, ROZMIAR > A;
  Macierz();
   ~Macierz();
/*!
 * \brief Operator mnożenia macierzy przez wektor
 *
 * \param[in] Wek - Wektor przez, który mnozymy macierz
 * \pre
 * Macierze muszą być tego samego rozmiaru
 *
 * \return
 * Zwraca wektor wynikowy.
 *
 */
  Wektor<TYP, ROZMIAR> operator*(Wektor<TYP, ROZMIAR> );
/*!
 *\brief Funkcja transponuje macierz
 *
 *\pre transponowana macierz musi być kwadratowa
 *
 *\return transponowana macierz
 */
  Macierz<TYP, ROZMIAR>Transponuj(void);
  protected:
  private:

};


 /*!
 * \brief Wczytuje liczbę danych do Macierzy określoną w zmiennej ROZMIAR
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[in] Strm - Strm referencja do strumienia z jakiego wczytujemy dane
 * \param[in] Mac - referencja do macierzy do której wpisujemy dane
 *
 *
 * \pre
 * Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * \post
 * Do macierzy zostają wczytane liczby
 *
 * \return
 * Referencja do strumienia, z którego wczytujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &Mac);


 /*!
 * \brief Wypisuje do danego strumienia Macierz danych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[out] Strm - strumień, do którego wypisujemy dane
 * \param[in] Mac - Macierz danych do wypisania
 *
 *
 * \pre
 * BRAK
 *
 * \post
 * Na dane wyjście zostaje wypisana Macierz danych
 *
 * \return
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, Macierz<TYP, ROZMIAR> &Mac);


#endif
