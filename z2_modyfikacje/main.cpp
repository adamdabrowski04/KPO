#include"include/dzialania.h"


int main()
{
 //Symbol wynik_alg, wynik_ope, wynik_fun;

sumaTychSamych();

//
// wynik_alg = a+b*c-e/a; // <- Wyrażenie zapisane w sposób zwyczajowy
// wynik_fun = odejmij(dodaj(a,mnoz(b,c)),dziel(e,a) ); // <- Wyrażenie wykorzystujące funkcje
// wynik_ope = operator-(operator+(a,operator*(b,c)),operator/(e,a) ); // <- Wyrażenie z jawnym wywołaniem operatorów
//
// Porownaj(wynik_alg,wynik_ope,wynik_fun);
//
// wynik_alg = (b-a)*a/b; // <- Wyrażenie zapisane w sposób zwyczajowy
// wynik_fun = dziel(mnoz( odejmij(b,a) ,a) ,b ); // <- Wyrażenie wykorzystujące funkcje
// wynik_ope = operator/(operator*( operator-(b,a) ,a) ,b ); // <- Wyrażenie z jawnym wywołaniem operatorów
//
// Porownaj(wynik_alg,wynik_ope,wynik_fun);
//
// wynik_alg = a*b/c/d; // <- Wyrażenie zapisane w sposób zwyczajowy
// wynik_fun = dziel(dziel(mnoz(a,b), c), d); // <- Wyrażenie wykorzystujące funkcje
// wynik_ope = operator/(operator/(operator*(a,b), c), d); // <- Wyrażenie z jawnym wywołaniem operatorów
//
// Porownaj(wynik_alg,wynik_ope,wynik_fun);
//
// wynik_alg = (a-b+c*d)/a; // <- Wyrażenie zapisane w sposób zwyczajowy
// wynik_fun = dziel(dodaj(odejmij(a,b),mnoz(c,d) ),a ); // <- Wyrażenie wykorzystujące funkcje
// wynik_ope = operator/(operator+(operator-(a,b),operator*(c,d) ),a ); // <- Wyrażenie z jawnym wywołaniem operatorów
//
// Porownaj(wynik_alg,wynik_ope,wynik_fun);
}
