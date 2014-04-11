#include "../inc/Statystyka.hh"



/*
 *  Tutaj nalezy zdefiniowac odpowiednie funkcje,
 *  ktore beda okreslac dopuszczalne metody dostepu
 *  i akceptowalny zbior operacji na strukturze Statystyka.
 unsigned int DobreOdpowiedzi, ZleOdpowiedzi, IloscWszystkichWyrazen;

 */
using namespace std;
ostream& operator<<(ostream& strm, const Statystyka& A)
{
    const int SZEROKOSC_POLA=10;
   cout<<"Statystyka:"<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Ilość wszystkich wyrażeń: "<<A.IloscWszystkichWyrazen<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Ilość poprawnie zapisanych wyrazen: "<<A.DobreOdpowiedzi+A.ZleOdpowiedzi<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Ilość wyrażeń z poprawnym wynikiem: "<<A.DobreOdpowiedzi<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Procentowo ilość poprawnych wyników: "<<A.DobreOdpowiedzi*100/(A.DobreOdpowiedzi+A.ZleOdpowiedzi)<<"%"<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Ilość operacji odejmowania i dodawania: "<<A.OdejmowanieDodawanie<<endl;
   cout<<setw(SZEROKOSC_POLA)<<"Ilość operacji mnozenia i dzielenia: "<<A.MnozenieDzielenie<<endl;
   return strm;
}
Statystyka::Statystyka()
{

    DobreOdpowiedzi=0;
    ZleOdpowiedzi=0;
    IloscWszystkichWyrazen=0;
    OdejmowanieDodawanie=0;
    MnozenieDzielenie=0;

}
