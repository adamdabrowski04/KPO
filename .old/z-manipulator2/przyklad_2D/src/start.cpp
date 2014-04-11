#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"


using namespace std;



int main() 
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;


  Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Ciagly,6);
  Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Punktowy,2);

  Lacze.DodajNazwePliku("przeszkoda1.dat",PzG::RR_Ciagly,5);
  Lacze.DodajNazwePliku("przeszkoda2.dat",PzG::RR_Ciagly,5);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-5,35);
  Lacze.UstawZakresX(-35,35);
  Lacze.Rysuj(); 
   
  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
