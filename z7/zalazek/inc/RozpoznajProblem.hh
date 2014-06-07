#ifndef ROZPOZNAJPROBLEM_HH_INCLUDED
#define ROZPOZNAJPROBLEM_HH_INCLUDED

#include<iostream>

const int ROZMIAR_MAX=5;
const int ROZMIAR_MIN=2;

enum TypProblemu {TP_double, TP_zespolone, TP_blad, TP_int};

 /*!
 * \brief Funkcja parsuje opcje wywoałania programu
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[out] Rozmiar - Rozmiar układu równań do wyliczenia
 * \param[in] argc - ilość argumentów wywołania + 1 (nazwa progreamu)
 * \param[in] argv - tablica wskaźników do argumentów wywołania
 *
 *
 * \pre
 * BRAK
 *
 * \post
 * Zostają rozpoznane opcje i wielkość układu równań w przypadku błednych opcji lub rozmiaru z poza przedziału 2<n<5 zostaje zwrócony błąd
 *
 * \return
 * TP_zespolone - liczby zespolone
 * TP_double    - liczby rzeczywiste
 * TP_blad      - blad rozpoznawania opcji
 */
TypProblemu RozpoznajProblem(int argc, char* argv[],int &Rozmiar);
 /*!
 * \brief Funkcja obliczajaca uklad rownan dla liczb zespolonych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[in] Rozmiar - Rozmiar układu równań do wyliczenia
 *
 * \pre
 * Musi istnieć rozkład LU macierzy współczynnikw układu równań
 *
 * \post
 * Zostaje policzony wynik układu równań i wwypisany na standarodwe wyjśćie
 *
 * \return
 * BRAK
 */
void RozwiazProblem_zespolone(const int);
void RozwiazProblem_int(const int);
 /*!
 * \brief Funkcja obliczajaca uklad rownan dla liczb rzeczywistych
 *
 * Zmienne z jakimi wywołujemy funkcję:
 * \param[in] Rozmiar - Rozmiar układu równań do wyliczenia
 *
 * \pre
 * Musi istnieć rozkład LU macierzy współczynnikw układu równań
 *
 * \post
 * Zostaje policzony wynik układu równań i wwypisany na standarodwe wyjśćie
 *
 * \return
 * BRAK
 */
void RozwiazProblem_double(const int);
#endif // ROZPOZNAJPROBLEM_HH_INCLUDED
