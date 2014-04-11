#include <iostream>
#include <list>

using namespace std;

/*!
 * Modeluje ogolne pojecie figury geometrycznej.
 */
class FiguraGeometryczna {
  public:
   FiguraGeometryczna() 
        { cout << " +++ " << FiguraGeometryczna::Nazwa() << endl; }

   virtual ~FiguraGeometryczna() 
	{ cout << " --- " << FiguraGeometryczna::Nazwa() << endl; }

    /* Udostepnia nazwe danej klasy */
   virtual const char* Nazwa() const { return "FiguraGeometryczna"; }
};


/*!
 * Modeluje pojecie kwadratu. W tej wersji
 * demonstrowana jest tylko hierarchia poszczegolnych
 * pojec. Brak jest w definicji klasy dodatkowych
 * atrybutow wlasciwych dla pojecia kwadratu.
 */
class Kwadrat: public FiguraGeometryczna {
  public:
   Kwadrat() { cout << " +++ " << Nazwa() << endl; }
   virtual ~Kwadrat() { cout << " --- " << Nazwa() << endl; }
    /* Udostepnia nazwe danej klasy */
   virtual const char* Nazwa() const { return "Kwadrat"; }
};

/*!
 * Modeluje pojecie trojkata. W tej wersji
 * demonstrowana jest tylko hierarchia poszczegolnych
 * pojec. Brak jest w definicji klasy dodatkowych
 * atrybutow wlasciwych dla pojecia trojkata.
 */
class Trojkat: public FiguraGeometryczna {
  public:
   Trojkat() { cout << " +++ " << Nazwa() << endl; }
   virtual ~Trojkat() { cout << " --- " << Nazwa() << endl; }
    /* Udostepnia nazwe danej klasy */
   virtual const char* Nazwa() const { return "Trojkat"; }
};


/*!
 * Modeluje liste figur geometrycznych dwoch rodzai tj. trojkatow
 * i kwadratow
 */
class ListaFigurGeometrycznych: public list<FiguraGeometryczna*> {
  public:
    ~ListaFigurGeometrycznych();
    void Wyswietl() const;
    Kwadrat* DodajKwadrat();
    Trojkat* DodajTrojkat();
};

/*!
 * Tworzy obiekt klasy Kwadrat, dodaje go do listy
 * i zwraca wskaznik na ten obiekt.
 */
Kwadrat* ListaFigurGeometrycznych::DodajKwadrat()
{
  cout << endl << "* Dodaje Kwadrat" << endl;
  Kwadrat *wObKwadrat = new Kwadrat();
  push_back(wObKwadrat);
  return wObKwadrat;
}


/*!
 * Tworzy obiekt klasy Trojkat, dodaje go do listy
 * i zwraca wskaznik na ten obiekt.
 */
Trojkat* ListaFigurGeometrycznych::DodajTrojkat()
{
  cout << endl << "* Dodaje Trojkat" << endl;
  Trojkat *wObTrojkat = new Trojkat();
  push_back(wObTrojkat);
  return wObTrojkat;
}


/*!
 * Usuwa wszystkie obiekty dynamicznie utworzone, których
 * wkaźniki zostały zapamiętane na liście.
 */
ListaFigurGeometrycznych::~ListaFigurGeometrycznych()
{
  cout << endl << "* Start destruktora listy:" << endl;
  for (iterator  Iter = begin();  Iter != end(); ++Iter) {
     cout << "- Start destrukcji elementu:" << endl;
     delete (*Iter);
  }
}


/*!
 * Wyswietla liste wszystkich elementow listy.
 */
void ListaFigurGeometrycznych::Wyswietl() const
{
  cout << endl << "* Lista elementow:" << endl;
  for (const_iterator  Iter = begin();  Iter != end(); ++Iter) {
      cout << "  " << (*Iter)->Nazwa() << endl;
  }
}



int main()
{
  ListaFigurGeometrycznych  ListaFig;

  ListaFig.DodajKwadrat();
  ListaFig.DodajTrojkat();
  ListaFig.DodajTrojkat();

  ListaFig.Wyswietl();
}
