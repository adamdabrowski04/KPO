#include "../inc/Macierz.hh"
#include "../inc/Wektor.hh"
<<<<<<< HEAD

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz()
=======
#include "../inc/rozmiar.h"
template <class TYP>
Macierz<TYP>::Macierz()
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{

}

<<<<<<< HEAD
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR>::~Macierz()
=======
template <class TYP>
Macierz<TYP>::~Macierz()
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{

}

<<<<<<< HEAD
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &Mac)
=======
template <class TYP>
std::istream& operator >> (std::istream &Strm, Macierz<TYP> &Mac)
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Strm>>Mac.A[i];
    }
    return Strm;
}

<<<<<<< HEAD
template <class TYP, int ROZMIAR>
std::ostream& operator<<(std::ostream &Strm, Macierz<TYP, ROZMIAR> &Mac)
=======
template <class TYP>
std::ostream& operator<<(std::ostream &Strm, Macierz<TYP> &Mac)
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{
        for(unsigned int i=0;i<ROZMIAR;i++)
        {
            Strm<<Mac.A[i]<<endl;
        }
    return Strm;
}
<<<<<<< HEAD
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator*(Wektor<TYP, ROZMIAR> Wek)
{
    Wektor<TYP, ROZMIAR> Rozw;
=======
template <class TYP>
Wektor<TYP> Macierz<TYP>::operator*(Wektor<TYP> Wek)
{
    Wektor<TYP> Rozw;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    for(int i=0; i<ROZMIAR;i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Rozw[i]=A[i][j]*Wek[j]+Rozw[i];
        }
    }
    return Rozw;
}


<<<<<<< HEAD
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::Transponuj(void)
{
    Macierz<TYP, ROZMIAR> Tmp;
=======
template <class TYP>
Macierz<TYP> Macierz<TYP>::Transponuj(void)
{
    Macierz<TYP> Tmp;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    for(int i =0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
        {
            Tmp.A[i][j]=A[j][i];
        }
    return Tmp;
}
