#ifndef KOLO_HH
#define KOLO_HH


/*
 * Definicja klasy Kolo
 *
 * Plik zawiera definicję klasy Kolo, która
 * jest klasą pochodną i jest ona specjalizacją
 * klasy FiguraGeometryczna
 */

#include "figurageometryczna.hh"

/*
 * Modeluje pojęcie kola
 *
 *  Klasa modeluje pojęcie kola o zadanym promieniu.
 *  Jej atrybutem jest pole zawierające wielkość promienia.
 *  Przyjmuje się, że długość promienia podawana jest jednostkach
 *  niemianowanych.
 */
class Kolo: public FiguraGeometryczna {
  /*
   * Długość promienia kola
   * 
   * Pole zawiera długość promienia kola. Przyjmuje
   * się, że jest ona podana w jednostkach niemianowanych.
   */
   double   _DlugoscPromienia; 
  public:
  /*
   * Inicjalizuje długość promienia
   *
   * Inicjalizuje długość promienia oraz wymusza wywołania konstruktora
   * klasy bazowej z identyfikatorem właściwym dla figury geometrycznej
   * typu kolo.
   *
   * Promien - długość promienia kola. Jest ona zapisywana
   *              w polu _DlugoscPromienia.
   */
   Kolo(double  Promien): FiguraGeometryczna(TF_Kolo), 
			 _DlugoscPromienia(Promien) {}

   /*
    * Zmienia długość boku kola
    *
    * Zmienia wartość długości boku kola.
    * Nowa wartość wpisywana jest do pola _DlugoscPromienia.
    * \param[in] Dlugosc - nowa wartość długości boku.
    *                      długość podawana jest w jednostkach 
    *                      niemianowanych.
    */
   void ZmienDlugoscPromien(double Dlugosc) { _DlugoscPromienia = Dlugosc; }

   /*
    * Udostępnia długość boku kola
    *
    *  Zwraca długość boku danego kola. Przyjmuje się,
    *  że jest ona wyrażona w jednostkach niemianowanych.
    *
    *  Zwraca zawartość pola _DlugoscPromienia.
    */
   double WezDlugoscPromienia() const { return _DlugoscPromienia; }
   /*
    * Wyznacza pole powierzchni kola
    */
  double ObliczPole() const;
};

#endif
