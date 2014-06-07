#include <iostream>
#include <iomanip>
#include "../inc/lacze_do_gnuplota.hh"
#include "../include/Manipulator.h"
#include "../include/Scena.h"
#include<string>
#include<unistd.h>
using namespace std;



int main(int argc, char* argv[])
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;
  Scena fabryka;
  Manipulator irb1400;
  if(!irb1400.WczytajDlugosciOgniw(argv[1])) return 1;
  fabryka.WczytajScene(argv[2]);
  irb1400.UstawPozycjeStartowa();
  irb1400.ZapiszWierzcholkiDoPliku("irb1400.dat");
  irb1400.WypiszKonfiguracje();
 // fabryka.RysujScene(Lacze);

      //for(vector<Manipulator>::iterator it =fabryka.lista_manipulatorow.begin();
        //it!=fabryka.lista_manipulatorow.end(); it++)
    for(unsigned int i=0; i<fabryka.lista_manipulatorow.size();i++)
    {
    //cout<<(*it).nazwa<<endl;
        Lacze.DodajNazwePliku( (fabryka.lista_manipulatorow[i]).nazwa.c_str(),PzG::RR_Ciagly,6);
        Lacze.DodajNazwePliku((fabryka.lista_manipulatorow[i]).nazwa.c_str(),PzG::RR_Punktowy,2);

    }
  Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Ciagly,6);
  Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Punktowy,2);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-200,200);
  Lacze.UstawZakresX(-250,250);
  Lacze.Rysuj();
  sleep(2);
  for(int i=2; i<argc; i++)
  {
    Lacze.UsunOstatniaNazwe();
    if(!irb1400.WczytajKaty(argv[i+1])) return 1;
    irb1400.ZapiszWierzcholkiDoPliku("irb1400.dat");
    Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Ciagly,6);
    Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Punktowy,2);
    Lacze.Rysuj();
    cout<<"Postura wczytana z "<<argv[i]<<"\n"<<endl;
    irb1400.WypiszWierzcholkiNaEkran();
    sleep(1);
  }

  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
