#ifndef ROZPOZNAJPROBLEM_HH_INCLUDED
#define ROZPOZNAJPROBLEM_HH_INCLUDED

#include<iostream>

const int ROZMIAR_MAX=5;
const int ROZMIAR_MIN=2;

enum TypProblemu {TP_double, TP_zespolone, TP_blad};

TypProblemu RozpoznajProblem(int argc, char* argv[],int &Rozmiar);
void RozwiazProblem_zespolone(const int);
void RozwiazProblem_double(const int);
#endif // ROZPOZNAJPROBLEM_HH_INCLUDED
