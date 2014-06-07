#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "../inc/rozmiar.h"
#include <iostream>
#include<vector>

using namespace std;

/*!
 *\file
 *\brief Definicja szblonu klasy Wektor
 *
 * Plik zawiera definicję szablonu klasy Wektor i deklaracje jej funkcji składowych
 *
 */

/*!
 *\brief Modeluje wektor
 *
 * Szabon klasy modeluje pojęcie wekor o określonej długośc (parametr szablonu) dla obiektów dwolnego typu.
 * Głównym elementem klasy jest wskażnik do obszaru pamięci zawierającego dane
 */
template <class TYP>
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  int ROZMIAR;
/*!
 * \brief Konstruktor z parametrem domniemanym klasy Wektor
 *
 *
 * \pre
 * BRAK
 *
 * \post
 * Konstruktor alokuje pamięć dla tablicy, o którą oparta jest cała klasa wektor, zapisuje jej adres we wskaźniku
 *\link Wektor::pTab \endlink.
 *
 * \return
 * BRAK
 */
  Wektor(int=0 );
/*!
 * \brief Konstruktor kopjujący
 *
 * Konstruktor alokuje pamięć dla nowego obiektu i kopjuje wszystkie elementy wektora
 */
    Wektor(Wektor & Wzor);
/*!
 * \brief operator przypisania
 *
 * operator przypisania alkouje pamięć i kopjuje wszysktie elementy wektora
 */
    Wektor& operator=(const Wektor<TYP>&);
/*!
 * \brief Destruktor klasy Wektor
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * BRAK
 *
 * \pre
 * Wskaźnik pTab musi pokazywać na początek dynamicznej tablicy danych
 *
 * \post
 * Zostaje zwolniona pamięć na jaką pokazuje wskaźnik pTab
 *
 * \return
 * BRAK
 */
   ~Wektor();

/*!
 * \brief Operator indeksujacy do tablicy
 *
 * \pre
 * Nie jest sprawdzane indeksowanie tablicy - mozna wyjsc poza zakres
 *
 * \post
 *  Zwraca referencję do elementu tablicy o danym indeksie licząc od 0
 *
 * \return
 * Zwraca  referencję do elementu tablicy o danym indeksie
 *
 */
inline TYP& operator[](unsigned int i);

/*!
 * \brief Dodaje dwa wektory
 *
 *
 * \pre
 *  Wektory musza być tej samej długości
 *
 * \post
 *  Dodaje dwa wektory
 *
 * \return
 *  Wektor wynikowy będący sumą dwóch wektorów
 *
 */
Wektor operator+( Wektor)const;

/*!
 * \brief Odejmuje dwa wektory
 *
 *
 * \pre
 *  Wektory musza być tej samej długości
 *
 * \post
 *  Odejmuje dwa wektory
 *
 * \return
 *  Wektor wynikowy będący różnicą dwóch wektorów
 *
 */
Wektor operator-( Wektor)const;

/*!
 * \brief Iloczyn Skalarny dwóch wektorów
 *
 * \pre Wektory tej samej długości
 *
 * \post
 *  funkcja wykonuje iloczyn skalarny dwóch wektorów
 *
 * \return
 *  Dana będący wynikiem iloczynu skalarnego dwóch we wktorów
 *
 */
 TYP operator*(Wektor)const;

/*!
 * \brief Funkcja mnoząca wektor przez pewien współczynnik
 *
 * \pre
 *  BRAK
 *
 * \post
 *  Funkcja mnozy wektor przez podaną daną
 *
 * \return
 *  Przeskalowany wektor
 *
 */
Wektor operator*(TYP)const;

/*!
 * \brief Funkcja dzieląca wektor przez pewien współczynnik
 *
 * \pre
 *  operacja dzielenia musi być wykonalna- współczynnik różny od 0
 *
 * \post
 *  Funkcja dzieli wektor przez podana dana
 *
 * \return
 *  Przeskalowany wektor
 *
 */
Wektor operator/(TYP)const;

/*!
 * \brief Wskaźnik pokazujący na tablicę danych
 *
 */
 //vector<TYP> pTab;
    TYP *pTab;
  protected:

  private:
};



 /*!
 * \brief Wczytuje liczbę danych do Wektora określoną w zmiennej ROZMIAR
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[in] Strm - referencja do strumienia z jakiego wczytujemy dane
 * \param[out] Wek - referencja do wektora do którego wpisujemy dane
 *
 *
 * \pre
 * Wczytywane liczby muszą być oddzielone znakiem białym
 *
 * \post
 * Do wektora zostają wczytane liczby
 *
 * \return
 * Referencja do strumienia, z którego wczytujemy dane
 *
 */
template <class TYP>
std::istream& operator >> (std::istream &Strm, Wektor<TYP> &Wek);


 /*!
 * \brief Wypisuje do danego strumienia wektor danych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[out] Strm - strumień, do którego wypisujemy dane
 * \param[in] Wek - wektro danych do wypisania
 *
 *
 * \pre
 * BRAK
 *
 * \post
 * Na dane wyjście zostaje wypisany wektor danych
 *
 * \return
 * Referencja do strumienia, do którego wypisujemy dane
 *
 */
template <class TYP>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP> &Wek);

#endif
