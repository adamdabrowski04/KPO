#include "../include/Manipulator.h"
#include "../include/ogniwo.h"
#include<string>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<cmath>

#define PI 3.14159265

using namespace std;
Manipulator::Manipulator()
{
    //ctor
}

Manipulator::~Manipulator()
{
    //dtor

}


bool Manipulator::WczytajDlugosciOgniw(string nazwa_pliku)
{
    double dlugosc;
    ifstream strumien_wejsciowy;
    strumien_wejsciowy.open(nazwa_pliku);
    if(!strumien_wejsciowy.is_open())
    {
        cerr<<"Nastapil blad podczas otwierania pliku z dluugosciami ogniw\n";
        return false;
    }
    liczba_ogniw =0;
    strumien_wejsciowy>>dlugosc;
    while(strumien_wejsciowy.peek()!=EOF)
    {
        manipulator_jeden.push_back(Ogniwo(dlugosc));
        cout<<(manipulator_jeden[0]).pobierz_dlugosc()<<endl;
        if(strumien_wejsciowy.good()) liczba_ogniw++;
        strumien_wejsciowy>>dlugosc;
        cout<<dlugosc<<"  "<<liczba_ogniw<<endl;
    }
    if(strumien_wejsciowy.fail()&&!strumien_wejsciowy.eof())
    {
        cerr<<"nastapil blad podczas wczytywania dlugosci"<<endl;
        strumien_wejsciowy.clear();
        strumien_wejsciowy.close();
        return false;
    }
    strumien_wejsciowy.close();
    return true;
}


bool Manipulator::WczytajKaty(string nazwa_pliku)
{
    double kat;
    ifstream strumien_wejsciowy;
    strumien_wejsciowy.open(nazwa_pliku);
    if(!strumien_wejsciowy.is_open())
    {
        cerr<<"Nastapil blad podczas otwierania pliku z katami ogniw\n";
        return false;
    }
    for(int i=0;strumien_wejsciowy.peek()!=EOF && i<liczba_ogniw; i++)
    {   strumien_wejsciowy>>kat;
        manipulator_jeden[i].ustaw_kat(kat);
    }

    if(strumien_wejsciowy.fail())
    {
        cerr<<"nastapil blad podczas wczytywania katow"<<endl;
        strumien_wejsciowy.clear();
        strumien_wejsciowy.close();
        return false;
    }
    strumien_wejsciowy>>kat;
    if(strumien_wejsciowy.peek()!=EOF)
    {
        cerr<<"W strumieniu nadal pozostaly katy do wczytania"<<endl;

    }
    strumien_wejsciowy.close();
    return true;
}
bool Manipulator::ZapiszWierzcholkiDoPliku(string nazwa_pliku) const
{
    double kat;
    ofstream strumien_wyjsciowy;
    strumien_wyjsciowy.open(nazwa_pliku);
    double wspolrzedna_x=zamocowanie_x;
    double wspolrzedna_y=zamocowanie_y;
    strumien_wyjsciowy<<wspolrzedna_x<<" "<<wspolrzedna_y<<endl;
    for(int i=0; i<liczba_ogniw;i++)
    {
        kat=0;
        for(int j=0;j<=i;j++)
        {
            kat+= manipulator_jeden[j].pobierz_kat();
        }
        wspolrzedna_x += (manipulator_jeden[i].pobierz_dlugosc() )* cos(kat*PI/180);
        wspolrzedna_y += (manipulator_jeden[i].pobierz_dlugosc() )* sin(kat*PI/180);
        strumien_wyjsciowy<<wspolrzedna_x<<" "<<wspolrzedna_y<<endl;
    }
    strumien_wyjsciowy.close();
    return true;
}
void Manipulator::WypiszWierzcholkiNaEkran(void) const
{
    double kat;
    double wspolrzedna_x=zamocowanie_x;
    double wspolrzedna_y=zamocowanie_y;
    cout<<"Postura:"<<endl;
    for(int i=0; i<liczba_ogniw;i++)
    {
        kat=0;
        for(int j=0;j<=i;j++)
        {
            kat+= manipulator_jeden[j].pobierz_kat();
        }
        wspolrzedna_x += (manipulator_jeden[i].pobierz_dlugosc() )* cos(kat*PI/180);
        wspolrzedna_y += (manipulator_jeden[i].pobierz_dlugosc() )* sin(kat*PI/180);
        cout<<" q"<<i<<" = "<<manipulator_jeden[i].pobierz_kat();
        cout<<"    Przegub_"<<i<<":  "<<wspolrzedna_x<<" "<<wspolrzedna_y<<endl;
    }
    cout<<"\n\n"<<endl;
}

void Manipulator::zapisz_wierzcholki_do_tablicy(double* wspolrzedna_x, double* wspolrzedna_y)
{
    double kat;
    wspolrzedna_x[0]=zamocowanie_x;
    wspolrzedna_y[0]=zamocowanie_y;
    for(int i=0; i<liczba_ogniw;i++)
    {
        kat=0;
        for(int j=0;j<=i;j++)
        {
            kat+= manipulator_jeden[j].pobierz_kat();
        }
        wspolrzedna_x[i+1] =wspolrzedna_x[i] + (manipulator_jeden[i].pobierz_dlugosc() )* cos(kat*PI/180);
        wspolrzedna_y[i+1] =wspolrzedna_y[i] + (manipulator_jeden[i].pobierz_dlugosc() )* sin(kat*PI/180);
    }
}


void Manipulator::UstawPozycjeStartowa(void)
{
 manipulator_jeden[0].ustaw_kat(90);
 for(int i=1; i<liczba_ogniw;i++)
 {
    manipulator_jeden[i].ustaw_kat(0);
 }
}

void Manipulator::WypiszKonfiguracje()
{
    cout<<"Konfiguracja:"<<endl;
    for(int i=0; i<liczba_ogniw; i++)
        cout<<" Dlugosc ogniwa_"<<i<<":  "<<manipulator_jeden[i].pobierz_dlugosc()<<endl;
    cout<<"\n\n"<<endl;

}


bool Manipulator::czy_kolizja_manipulatora_z_odcinkiem(double x_pierwszy, double y_pierwszy, double x_drugi, double y_drugi )
{
  int liczba_wspolrzednych=this->liczba_ogniw + 1;
  double *wierzcholki_x=new double[liczba_wspolrzednych];
  double *wierzcholki_y=new double[liczba_wspolrzednych];
  this->zapisz_wierzcholki_do_tablicy(wierzcholki_x, wierzcholki_y);
  double Wg;
  Wg=x_pierwszy-x_drugi;
  double a_1 = (y_pierwszy-y_drugi)/Wg;
  double b_1 = (x_pierwszy*y_drugi-x_drugi*y_pierwszy)/Wg;
  double a_2, b_2;
  for(int i=0; i<liczba_wspolrzednych-1; i++)
  {
    Wg=wierzcholki_x[i]-wierzcholki_x[i+1];
    a_2 = (wierzcholki_y[i]-wierzcholki_y[i+1])/Wg;
    b_2 = (wierzcholki_x[i]*wierzcholki_y[i+1]-wierzcholki_x[i+1]*wierzcholki_y[i])/Wg;
    if(static_cast<int>(a_1*1000)==static_cast<int>(a_2*1000) )  //moze byc problem związaony z porównywaniem liczb typu double
    {
      if(static_cast<int>(b_1*1000)==static_cast<int>(b_2*1000) )
      {
        if(
            ( czy_punkt_na_odcinku(x_pierwszy,wierzcholki_x[i],wierzcholki_x[i+1])&&czy_punkt_na_odcinku(y_pierwszy,wierzcholki_y[i],wierzcholki_y[i+1]) ) ||
            ( czy_punkt_na_odcinku(x_drugi,wierzcholki_x[i],wierzcholki_x[i+1])&&czy_punkt_na_odcinku(y_drugi,wierzcholki_y[i],wierzcholki_y[i+1]) )
          ) return true;

      }
    }
    double x_przeciecia=(b_2-b_1)/(a_1-a_2);
    double y_przeciecia=(b_2-a_2*b_1)/(a_1-a_2);
    if( czy_punkt_na_odcinku(x_przeciecia,wierzcholki_x[i],wierzcholki_x[i+1])&&czy_punkt_na_odcinku(y_przeciecia,wierzcholki_y[i],wierzcholki_y[i+1])&&
        czy_punkt_na_odcinku(x_przeciecia,x_pierwszy,x_drugi)&&czy_punkt_na_odcinku(y_przeciecia,y_pierwszy,y_drugi)
      )
      return true;
  }
  return false;
}

bool czy_kolizja_manipulatora_z_manipulatorem(Manipulator pierwszy,Manipulator drugi)
{
  int liczba_wspolrzednych=drugi.liczba_ogniw + 1;
  double *wierzcholki_x=new double[liczba_wspolrzednych];
  double *wierzcholki_y=new double[liczba_wspolrzednych];
  drugi.zapisz_wierzcholki_do_tablicy(wierzcholki_x, wierzcholki_y);
  for(int i=0; i<liczba_wspolrzednych-1; i++)
  {
    if(pierwszy.czy_kolizja_manipulatora_z_odcinkiem(wierzcholki_x[i],wierzcholki_y[i],wierzcholki_x[i+1],wierzcholki_y[i+1]) )
      return true;
  }
  return false;
}

bool czy_punkt_na_odcinku(double sprawdzany, double pierwszy, double drugi)
{
  if( (sprawdzany>=pierwszy&&sprawdzany<=drugi) || (sprawdzany>=drugi&&sprawdzany<=pierwszy) )
    return true;
  else
    return false;
}

