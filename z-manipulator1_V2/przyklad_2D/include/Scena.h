#ifndef SCENA_H
#define SCENA_H
#include "../include/Manipulator.h"
#include "../inc/lacze_do_gnuplota.hh"
#include<vector>
using namespace std;

class Scena
{
    public:

    vector<Manipulator> lista_manipulatorow;
    Manipulator glowny_manipulator;

    bool RysujScene(PzG::LaczeDoGNUPlota &Lacze);
    /*!
     *
     *\brief Wczytuje manipulatory na scenie
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
