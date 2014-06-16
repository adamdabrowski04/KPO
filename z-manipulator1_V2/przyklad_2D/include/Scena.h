#ifndef SCENA_H
#define SCENA_H
#include "../include/Wielobok.h"
#include "../include/Manipulator.h"
#include "../inc/lacze_do_gnuplota.hh"
#include "../include/ZlozonyObiektGeometryczny.h"
#include<vector>
using namespace std;

class Scena
{
    public:
    /*!
     *
     *\brief Sprawdza czy na scenie wystepuja kolizje
     *
     *
     *\pre
     *BRAK
     *
     *\post
     *sprawdza czy na scenie wystepuja kolizje
     *
     *
     *\return
     * true -  na scenie wystepuja kolizje
     * false - na scenie brak kolizji
     */
    bool czy_kolizja_na_scenie(void);
    vector<Manipulator> lista_manipulatorow;
    vector<Wielobok>    lista_wielobokow;
    vector<ZlozonyObiektGeometryczny*> lista_wskaznikow;
    Manipulator glowny_manipulator;

    /*!
     *
     *\brief Rysuje scene
     *
     *\arg[in] Lacze - laczew do GNUplot
     *
     *\pre
     *BRAK
     *
     *\post
     *wysyla dane do GNUplot
     *
     *
     *\return
     * true -  operacja sie powiodla
     * false - operacja sie nie powiodla
     */
    bool RysujScene(PzG::LaczeDoGNUPlota &Lacze);
    /*!
     *
     *\brief Wczytuje manipulatory na scenie
     *
     *\arg[in] nazwa_pliku_sceny - nazwa pliku w ktorym zapisana jest scena
     *
     *\pre
     *BRAK
     *
     *\post
     *Wczytuje manipulatory, wylicza wspolrzedne wierzcholkow i wypisuje je do plikow
     *
     *
     *\return
     * true -  w przypadku udanego wczytywania manipulatorow
     * false - w przypadku nieudanego wczytywania
     */
    bool WczytajScene(string nazwa_pliku_sceny);
        Scena();

    protected:

    private:
};

#endif // SCENA_H
