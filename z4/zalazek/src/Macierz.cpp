#include "../inc/Macierz.hh"

template<class TYP>
Macierz<TYP>::Macierz()
{

}

template<class TYP>
Macierz<TYP>::~Macierz()
{

}

template<class TYP>
std::istream& operator >> (std::istream &Strm, Macierz<TYP> &Mac)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm>>Mac.A[i];
    }
    return Strm;
}

template<class TYP>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP> &Mac)
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm<<Mac.A[i]<<endl;
    }
    return Strm;
}
