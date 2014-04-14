#include "../inc/Wektor.hh"
using namespace std;

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor()
{
    pTab=new TYP[ROZMIAR];
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::~Wektor()
{
    delete[](pTab);
    pTab=0;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(Wektor & Wzor)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        pTab[i]=Wzor.pTab[i];
    }
}
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>& Wektor<TYP, ROZMIAR>::operator=(Wektor<TYP, ROZMIAR> &Wzor)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        pTab[i]=Wzor.pTab[i];
    }
    return Wzor;
}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm>>Wek.pTab[i];
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm<<Wek.pTab[i]<<" ";
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
inline TYP& Wektor<TYP, ROZMIAR>::operator[](unsigned int i)
{
    return pTab[i];
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator+(Wektor<TYP, ROZMIAR> Drugi)const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]+Drugi[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator-(Wektor<TYP, ROZMIAR> Drugi)const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]-Drugi[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
TYP Wektor<TYP, ROZMIAR>::operator*(Wektor<TYP, ROZMIAR> Drugi)const
{
    TYP Wynik=0;
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Wynik+=pTab[i]*Drugi[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator*(TYP Wspolczynnik)const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]*Wspolczynnik;
    }
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator/(TYP Wspolczynnik)const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]/Wspolczynnik;
    }
}
