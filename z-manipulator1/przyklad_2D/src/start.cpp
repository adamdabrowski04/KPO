#include <iostream>
#include <iomanip>
<<<<<<< HEAD
#include "../inc/lacze_do_gnuplota.hh"
#include "../include/Manipulator.h"
#include<string>
#include<unistd.h>
=======
#include<unistd.h>
#include "lacze_do_gnuplota.hh"


>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
using namespace std;



<<<<<<< HEAD
int main(int argc, char* argv[])
=======
int main()
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;

<<<<<<< HEAD
  Manipulator irb1400;
  irb1400.WczytajDlugosciOgniw(argv[1]);
  irb1400.UstawPozycjeStartowa();
  irb1400.ZapiszWierzcholkiDoPliku("irb1400.dat");
  irb1400.WypiszKonfiguracje();
  Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Ciagly,6);
  Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Punktowy,2);
Lacze.DodajNazwePliku("cos.dat",PzG::RR_Ciagly,6);
  Lacze.DodajNazwePliku("cos.dat",PzG::RR_Punktowy,2);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-200,200);
  Lacze.UstawZakresX(-250,250);
  Lacze.Rysuj();
  sleep(2);
  for(int i=2; i<argc; i++)
  {
    Lacze.UsunOstatniaNazwe();
    irb1400.WczytajKaty(argv[i]);
    irb1400.ZapiszWierzcholkiDoPliku("irb1400.dat");
    Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Ciagly,6);
    Lacze.DodajNazwePliku("irb1400.dat",PzG::RR_Punktowy,2);
    Lacze.Rysuj();
    cout<<"Postura wczytana z "<<argv[i]<<"\n"<<endl;
    irb1400.WypiszWierzcholkiNaEkran();
    sleep(1);
  }
=======

  Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Ciagly,6);
 // Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Punktowy,2);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-5,35);
  Lacze.UstawZakresX(-35,35);

    Lacze.Rysuj();

  sleep(1);

  Lacze.UsunOstatniaNazwe();
  Lacze.DodajNazwePliku("manipulator2.dat",PzG::RR_Ciagly,6);
  Lacze.Rysuj();
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2

  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
