#include "../inc/RozpoznajProblem.hh"
#include <iostream>
#include <string>
#include "../src/Wektor.cpp"
#include "../src/Macierz.cpp"
#include "../src/UkladRownanLiniowych.cpp"
#include "../inc/rozmiar.h"
#include "../inc/zespolone.hh"
#include <unistd.h>
#include <fstream>
using namespace std;

//TypProblemu RozpoznajProblem(int argc, char* argv[],int &Rozmiar)
//{
//    TypProblemu WczytanyTypProblemu;
//    if(argc!=5)
//    {
//        cerr<<"Bledna ilosc opcji"<<endl;
//        return TP_blad;
//    }
//
//    if(argv[1][1]=='t')
//    {
//        if(argv[2][0]=='z')
//            WczytanyTypProblemu=TP_zespolone;
//        else if(argv[2][0]=='r')
//            WczytanyTypProblemu=TP_double;
//        else
//            return TP_blad;
//
//    }
//    else if(argv[3][1]=='t')
//    {
//        if(argv[4][0]=='z')
//            WczytanyTypProblemu=TP_zespolone;
//        else if(argv[4][0]=='r')
//            WczytanyTypProblemu=TP_double;
//        else
//            return TP_blad;
//    }
//    else
//        return TP_blad;
//
//
//    if(argv[1][1]=='r')
//    {
//        Rozmiar=argv[2][0]-'0';
//    }
//    else if(argv[3][1]=='r')
//    {
//        Rozmiar=argv[4][0]-'0';
//    }
//    else
//        return TP_blad;
//
//    if(Rozmiar>ROZMIAR_MAX||Rozmiar<ROZMIAR_MIN)
//        return TP_blad;
//
//
//    return WczytanyTypProblemu;
//}

void RozwiazProblem_double(const int Rozmiar, istream &StrmWe, ostream &StrmWy)
{

    Wektor<double>  Wek_Rozw;
    UkladRownanLiniowych<double> A;
    double blad;
    StrmWe>>A;
    StrmWy<<"MaicierzA^T\n"<<A.Mac_A;
    StrmWy<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    StrmWy<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    StrmWy<<"Rozwiazanie x= ";
    for(int i =1; i<=Rozmiar; i++)
        StrmWy<<"x"<<i<<" ";
    StrmWy<<endl;
    StrmWy<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    StrmWy<<"Dlugosc wektora Bledu:  "<<blad<<endl;

}

void RozwiazProblem_zespolone(const int Rozmiar, istream &StrmWe, ostream &StrmWy)
{

    Wektor<Zespolona>  Wek_Rozw;
    UkladRownanLiniowych<Zespolona> A;
    Zespolona blad;
    StrmWe>>A;
    StrmWy<<"MaicierzA^T\n"<<A.Mac_A;
    StrmWy<<"Wektor wyrazow wolnych b:\n"<<A.Wek_b<<endl;
    A.Rozklad_LUP();
    StrmWy<<"MaicierzLU\n"<<A.LU;
    Wek_Rozw=A.Rozwiaz_LUP();
    StrmWy<<"Rozwiazanie x= ";
    for(int i =1; i<=Rozmiar; i++)
        StrmWy<<"x"<<i<<" ";
    StrmWy<<endl;
    StrmWy<<"( "<<A.Wek_X<<" )"<<endl;
    blad= A.ObliczBlad(Wek_Rozw);
    StrmWy<<"Dlugosc wektora Bledu:  "<<blad<<endl;

}

TypProblemu RozpoznajProblem(int argc, char* argv[],int &Rozmiar,string &NazwaWe,string &NazwaWy)
{
    TypProblemu WczytanyTypProblemu;
    int c;
    while ((c = getopt (argc, argv, "t:r:i:o:")) != -1)
         switch (c)
           {
           case 't':
                if(*optarg=='z')
                    WczytanyTypProblemu=TP_zespolone;
                else if(*optarg=='r')
                    WczytanyTypProblemu=TP_double;
                else
                    return TP_blad;
             break;
           case 'r':
             Rozmiar=*optarg-'0';  // TODO (Adam#3#): poprawić sposób rozpoznawania liczb
             break;
           case 'i':
           NazwaWe=optarg;
           break;
           case 'o':
           NazwaWy=optarg;
           break;
           case '?':
             if (optopt == 'r')
               cerr<<"Option r requires an argument.\n"<<endl;
             else if (optopt=='t')
               cerr<<"Option t requires an argument.\n"<<endl;
             else
               cerr<<"Unknown option character"<<endl;
             return TP_blad;
           default:
             return TP_blad;
           }

    if(Rozmiar>ROZMIAR_MAX||Rozmiar<ROZMIAR_MIN)
       return TP_blad;
    return WczytanyTypProblemu;
}
