#include "kolo.hh"

/*
 * Definicja metody klasy Kolo
 *
 * Zawiera definicję metod klasy Kolo.
 */



#define PI    3.1415927

/*
 * Wyznacza pole powierzchni danego kwadratu
 * i zwraca jego wartość. 
 *
 * Zwraca pole powierzchni kwadratu. Jest ono wyrażone
 * w jednostkach niamianowanych.
 */
double Kolo::ObliczPole() const 
{ 
  return PI*_DlugoscPromienia*_DlugoscPromienia; 
}
