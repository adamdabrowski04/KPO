#include "../inc/RozpoznajProblem.hh"
#include <iostream>
#include <string>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"

using namespace std;

TypProblemu RozpoznajProblem(int argc, char* argv[],int &Rozmiar)
{
    TypProblemu WczytanyTypProblemu;
    if(argc!=5)
    {
        cerr<<"Bledna ilosc opcji"<<endl;
        return TP_blad;
    }

    if(argv[1][1]=='t')
    {
        if(argv[2][0]=='z')
            WczytanyTypProblemu=TP_zespolone;
        else if(argv[2][0]=='r')
            WczytanyTypProblemu=TP_double;
        else
            return TP_blad;

    }
    else if(argv[3][1]=='t')
    {
        if(argv[4][0]=='z')
            WczytanyTypProblemu=TP_zespolone;
        else if(argv[4][0]=='r')
            WczytanyTypProblemu=TP_double;
        else
            return TP_blad;
    }
    else
        return TP_blad;


    if(argv[1][1]=='r')
    {
        Rozmiar=argv[2][0]-'0';
    }
    else if(argv[3][1]=='r')
    {
        Rozmiar=argv[4][0]-'0';
    }
    else
        return TP_blad;

    if(Rozmiar>ROZMIAR_MAX||Rozmiar<ROZMIAR_MIN)
        return TP_blad;


    return WczytanyTypProblemu;
}

void RozwiazProblem_double(const int Rozmiar)
{

    Wektor<double>  Wek_Rozw(Rozmiar);
    UkladRownanLiniowych<double> A(Rozmiar);
    double blad;
    cin>>A;
    cout<<"MaicierzA^T\n"<<A.Mac_A;
    cout<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    cout<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    cout<<"Rozwiazanie x= ";
    for(int i =1; i<=Rozmiar; i++)
        cout<<"x"<<i<<" ";
    cout<<endl;
    cout<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    cout<<"Dlugosc wektora Bledu:  "<<blad<<endl;

}

void RozwiazProblem_zespolone(const int Rozmiar)
{

    Wektor<Zespolona>  Wek_Rozw(Rozmiar);
    UkladRownanLiniowych<Zespolona> A(Rozmiar);
    Zespolona blad;
    cin>>A;
    cout<<"MaicierzA^T\n"<<A.Mac_A;
    cout<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    cout<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    cout<<"Rozwiazanie x= ";
    for(int i =1; i<=Rozmiar; i++)
        cout<<"x"<<i<<" ";
    cout<<endl;
    cout<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    cout<<"Dlugosc wektora Bledu:  "<<blad<<endl;

}

