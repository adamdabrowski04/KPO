#include "../inc/Macierz.hh"

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz()
{

}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR>::~Macierz()
{

}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &Mac)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm>>Mac.A[i];
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP, ROZMIAR> &Mac)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm<<Mac.A[i]<<endl;
    }
    return Strm;
}

