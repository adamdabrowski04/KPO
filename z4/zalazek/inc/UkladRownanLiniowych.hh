#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "../inc/rozmiar.h"
#include "../inc/Wektor.hh"
#include "../inc/Macierz.hh"
#include "../inc/rozmiar.h"
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <class TYP, int ROZMIAR>
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

  public:
  Wektor<TYP, ROZMIAR> Rozwiaz_LUP(void);
  Wektor<int, ROZMIAR> PI;
    Macierz<TYP, ROZMIAR> Mac_A, LU;
  Wektor<TYP, ROZMIAR>  Wek_b, Wek_X;
  Macierz<TYP, ROZMIAR> Rozklad_LUP();

  protected:

  private:

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
 template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
 template <class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<TYP, ROZMIAR>    &UklRown
                          );


#endif
