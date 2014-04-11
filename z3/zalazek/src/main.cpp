#include <iostream>
#include <stdio.h>
#include "../inc/WyrazenieAlgeb.hh"
#include "../inc/Statystyka.hh"
#include "../inc/Symbol.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

using namespace std;
int main()
{
  //Symbol           x, y;    // To tylko przykladowe definicje zmiennych
  Statystyka       Stat;
  WyrazenieAlgeb   Wyrazenie;


  cout << "Start sprawdzianu testu arytmetyki symboli" << endl;
  while(cin.peek()!=EOF)
  {
    cin>>Wyrazenie;
    Stat.IloscWszystkichWyrazen++;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        continue;
    }
    cout<<"Wczytano wyrażenie : "<< Wyrazenie;
    Oblicz(Wyrazenie,Stat);
    if(Wyrazenie.ObliczonyWynik==Wyrazenie.WczytanyWynik)
    {
       cout<<" Wynik poprawny."<<endl;
       Stat.DobreOdpowiedzi++;
    }
    else
    {
       cout<<" Wynik niepoprawny."<<endl;
       Stat.ZleOdpowiedzi++;
    }
  }
  cout<<Stat;
return 0;
}


