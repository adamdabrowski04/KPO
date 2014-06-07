#include "../inc/Macierz.hh"
#include "../inc/Wektor.hh"

template <class TYP>
Macierz<TYP>::Macierz(int ROZMIAR):ROZMIAR(ROZMIAR),A(ROZMIAR)
{

}

template <class TYP>
Macierz<TYP>::~Macierz()
{

}

template <class TYP>
std::istream& operator >> (std::istream &Strm, Macierz<TYP> &Mac)
{
    for(unsigned int i=0;i<Mac.ROZMIAR;i++)
    {
        Strm>>Mac.A[i];
    }
    return Strm;
}

template <class TYP>
std::ostream& operator<<(std::ostream &Strm, Macierz<TYP> &Mac)
{
        for(unsigned int i=0;i<Mac.ROZMIAR;i++)
        {
            Strm<<Mac.A[i]<<endl;
        }
    return Strm;
}
template <class TYP>
Wektor<TYP> Macierz<TYP>::operator*(Wektor<TYP> Wek)
{
    Wektor<TYP> Rozw(ROZMIAR);
    for(int i=0; i<ROZMIAR;i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Rozw[i]=A[i][j]*Wek[j]+Rozw[i];
        }
    }
    return Rozw;
}


template <class TYP>
Macierz<TYP> Macierz<TYP>::Transponuj(void)
{
    Macierz<TYP> Tmp(ROZMIAR);
    for(int i =0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
        {
            Tmp.A[i][j]=A[j][i];
        }
    return Tmp;
}
