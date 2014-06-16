#include "../include/Wielobok.h"
#include<string>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
Wielobok::Wielobok()
{
    //ctor
}

Wielobok::~Wielobok()
{
    //dtor
}


bool WczytajWierzcholki()
{


}


bool Wielobok::ZapiszWierzcholkiDoPliku(string nazwa_pliku)
{
    ofstream strumien_wyjsciowy;
    strumien_wyjsciowy.open(nazwa_pliku);
    for(unsigned int i=0; i<tablica_x.size();i++)
    {
      strumien_wyjsciowy<<tablica_x[i]<<" "<<tablica_y[i]<<endl;
    }
    strumien_wyjsciowy.close();
  return true;
}
