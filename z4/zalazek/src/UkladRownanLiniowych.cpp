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
            SumaTmp=Mac_A.A[i][j]*Wek_Y[j];

        Wek_Y[i]=Wek_b[PI[i]]-SumaTmp;
    }
    for(int i=ROZMIAR-1;i>=0;i--)
    {
        TYP SumaTmp;
        for(int j=i+1;j<ROZMIAR;j++)
            SumaTmp=Mac_A.A[i][j]*Wek_X[j];
        Wek_X[i]=(Wek_Y[i]-SumaTmp)/Mac_A.A[i][i];
    }
    return Wek_X;
}


template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::Rozklad_LUP()
{
    //Mac_A;
    int kPrim;
    for(int i =0; i<ROZMIAR;i++)
    {
    cout<<"aa"<<endl;
        PI[i]=i;
    }
    for(int k=0;k<ROZMIAR;k++)
    {
    cout<<"bb"<<endl;
        int p=0;
        for(int i=k;i<ROZMIAR;i++)
        {
            if( ( (Mac_A.A[i][k]<0)?-Mac_A.A[i][k]:Mac_A.A[i][k]) > p)
            {
                p=( (Mac_A.A[i][k]<0)?-Mac_A.A[i][k]:Mac_A.A[i][k]);
                kPrim=i;
            }
        }
        if(p==0)
            cerr<<"Blad 1"<<endl;
        cout<<"cc"<<kPrim<<endl;
        int tmpPI;
        tmpPI=PI[k];
        PI[k]=PI[kPrim];
        PI[kPrim]=tmpPI;
        for(int i=0;i<ROZMIAR;i++)
        {
            TYP tmp;
            tmp=Mac_A.A[k][i];
            Mac_A.A[k][i]=Mac_A.A[kPrim][i];
            Mac_A.A[kPrim][i]=tmp;
        }
        for(int i=k+1;i<ROZMIAR;i++)
        {
            Mac_A.A[i][k]=Mac_A.A[i][k] / Mac_A.A[k][k];
            for(int j=k+1;j<ROZMIAR;j++)
            {
                Mac_A.A[i][j]=Mac_A.A[i][j] - Mac_A.A[i][k] * Mac_A.A[k][j];
            }
        }
    }
     cout<<"dd"<<endl;
    return Mac_A;

}
