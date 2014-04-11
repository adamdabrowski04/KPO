#include"../inc/Symbol.hh"
/*
  Definicja funkcji: Dodaj, OdwrotnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
using namespace std;
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


ostream& operator<<(ostream& strm, Symbol a)
{
    char tab[]={'e','a','b','c','d'};
    strm<<tab[a];
    return strm;
}

istream& operator>> (istream & strmWe, Symbol &wynik)
{
    char wczytany;
    string wzor="eabcd";
    Symbol tabWzorSymboli[]={e,a,b,c,d};
    string::size_type NumerLitery;
    strmWe>>wczytany;
    NumerLitery=wzor.find(wczytany);
    if(NumerLitery==string::npos)
    {
        strmWe.setstate(ios::failbit);
        return strmWe;
    }
    else
    {
        wynik=tabWzorSymboli[NumerLitery];
        return strmWe;
    }
}


ostream& operator<<(ostream& strm, ZnakDzial a)
{
    char tab[]={'+','-','*','/'};
    strm<<tab[a];
    return strm;
}

istream& operator>> (istream & strmWe, ZnakDzial &wynik)
{
    char wczytany;
    string wzor="+-*/";
    ZnakDzial tabWzorSymboli[]={s,r,iloczyn,iloraz};
    string::size_type NumerLitery;
    strmWe>>wczytany;
    NumerLitery=wzor.find(wczytany);
    if(NumerLitery==string::npos)
    {
        strmWe.setstate(ios::failbit);
        return strmWe;
    }
    else
    {
        wynik=tabWzorSymboli[NumerLitery];
        return strmWe;
    }
}
