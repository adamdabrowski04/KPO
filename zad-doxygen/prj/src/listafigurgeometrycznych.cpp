/*
 * Definicje metod klasy ListaFigurGeometrycznych
 *
 * Zawiera definicje metod klasy ListaFigurGeometrycznych
 * oraz funkcję pomocniczą WyswietlPole.
 */


#include <iostream>
#include "listafigurgeometrycznych.hh"
using namespace std;


/*
 * Dodaje do listy kwadratów nowy obiekt reprezentujący
 * kwadrat.
 *
 * DlugoscBoku - długość boku kwadratu, który 
 *              zostać dodany do listy. Długość
 *              wyrażona jest w jednostkach niemianowanych.
 */
void ListaFigurGeometrycznych::DodajKwadrat(double DlugoscBoku)
{
  _ListaFigur.push_back(new Kwadrat(DlugoscBoku));
}



/*
 * Dodaje do listy kół nowy obiekt reprezentujący
 * koło.
 *
 * DlugoscPromienia - długość promienia koła, 
 *                  które zostać dodane do listy. Długość
 *              wyrażona jest w jednostkach niemianowanych.
 */
void ListaFigurGeometrycznych::DodajKolo(double DlugoscPromienia)
{
  _ListaFigur.push_back(new Kolo(DlugoscPromienia));
}




/*
 * Wyświetla pole figury geometrycznej
 *
 * Funkcja wyświetla pole figury geometrycznej. Na podstawie
 * identyfikatora typu figury rozpoznaje, czy obiekt jest
 * częścią składową obiektu klasy Kolo, czy też Kwadrat,
 * lub czy jest to samodzielny obiekt klasy FiguraGeometryczna.
 * W zależności od tego wyświetla dokonuje właściwego rzutowania
 * i wylicza pole figury. Następnie wyświetlany jest komunikat,
 * w którym jest zawarta nazwa rodzaju figury oraz wartość jej pola,
 * np.

     Kwadrat    Pole = 10

 *
 *  Figura - figura geometryczna, dla której ma zostać
 *           wyświetlona wartość jej pola.
 */
void WyswietlPole(const FiguraGeometryczna&  Figura)
{
  switch (Figura.TypFigury()) {
    case TF_Kwadrat:
      cout << " Kwadrat   Pole = "
	   << static_cast<const Kwadrat&>(Figura).ObliczPole() << endl;
      break;

    case TF_Kolo:
      cout << " Kolo      Pole = "
	   << static_cast<const Kolo&>(Figura).ObliczPole() << endl;
      break;

    case TF_Zadna:
      cout << " To nie jest zadna konkretna figura geometryczna." 
           << endl;
      break;
  }
}



/*
 * Wyświetla informację o polach powierzchni wszystkich
 * obiektów, które znajdują się na liście figur geometrycznych.
 * Wielkości pół wyrażone są w jednostkach niemianowanych.
 */
void ListaFigurGeometrycznych::WyswietlPolaFigur() const
{
  for (list<FiguraGeometryczna*>::const_iterator Iter = _ListaFigur.begin();
       Iter != _ListaFigur.end(); ++Iter ) {
    WyswietlPole(**Iter);
  }
}

/*
 *  Usuwa wszystkie obiekty tworzone dynamicznie w momencie dodawania
 *  nowego kwadratu lub kola. Operacja ta musi być wykonana zaimplementowana,
 *  gdyż destruktor szablonu std::list<> samodzielnie nie usunąłby ich.
 */
ListaFigurGeometrycznych::~ListaFigurGeometrycznych()
{
  for (list<FiguraGeometryczna*>::iterator Iter = _ListaFigur.begin();
       Iter != _ListaFigur.end(); ++Iter ) {

   switch ((*Iter)->TypFigury()) {
    case TF_Kwadrat:
      delete static_cast<Kwadrat*>(*Iter);
      break;

    case TF_Kolo:
      delete static_cast<const Kolo*>(*Iter);
      break;

    case TF_Zadna:
      delete *Iter;
      break;
   }
  }
}
