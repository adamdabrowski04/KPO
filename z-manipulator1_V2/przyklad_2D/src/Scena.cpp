#include "../include/Scena.h"
#include<fstream>
#include<iostream>

using namespace std;

Scena::Scena()
{
    //ctor
}

bool Scena::czy_kolizja_na_scenie(void)
{
  for(unsigned int i=0; i<lista_manipulatorow.size(); i++)
  {
    for(unsigned int j=0; j<lista_manipulatorow.size(); j++)
    {
      if(i!=j)
      {
        if(czy_kolizja_manipulatora_z_manipulatorem(lista_manipulatorow[i],lista_manipulatorow[j]) )
        return true;
      }
    }
  }
  return false;
}

bool Scena::WczytajScene(string nazwa_pliku_sceny)
{
    Manipulator tmp_manipulator;
    string tmp_string;
    ifstream StrmWej;
    StrmWej.open(nazwa_pliku_sceny);
    while(StrmWej.peek()!=EOF)
    {

        StrmWej>>tmp_string;
        if(tmp_string=="M:")
        {

            StrmWej>>tmp_manipulator.nazwa;
            StrmWej>>tmp_string;
            if(tmp_string=="(")
            {
                StrmWej>>tmp_manipulator.zamocowanie_x;
                StrmWej>>tmp_manipulator.zamocowanie_y;
                StrmWej>>tmp_string;
                if(tmp_string!=")")
                    return false;
            }
            else
                return false;
                StrmWej>>tmp_string;
                cout<<tmp_string<<endl;

            tmp_manipulator.WczytajDlugosciOgniw(tmp_string);
            StrmWej>>tmp_string;
            cout<<tmp_string<<endl;
            tmp_manipulator.WczytajKaty(tmp_string);
            tmp_manipulator.ZapiszWierzcholkiDoPliku(tmp_manipulator.nazwa);
            lista_manipulatorow.push_back(tmp_manipulator);
            cout<<"hhhhh"<<endl;
            cout<<lista_manipulatorow.size()<<endl;
        }
        else if(StrmWej.peek()!=EOF)
            return false;
    }
    StrmWej.close();
    return true;
}


 bool Scena::RysujScene(PzG::LaczeDoGNUPlota &Lacze)
 {
    for(vector<Manipulator>::iterator it =lista_manipulatorow.begin();
        it!=lista_manipulatorow.end(); it++)
    {
        Lacze.DodajNazwePliku((*it).nazwa.c_str(),PzG::RR_Ciagly,6);
        Lacze.DodajNazwePliku((*it).nazwa.c_str(),PzG::RR_Punktowy,2);

    }
    return true;
 }
