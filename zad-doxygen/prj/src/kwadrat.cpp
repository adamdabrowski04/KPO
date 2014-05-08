#include "kwadrat.hh"

/*
 * Definicja metody klasy Kwadrat
 *
 * Zawiera definicję metod klasy Kwadrat.
 */


/*
 * Wyznacza pole powierzchni danego kwadratu
 * i zwraca jego wartość. 
 *
 * Zwraca pole powierzchni kwadratu. Jest ono wyrażone
 * w jednostkach niemianowanych.
 */
double Kwadrat::ObliczPole() const 
{ 
  return _DlugoscBoku*_DlugoscBoku; 
}
