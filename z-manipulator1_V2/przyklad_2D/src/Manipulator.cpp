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
    double wspolrzedna_x=0;
    double wspolrzedna_y=0;
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


