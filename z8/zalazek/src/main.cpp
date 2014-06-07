#include <iostream>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"
#include "../inc/RozpoznajProblem.hh"
#include <fstream>
#include <string>
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
bool tabFlag[2] ={false, false};
TypProblemu WczytanyTypProblemu;

string  NazwaPlikuWe;
string  NazwaPlikuWy;
ifstream StrmWe;
ofstream StrmWy;

WczytanyTypProblemu=RozpoznajProblem(argc, argv, ROZMIAR, NazwaPlikuWe, NazwaPlikuWy);
if(!NazwaPlikuWe.empty())
{
    StrmWe.open(NazwaPlikuWe);
    tabFlag[0]=true;
    cout<<NazwaPlikuWe<<endl;
}
if(!NazwaPlikuWy.empty())
{
    StrmWy.open(NazwaPlikuWy);
    tabFlag[1]=true;
    cout<<NazwaPlikuWy<<endl;
}
switch(WczytanyTypProblemu)
{

    case TP_double:
        RozwiazProblem_double(ROZMIAR, (tabFlag[0])?StrmWe:cin, (tabFlag[1])?StrmWy:cout);
    break;
    case TP_zespolone:
        RozwiazProblem_zespolone(ROZMIAR,(tabFlag[0])?StrmWe:cin, (tabFlag[1])?StrmWy:cout);
    break;
    case TP_blad:
        cerr<<"Bledne wywolanie programu!\n\n";
        cout<<"Poprawne wywolanie programu:";
        cout<<"\n\t"<<argv[0]<<" -t [r|z] -r [2-5]"<<endl;
    break;
}
if(tabFlag[0])StrmWe.close();
if(tabFlag[1])StrmWy.close();
cout<<"\nkoniec programu"<<endl;
}


//TODO (adam#5#) makro assert
