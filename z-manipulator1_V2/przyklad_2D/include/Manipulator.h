#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include<vector>
#include<string>
#include "../include/ogniwo.h"
using namespace std;
class Manipulator: public ZlozonyObiektGeometryczny
{
    public:
    virtual const char* TypPrzeszkoday(){return"Manipulator";}

        bool WczytajDlugosciOgniw(string nazwa_pliku);
    /*!
     *
     *\brief Wczytuje dlugosci poszczegolnych ogniw manipulatora
     *
     *\pre
     *BRAK
     *
     *\post
     *Wczytuja dlugosci poszczegolnych ogniw
     *
     *\param[in] nazwa_pliku - nnazwa pliku z któregczyjemyy dane;
     *
     *\return
     *true-wczystko się powiedzie
     *false - nie uda sie wczytac
     */
        bool WczytajKaty(string);
     /*!
     *
     *\brief Wczytuje katy kolejnych ogniw
     *
     *\pre
     *W pliku nie moze byc bledow ///TODO (1#Adam#) naprawic to
     *
     *\post
     *Zapisuje w odpowiedniej zmiennej poszczegolne katy
     *
     *\param[in] nazwa_pliku - nazwa pliku z którego wczytujemy dane;
     *
     *\return
     *true - wszystko się powiedzie
     *false - nie uda sie wczytac
     */
        bool ZapiszWierzcholkiDoPliku(string) const;
    /*!
     *
     *\brief Zapisuje wspolrzedne wierzcholkow w pliku o podanej nazwie
     *
     *\pre
     *BRAK
     *
     *\post
     *dostajemy plik z zapisanymi wspolrzednymi x i y w 2 kolumnach
     *
     *\param[in] nazwa_pliku - nazwa pliku do którego wypisujemy dane;
     *
     *\return
     *true - wszystko się powiedzie
     *false - nie uda sie wczytac
     */
        void WypiszWierzcholkiNaEkran(void) const;
    /*!
     *
     *\brief Wypisuje nr wiercholka kot nachylenia i jego wspolrzedne
     *
     *\pre
     *BRAK
     *
     */
        void UstawPozycjeStartowa(void);
    /*!
     *
     *\brief Ustawia pozycje wspolrzedne startowe dla manipulatora
     *
     *\pre
     *BRAK
     *
     */
        void WypiszKonfiguracje();
    /*!
     *
     *\brief Wypisuje dlugosci kolejnych ogniw manioulatora
     *
     *\pre
     *BRAK
     *
     */
        Manipulator();
         ~Manipulator();
    protected:
    private:
    /*!
     *
     *\brief Zmienna w której przechowujemy dane na temat kolejnych ogniw
     *
     */
        vector<Ogniwo> manipulator_jeden;
        int liczba_ogniw;
};


#endif // MANIPULATOR_H
