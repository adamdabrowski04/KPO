#include "../inc/WyrazenieAlgeb.hh"
#include "../inc/Statystyka.hh"



/*
 *  Tutaj nalezy zdefiniowac odpowiednie funkcje,
 *  ktore beda okreslac dopuszczalne metody dostepu
 *  i akceptowalny zbior operacji na strukturze WyrazenieAlgeb.
 */
using namespace std;
istream& operator>> (istream & strmWe, WyrazenieAlgeb &Wyrazenie)
{
    char znak;
    strmWe>>Wyrazenie.Pierwszy>>Wyrazenie.ZnakDzialania>>Wyrazenie.Drugi>>znak;
    if(znak!='='||cin.fail() )
    {
        strmWe.setstate(ios::failbit);
        return strmWe;
    }
    strmWe>>Wyrazenie.WczytanyWynik;
    return strmWe;
}

ostream& operator<< (ostream & strmWy, const WyrazenieAlgeb &Wyrazenie)
{

   strmWy<<Wyrazenie.Pierwszy<<" "<<Wyrazenie.ZnakDzialania<<" "<<Wyrazenie.Drugi<<" = "<<Wyrazenie.WczytanyWynik;
   return strmWy;

}
Symbol Oblicz (WyrazenieAlgeb &Wyrazenie, Statystyka &Stat)
{
    switch(Wyrazenie.ZnakDzialania)
    {
    case s:
        Wyrazenie.ObliczonyWynik=Wyrazenie.Pierwszy+Wyrazenie.Drugi;
        Stat.OdejmowanieDodawanie++;
        break;
    case r:
        Wyrazenie.ObliczonyWynik=Wyrazenie.Pierwszy-Wyrazenie.Drugi;
        Stat.OdejmowanieDodawanie++;
        break;
    case iloczyn:
        Wyrazenie.ObliczonyWynik=Wyrazenie.Pierwszy*Wyrazenie.Drugi;
        Stat.MnozenieDzielenie++;
        break;
    case iloraz:
        Stat.MnozenieDzielenie++;
        Wyrazenie.ObliczonyWynik=Wyrazenie.Pierwszy/Wyrazenie.Drugi;
        break;

    }
return Wyrazenie.ObliczonyWynik;
}
