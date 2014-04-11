#include <iostream>
#include"../include/dzialania.h"
using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla Symboli  a, b, c, d, e.
*/



/*
  Definicja funkcji: Dodaj, OdwrotnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/

Symbol dodaj(Symbol pierwszy, Symbol drugi)
{
    const Symbol tabDodawania[5][5]={{e, a, b ,c ,d},
                                 {a, b, c, d, e},
                                 {b, c, d, e, a},
                                 {c, d, e, a, b},
                                 {d, e, a, b, c}};

  return tabDodawania[pierwszy][drugi];
}

Symbol odejmij(Symbol pierwszy, Symbol drugi)
{
    return pierwszy+(-drugi);
}

Symbol mnoz(Symbol pierwszy, Symbol drugi)
{
    const Symbol tabMnoz[5][5]={{e,e,e,e,e},
                                {e,a,b,c,d},
                                {e,b,d,a,c},
                                {e,c,a,d,b},
                                {e,d,c,b,a}};

    return tabMnoz[pierwszy][drugi];
}

Symbol dziel(Symbol dzielna, Symbol dzielnik)
{
    if(dzielnik==e)
    {
    cerr<<"Nie mozna dzielic przez zero"<<endl;
    return dzielnik;
    }
    const Symbol tabOdwrotnaDzielenie[5]={e,a,c,b,d};
    return mnoz(dzielna, tabOdwrotnaDzielenie[dzielnik]);
}


/*
  Definicja przeciążeń operatorów
*/

Symbol operator*(Symbol pierwszy, Symbol drugi)
{
    return mnoz(pierwszy, drugi);
}

Symbol operator/(Symbol dzielna, Symbol dzielnik)
{
    return dziel(dzielna, dzielnik);
}
Symbol operator+(Symbol pierwszy, Symbol drugi)
{
  return dodaj(pierwszy,drugi);
}
Symbol operator-(Symbol pierwszy, Symbol drugi)
{
    return odejmij(pierwszy, drugi);
}
Symbol operator-(Symbol element)
{
    const Symbol tabOdwrotnaDodawanie[5]={e, d, c, b, a};
    return tabOdwrotnaDodawanie[element];
}


void sumaTychSamych()
{
    Symbol tab[]={e,a,b,c,d};
    for(int i=0;i<5;i++)
        cout<<tab[i]+tab[i]<<endl;
}



ostream& operator<<(ostream& strm, Symbol a)
{
    char tab[]={'e','a','b','c','d'};
    strm<<tab[a];
    return strm;
}



void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
    static unsigned int licznik=1;
    cout<<"Wyrazenie numer"<<licznik++<<endl;
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne")
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne")
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne")
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}
