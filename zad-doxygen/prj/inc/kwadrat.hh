#ifndef KWADRAT_HH
#define KWADRAT_HH

/*
 * Definicja klasy Kwadrat
 *
 * Plik zawiera definicję klasy Kwadrat, która
 * jest klasą pochodną i jest ona specjalizacją
 * klasy FiguraGeometryczna
 */

#include "figurageometryczna.hh"


/*
 * Modeluje pojęcie kwadratu
 *
 *  Klasa modeluje pojęcie kwadratu o zadanej długości boku.
 *  Jej atrybutem jest pole zawierające długość boku.
 *  Przyjmuje się, że długość podawana jest w jednostkach
 *  niemianowanych.
 */
class Kwadrat: public FiguraGeometryczna {
  public:
  /*
   * Inicjalizuje długość boku
   *
   * Inicjalizuje długość boku oraz wymusza wywołania konstruktora
   * klasy bazowej z identyfikatorem właściwym dla figury geometrycznej
   * typu kwadrat.
   *
   *  DlugoscB - długość boku kwadratu. Jest ona zapisywana
   *              w polu  _DlugoscBoku.
   */
   Kwadrat(double  DlugoscB): FiguraGeometryczna(TF_Kwadrat), 
                              _DlugoscBoku(DlugoscB) {}

   /*
    * Zmienia długość boku kwadratu
    *
    * Zmienia wartość długości boku kwadratu.
    * Nowa wartość wpisywana jest do pola _DlugoscBoku
    *
    * Dlugosc - nowa wartość długości boku. Długość podawana jest w jednostkach 
    *           niemianowanych.
    */
   void ZmienDlugoscBoku(double Dlugosc) { _DlugoscBoku = Dlugosc; }

   /*
    * Udostępnia długość boku kwadratu
    *
    *  Zwraca długość boku danego kwadratu. Przyjmuje się,
    *  że jest ona wyrażona w jednostkach niemianowanych.
    *
    *  Zwraca zawartość pola _DlugoscBoku.
    */
   double WezDlugoscBoku() const { return _DlugoscBoku; }
   /*
    * Wyznacza pole powierzchni kwadratu
    */
   double ObliczPole() const;

 private:
  /*
   * Długość boku kwadratu
   *
   * Pole zawiera długość boku kwadratu. Przyjmuje
   * się, że jest ona podana w jednostkach niemianowanych.
   */
   double   _DlugoscBoku; 
};




#endif
