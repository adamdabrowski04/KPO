#include <iostream>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
 // UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
   Wektor<double, ROZMIAR_DEFINED>  Wek_Rozw;
    UkladRownanLiniowych<double, ROZMIAR_DEFINED> A;
    cin>>A.Mac_A;
   // cout<<"maicierz"<<A.Mac_A;
    cin>>A.Wek_b;
    A.Rozklad_LUP();
    cout<<"pies"<<endl;
    //cout<<"maicierz"<<A.LU;
    A.Rozwiaz_LUP();
    cout<<A.Wek_X;

cout<<"koniec programu"<<endl;
}
