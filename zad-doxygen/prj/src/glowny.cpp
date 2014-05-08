#include "listafigurgeometrycznych.hh"


/*
 * Moduł główny
 *
 * Zawiera funkcję \p main, w której jest przykład
 * użycia obiektu klasy ListaFigurGeometrycznych.
 */


int main()
{
  ListaFigurGeometrycznych   LstFig;

  LstFig.DodajKwadrat(2);
  LstFig.DodajKwadrat(3.4);
  LstFig.DodajKolo(1);

  LstFig.WyswietlPolaFigur();
}
