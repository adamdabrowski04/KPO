#include <iostream>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"
using namespace std;

/*!
 *\mainpage Program Oblicza układy równan
 *
 *Program oblicza uklady równana dowlonej wielkosci dla liczb rzeczywistych i zespolonych - obie te wartosci ustala sie podczas kompilacji
 *\image html Diagram1.jpeg
 */


int main()
{

    Wektor<Zespolona, ROZMIAR_DEFINED>  Wek_Rozw;
    UkladRownanLiniowych<Zespolona, ROZMIAR_DEFINED> A;
    Zespolona blad;
    cin>>A;
    cout<<"MaicierzA^T\n"<<A.Mac_A;
    cout<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    cout<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    cout<<"Rozwiazanie x= ( x1 x2 x3 x4 )"<<endl;
    cout<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    cout<<"Dlugosc wektora Bledu:  "<<blad<<endl;
cout<<"\nkoniec programu"<<endl;
}



