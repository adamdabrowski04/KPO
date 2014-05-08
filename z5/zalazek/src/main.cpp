#include <iostream>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"
using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{

    Wektor<double, ROZMIAR_DEFINED>  Wek_Rozw;
    UkladRownanLiniowych<double, ROZMIAR_DEFINED> A;
    double blad;
    cin>>A;
    cout<<"MaicierzA^T\n"<<A.Mac_A;
    cout<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    cout<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    cout<<"Rozwiazanie x= ( x1 x2 x3 )"<<endl;
    cout<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    cout<<"Dlugosc wektora Bledu:  "<<sqrt(blad)<<endl;
cout<<"\nkoniec programu"<<endl;
}
