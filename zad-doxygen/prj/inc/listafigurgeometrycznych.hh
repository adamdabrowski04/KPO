#ifndef LISTAFIGURGEOMETRYCZNYCH_HH
#define LISTAFIGURGEOMETRYCZNYCH_HH

#include <list>
#include "kolo.hh"
#include "kwadrat.hh"

/*
 * Definicja klasy ListaFigurGeometrycznych
 *
 * Zawiera definicję klasy ListaFigurGeometrycznych. 
 * Modeluje ona rodzaj listy, której elementy mogą obiektami
 * dwóch różnych klas wyprowadzonej z tej samej klasy bazowej.
 */

/*
 * Modeluje listę figur geometrycznych typu kwadrat i koło
 *
 * Klasa modeluje listę figur geometrycznych dwóch typów, tzn.
 * kwadratów i kół. W wewnętrznej budowie klasy istnieją tylko jedna
 * wspólna lista tych obiektów. Nie jest ona  bezpośrednio widoczne
 * poprzez interfejs publiczny klasy.
 *
 * Wspomniany interfejs klasy umożliwia dodawanie nowych figur typu
 * kwadrat lub koło. Pozwala również na wyświetlenie 
 * informacji o polach wszystkich figur, które zostały dodane do
 * wcześniej wspomnianej listy.
 */
class ListaFigurGeometrycznych {
   /*
    * Lista figur geometrycznych
    *
    *  Pole jest zarządcą listy obiektów typu które są typu 
    *  FiguraGeometryczna. Jednak obiekty, które są umieszczane
    *  na tej liście nie są samodzielnymi obiektami.
    *  Są one składnikami obiektów klasy Kolo lub Kwadrat.
    */
   std::list<FiguraGeometryczna*>  _ListaFigur;

  public:
  /*
   *  Usuwa wszystkie obiekty dynamiczne skojarzone z daną listą
   *
   *  Usuwa wszystkie obiekty tworzone dynamicznie w momencie dodawania
   *  nowego kwadratu lub kola. Operacja ta musi być wykonana zaimplementowana,
   *  gdyż destruktor szablonu std::list<> samodzielnie nie usunąłby ich.
   */
   ~ListaFigurGeometrycznych();

   /*
    * Dodaje nowy kwadrat do listy kwadratów
    */
   void DodajKwadrat(double DlugoscBoku);
   /*
    * Dodaje nowe kolo do listy kół
    */
   void DodajKolo(double DlugoscPromienia);
   /*
    * Wyświetla pola kwadratów i kół
    */
   void WyswietlPolaFigur() const;
};



#endif
