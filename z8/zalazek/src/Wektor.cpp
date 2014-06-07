#include "../inc/Wektor.hh"
using namespace std;

template <class TYP>
<<<<<<< HEAD
Wektor<TYP>::Wektor(int ROZMIAR):ROZMIAR(ROZMIAR)
{
=======
Wektor<TYP>::Wektor()
{

>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    pTab=new TYP[ROZMIAR];
}

template <class TYP>
Wektor<TYP>::~Wektor()
{
<<<<<<< HEAD
=======
    //cout<<"Ilosc Wywolan wypisana z destruktora "<<iloscWywolan<<endl;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    delete[](pTab);
    pTab=0;
}

template <class TYP>
<<<<<<< HEAD
Wektor<TYP>::Wektor(Wektor & Wzor):ROZMIAR(Wzor.ROZMIAR)
=======
Wektor<TYP>::Wektor(Wektor & Wzor)
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
{
    pTab = new TYP[ROZMIAR];
    for(int i=0;i<ROZMIAR;i++)
    {
        pTab[i]=Wzor.pTab[i];
    }
<<<<<<< HEAD
=======
    iloscWywolan++;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
}

template <class TYP>
Wektor<TYP>& Wektor<TYP>::operator=( const Wektor<TYP> &Wzor)
{
<<<<<<< HEAD
   //pTab= new TYP[ROZMIAR];
   //ROZMIAR=Wzor.ROZMIAR;
=======
    //pTab= new TYP[ROZMIAR];
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    for(int i=0;i<ROZMIAR;i++)
    {
        this->pTab[i]=Wzor.pTab[i];
    }
    return *this;
}

template <class TYP>
std::istream& operator >> (std::istream &Strm, Wektor<TYP> &Wek)
{
<<<<<<< HEAD
    for(unsigned int i=0;i<Wek.ROZMIAR;i++)
    {
        Strm>>Wek.pTab[i];
=======
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        TYP tmp;
        Strm>>tmp;
        //Wek.pTab.emplace_back(tmp);
        Wek.pTab[i]=tmp;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    }
    return Strm;
}

template <class TYP>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP> &Wek)
{
<<<<<<< HEAD
    for(unsigned int i=0;i<Wek.ROZMIAR;i++)
=======
    for(unsigned int i=0;i<ROZMIAR;i++)
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    {
        Strm<<Wek.pTab[i]<<" ";
    }
    return Strm;
}

template <class TYP>
inline TYP& Wektor<TYP>::operator[](unsigned int i)
{
    return pTab[i];
}

template <class TYP>
Wektor<TYP> Wektor<TYP>::operator+(Wektor<TYP> Drugi)const
{
<<<<<<< HEAD
    Wektor<TYP> Wynik(ROZMIAR);
=======
    Wektor<TYP> Wynik;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]+Drugi[i];
    }
    return Wynik;
}

template <class TYP>
Wektor<TYP> Wektor<TYP>::operator-(Wektor<TYP> Drugi)const
{
<<<<<<< HEAD
    Wektor<TYP> Wynik(ROZMIAR);
=======
    Wektor<TYP> Wynik;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]-Drugi[i];
    }
    return Wynik;
}

template <class TYP>
TYP Wektor<TYP>::operator*(Wektor<TYP> Drugi)const
{
    TYP Wynik=0;
    for(unsigned int i=0;i<ROZMIAR;i++)
    {
        Wynik=pTab[i]*Drugi[i]+Wynik;
    }
    return Wynik;
}

template <class TYP>
Wektor<TYP> Wektor<TYP>::operator*(TYP Wspolczynnik)const
{
    Wektor<TYP> Wynik(ROZMIAR);
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]*Wspolczynnik;
    }
<<<<<<< HEAD
=======
    return Wynik;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
}

template <class TYP>
Wektor<TYP> Wektor<TYP>::operator/(TYP Wspolczynnik)const
{
    Wektor<TYP> Wynik(ROZMIAR);
    for (unsigned int i =0; i<ROZMIAR;i++)
    {
        Wynik[i]=pTab[i]/Wspolczynnik;
<<<<<<< HEAD
    }
=======

    }
    return Wynik;
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
}
