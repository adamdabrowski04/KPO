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


int main()
{

RozwiazProblem_zespolone(4);


cout<<"\nkoniec programu"<<endl;
}



