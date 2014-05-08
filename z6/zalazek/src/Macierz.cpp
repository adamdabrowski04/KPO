#include "../inc/Macierz.hh"
#include "../inc/Wektor.hh"

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
std::ostream& operator<<(std::ostream &Strm, Macierz<TYP, ROZMIAR> &Mac)
{
        for(unsigned int i=0;i<ROZMIAR;i++)
        {
            Strm<<Mac.A[i]<<endl;
        }
    return Strm;
}
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator*(Wektor<TYP, ROZMIAR> Wek)
{
    Wektor<TYP, ROZMIAR> Rozw;
    for(int i=0; i<ROZMIAR;i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Rozw[i]=A[i][j]*Wek[j]+Rozw[i];
        }
    }
    return Rozw;
}


template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::Transponuj(void)
{
    Macierz<TYP, ROZMIAR> Tmp;
    for(int i =0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
        {
            Tmp.A[i][j]=A[j][i];
        }
    return Tmp;
}
