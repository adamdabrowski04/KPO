#include "../inc/Wektor.hh"
using namespace std;

template<class TYP>
Wektor<TYP>::Wektor()
{
    pTab=new TYP[ROZMIAR];
}

template<class TYP>
Wektor<TYP>::~Wektor()
{
    delete[](pTab);
}

template<class TYP>
std::istream& operator >> (std::istream &Strm, Wektor<TYP> &Wek)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm>>Wek.pTab[i];
    }
    return Strm;
}

template<class TYP>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP> &Wek)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm<<Wek.pTab[i]<<" ";
    }
    return Strm;
}

template<class TYP>
inline TYP& Wektor<TYP>::operator[](unsigned int i)const
{
    return pTab[i];
}

template<class TYP>
Wektor<TYP> Wektor<TYP>::operator+(Wektor<TYP> Drugi)const
{
    Wektor<TYP> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]+Drugi[i];
    }
    return Wynik;
}

template<class TYP>
Wektor<TYP> Wektor<TYP>::operator-(Wektor<TYP> Drugi)const
{
    Wektor<TYP> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]-Drugi[i];
    }
    return Wynik;
}

template<class TYP>
TYP Wektor<TYP>::operator*(Wektor<TYP> Drugi)const
{
    TYP Wynik=0;
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Wynik+=pTab[i]*Drugi[i];
    }
    return Wynik;
}

template<class TYP>
Wektor<TYP> Wektor<TYP>::operator*(TYP Wspolczynnik)const
{
    Wektor<TYP> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]*Wspolczynnik;
    }
}

template<class TYP>
Wektor<TYP> Wektor<TYP>::operator/(TYP Wspolczynnik)const
{
    Wektor<TYP> Wynik;
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]/Wspolczynnik;
    }
}
