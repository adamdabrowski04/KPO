#include "../include/ogniwo.h"
#include<cmath>

Ogniwo::Ogniwo(double dlugosc, double kat)
        : dlugosc(dlugosc), kat(kat)
{
    ;
}


void Ogniwo::
ustaw_kat(double wartosc)
{
    this->kat=wartosc;
}
double Ogniwo::pobierz_kat()const
{
    return kat;
}
void Ogniwo::ustaw_dlugosc(double wartosc)
{
    dlugosc=wartosc;
}
double Ogniwo::pobierz_dlugosc()const
{
    return dlugosc;
}

double Ogniwo::wspolrzedna_x()const
{
    return dlugosc*cos(kat);
}
double Ogniwo::wspolrzedna_y()const
{
    return dlugosc*sin(kat);
}

