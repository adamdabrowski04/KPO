#include <iostream>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"
#include "../inc/RozpoznajProblem.hh"

using namespace std;

/*!
 *\mainpage Program Oblicza układy równan
 *
 *Program oblicza uklady równana dowlonej wielkosci dla liczb rzeczywistych i zespolonych - obie te wartosci ustala sie podczas kompilacji
 *\image html Diagram1.jpeg
 */
int ROZMIAR;

int main(int argc, char* argv[])
{
TypProblemu WczytanyTypProblemu;
WczytanyTypProblemu=RozpoznajProblem(argc, argv, ROZMIAR);

switch(WczytanyTypProblemu)
{
    case TP_double:
        RozwiazProblem_double(ROZMIAR);
    break;
    case TP_zespolone:
        RozwiazProblem_zespolone(ROZMIAR);
    break;
    case TP_blad:
        cerr<<"Bledne wywolanie programu!\n\n";
        cout<<"Poprawne wywolanie programu:";
        cout<<"\n\t"<<argv[0]<<" -t [r|z] -r [2-5]"<<endl;
    break;
}

cout<<"\nkoniec programu"<<endl;
}



