#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


enum Symbol { e, a, b, c, d };


/*!
 * Umozliwia wczytanie symbolu ze strumienia wejscia.
 * 
 * Parametry:
 *   StrmWej - strumien wejsciowy, z ktorego ma byc wczytany
 *       symbol.
 *   WczytSym - do niego ma byc wczytany symbol ze strumienia
 *       wejsciowego.
 *
 * Warunki koncowe:
 *   WczytSym - zawiera wczytany symbol pod warunkiem, ze 
 *       ze strumienia zostal odczytany znak z przedzialu 'a'-'e'.
 *       W przypadku przeciwnym dzialanie programu zostaje
 *       przerwane z komunikatem bledu.
 *
 * Zwracane wartosci:
 *   Referencja do strumienia, na ktorym wykonana zostala
 *   operacja odczytu symbolu w postaci znaku.
 */
istream &  operator >> (istream &  StrmWej, Symbol &  WczytSym)
{
  Symbol TabSymboli[] = {a,b,c,d,e};
  char   ZnakSymbolu;
  
  StrmWej >> ZnakSymbolu;
  if (ZnakSymbolu < 'a' || 'e' < ZnakSymbolu) {
    cerr << "Blad! Wprowadzony znak nie odpowiada zadnemu symbolowi."
         << endl;
    exit(1);
  }
  WczytSym =  TabSymboli[ZnakSymbolu-'a'];
  return StrmWej;
}


int main()
{
  Symbol  x;

  cout << "Wprowadz symbol [a-e] > " << flush;
  cin >> x;

  cout << "___ Wprowadzono symbol: " << x << endl;
  return 0;
}
