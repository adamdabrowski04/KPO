#include "../inc/UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::Rozwiaz_LUP(void)
{
    Wektor<TYP, ROZMIAR> Wek_Y;
    for(int i=0;i<ROZMIAR;i++)
    {
    TYP SumaTmp;
        for(int j=0;j<i-1;j++)
            SumaTmp=LU.A[i][j]*Wek_Y[j];

        Wek_Y[i]=Wek_b[PI[i]]-SumaTmp;
    }
    for(int i=ROZMIAR-1;i>=0;i--)
    {
        TYP SumaTmp;
        for(int j=i+1;j<ROZMIAR;j++)
            SumaTmp=LU.A[i][j]*Wek_X[j];
        Wek_X[i]=(Wek_Y[i]-SumaTmp)/LU.A[i][i];
    }
    return Wek_X;
}


template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::Rozklad_LUP()
{
    LU=Mac_A.Transponuj();
    int kPrim;
    for(int i =0; i<ROZMIAR;i++)
    {
        PI[i]=i;
    }
    for(int k=0;k<ROZMIAR;k++)
    {
        TYP p(0);
        for(int i=k;i<ROZMIAR;i++)
        {
            if( ( (LU.A[i][k]<0)?-LU.A[i][k]:LU.A[i][k]) > p)
            {
                p=( (LU.A[i][k]<0)?-LU.A[i][k]:LU.A[i][k]);
                kPrim=i;
            }
        }
        if(p==0)
            cerr<<"Blad 1"<<endl;
        int tmpPI;
        tmpPI=PI[k];
        PI[k]=PI[kPrim];
        PI[kPrim]=tmpPI;
        for(int i=0;i<ROZMIAR;i++)
        {
            TYP tmp;
            tmp=LU.A[k][i];
            LU.A[k][i]=LU.A[kPrim][i];
            LU.A[kPrim][i]=tmp;
        }
        for(int i=k+1;i<ROZMIAR;i++)
        {
            LU.A[i][k]=LU.A[i][k] / LU.A[k][k];
            for(int j=k+1;j<ROZMIAR;j++)
            {
                LU.A[i][j]=LU.A[i][j] - LU.A[i][k] * LU.A[k][j];
            }
        }
    }
    return LU;

}

template <class TYP, int ROZMIAR>
TYP UkladRownanLiniowych<TYP, ROZMIAR>::ObliczBlad(Wektor<TYP, ROZMIAR> WekRozw)
{
    TYP blad;
    Wektor<TYP, ROZMIAR> WekBlad;
    WekBlad= Mac_A.Transponuj()*WekRozw;
    WekBlad= WekBlad-Wek_b;
    blad=WekBlad*WekBlad;
    return blad;
}


 template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown)
{
    Strm>>UklRown.Mac_A;
    Strm>>UklRown.Wek_b;
    return Strm;
}


