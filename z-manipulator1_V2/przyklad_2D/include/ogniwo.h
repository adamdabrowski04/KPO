#ifndef OGNIWO_H
#define OGNIWO_H
#include <vector>

using namespace std;
class Ogniwo
{
    public:

        void ustaw_kat(double);
    /*!
     *
     *\brief Akcesor zmiennej kat
     */
        double pobierz_kat()const;
    /*!
     *
     *\brief Akcesor zmiennej kat
     */

        void ustaw_dlugosc(double);
    /*!
     *
     *\brief Akcesor zmiennej dlugosc
     */
        double pobierz_dlugosc()const;
    /*!
     *
     *\brief Akcesor zmiennej dlugosc
     */


        double wspolrzedna_x()const;
    /*!
     *
     *\brief Wylicza i zwraca wspolrzedna x wiercholka w lokalnym ukladzie odniesienia
     *
     *\pre
     *BRAK
     *
     *\post
     *Oblicza wspolrzedna x wierzcholka
     *
     *
     *\return
     * Wspolrzedna x wiercholka danego ogniwa
     */
        double wspolrzedna_y()const;
    /*!
     *
     *\brief Wylicza i zwraca wspolrzedna y wiercholka w lokalnym ukladzie odniesienia
     *
     *\pre
     *BRAK
     *
     *\post
     *Oblicza wspolrzedna y wierzcholka
     *
     *
     *\return
     * Wspolrzedna y wiercholka danego ogniwa
     */

        Ogniwo(double =0, double =0);
        /*!
        *
        *\brief Konstruktor klasy Ogniwo
        */
    protected:

    private:
    double dlugosc;
    double kat;

};



#endif // OGNIWO_H
