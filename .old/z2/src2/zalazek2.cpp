#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


enum Symbol { e, a, b, c, d };

/*

 Przeciazenia tych operatorow trzeba zrealizowac.

Symbol operator - (Symbol x, Symbol y);
Symbol operator + (Symbol x, Symbol y);
Symbol operator * (Symbol x, Symbol y);
Symbol operator / (Symbol x, Symbol y);
ostream &  operator << (ostream &  StrmWyj, Symbol SymDoWysw);
*/


//============================================================================
//.......................  ZbiorPytan ........................................

/*
 * Tablica z zestawem pytan, ktore maja zostac zadane uzytkownikowi.
 */
const char*  ZestawPytan[] = {"a+d", "e*c", "c-b", "c/a", NULL};

/*
 * Modeluj zbior pytan, która maja zostac zadane uzytkownikowi.
 * Ponadto klasa ta dostarcza odpowiedni interfejs umozliwiajacy
 * pobieranie kolejnych pytan. 
 */
struct ZbiorPytan {
 private:
   /*
    * Przechowuje numer nastepnego pytania. Jest nim napis w tablicy
    * dostepnej poprzez pole "_wwTabPytan". Wartosc w polu
    * "_NrNastepnegoPytania" jest indeksem tej tablicy.
    * Jesli wartosc tego pola wynosi -1, to znaczy, ze
    * z obiektem nie jest skojarzony zaden zestaw pytan.
    */
    int   _NrNastepnegoPytania;
   /*
    * Wskaźnik na tablicę napisów zawierających pytania, które mają
    * zostać zadane uzytkownikowi. Ostatnim elementem tablicy
    * jest wskaznik "NULL".
    */
   const char **_wwTabPytan;

 public:
    /*
     * Inicjalizuje obiekt jako pusty, tzn. nie zawierajacy
     * zadnego zestawu pytan.
     */
  ZbiorPytan() { _NrNastepnegoPytania = -1;  _wwTabPytan = NULL; }
 
   /*
    * Pobiera kolejne pytanie z zestawu pytan, ktory dostepny jest
    * w danym obiekcie.
    *
    * Zestaw pytan dostepny jest poprzez pole "_wwTabPytan". Zawartosc
    * pola "_NrNastepnegoPytania" traktowana jest jako indeks w tej tablicy.
    * Jeśli zestaw pytan jest dostepny (tzn. "_wwTabPytan" <> NULL) oraz
    * adres pytania jest rozny do NULL, to zawartosc pola
    * "_NrNastepnegoPytania" zostaje zwiekszona o 1.
    *
    * Zwraca: Wskaznik do nastepnego pytania. Jesli jest ono niedostepne
    *         (koniec zbioru pytan lub brak pytan), to zwracany jest
    *         adres NULL.
    */
  const char* WezNastepnePytanie() { /* Tu trzeba wstawic odpowiedni kod */ }  
  /*
   * Kojarzy obiekt z zestawem pytan wpisujac wskaznik na tablice 
   * pytan do pola "_wwTabPytan".
   * Parametry:
   *    wwZestawPytan - tablica z zestawem pytan, ktorej ostatnim elementem
   *                    jest wskaznik "NULL".
   * Warunki wstepne:
   *   Parametr "wwZestawPytan" wskazuje na tablice napisow, ktorej
   *   ostatnim elementem jest wskaznik "NULL".
   * Warunki koncowe:
   *   Zawartosc pola "_NrNastepnegoPytania" ustawiona jest na wartosc
   *   zero.
   */
  void WstawZestawPytan(const char** wwZestawPytan);
};


void ZbiorPytan::WstawZestawPytan(const char** wwZestawPytan)
{
  /*  Tu trzeba wpisac kod tej metody. */ 
}

/* 
 * Klasa modeluje interpreter operacji, ktorych operatory sa przekazywane
 * do obiektu tej klasy jako znak.
 */
struct InterpreterOper {
  /*!
   * Przechowuje wartosc pierwszego argumentu.
   */
  Symbol  _Arg1;
  /*!
   * Przechowuje wartosc drugiego argumentu.
   */
  Symbol  _Arg2;
  /*
   * Znak operatora, okreslajacego typ wykonywanej operacji.
   * Dopuszczalne wartosci tego pola to: '+', '-', '*', '/'.
   */
  char    _Oper;

 public:
  /*
   * Inicjalizuje wstepna zawartosc obiektu.
   * Przypisuje mu operator dodawania, a jako wartosci argumentow
   * wstawiane sa elementy neutralne wzgledem tej operacji.
   */
  InterpreterOper() { _Arg1 = _Arg2 = e;  _Oper = '+'; }
  /*
   * Zmienia zawartosc pierwszego argumentu.
   * Parametry:
   *    Arg - nowa wartosc pierwszego argumentu.
   */
  void UstawArg1(Symbol Arg) { _Arg1 = Arg; }
  /*
   * Zmienia zawartosc drugiego argumentu.
   * Parametry:
   *    Arg - nowa wartosc drugiego argumentu.
   */
  void UstawArg2(Symbol Arg) { /* ... */ }
  /*
   * Zmienia zawartosc operator.
   * Parametry:
   *    Oper - nowa wartosc operator.
   *
   * Warunki wstepne:
   *   Oper - moze zawierac jeden z czterech znakow: '+', '-', '*', '/'.
   */
  void UstawOper(char Oper) { /* ... */ }


  Symbol WykonajDzialanie();
};

//.......................  ZbiorPytan ........................................
//============================================================================

//============================================================================
//.......................  InterpreterOper ...................................

/*!
 * Interpretuje symbol operatora i wykonuje zadana operacje
 * dwuargumentowa. Operacja jest interpretowana na podstawie
 * wartości pól _Arg1, _Arg2 oraz _Oper.
 * 
 * Warunki wstepne: 
 *  _Oper - moze byc jednym ze znakow: '-','+','*','/'.
 *          W innego znaku dzialanie programu jest przerywane z komunikatem
 *          bledu.
 *  _Arg2 - gdy dzialanie '/', to Arg2 nie moze miec wartosc symbolu "e".
 *          Symbol ten jest elementem neutralnym operacji dodawania i
 *          odejmowania.
 *
 * Zwracana wartosc:
 *    Wynik wykonanej operacji.
 */
Symbol InterpreterOper::WykonajDzialanie()
{
  switch (_Oper) {
  /*
    Te czesc mozna odkomentowac, gdy w kodzie umieszczone zostana
    definicje przeciazen operatorow: -, +, *, /.
    
    case '-': return _Wynik = _Arg1 - _Arg2;
    case '+': return _Wynik = _Arg1 + _Arg2;
    case '*': return _Wynik = _Arg1 * _Arg2;
    case '/': return _Wynik = _Arg1 / _Arg2;
   */
    default:
      cerr << "Blad! Jako operator zostal uzyty niedozwolony znak: '" 
           << _Oper << "'" << endl;
      exit(1);
  }
}

//.......................  InterpreterOper ...................................
//============================================================================



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
 *   WczytSym - zawiera wczytany symbol pod waunkiem, ze 
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



//------------------------------------------------
// To jest przyklad opisu przeciazenia operatora

/* 
 * Realizuje odejmowanie dwoch symboli.
 *
 * Parametry:
 *   Arg1 - odjemna
 *   Arg2 - odjemnik
 *
 * Zwracana wartosc:
 *   Wynik operacji odejmowania, ktora zdefiniowania jest
 *   posrednio na podstawie tabelki operacji dodawania.
 */
Symbol operator - (Symbol Arg1, Symbol Arg2)
{
 /*
  To jest przyklad definicji przeciazenia operatora w wersji
  dla bardziej ambinych.

  return Arg1 + ElementOdwrotny_Dodawanie(Arg2);
 */

 // Kod ponizej jest tylko po to, aby wszystko poprawnie kompilowalo sie
 // i konsolidowalo.
 return e;
}



int main()
{
  ZbiorPytan   ZbPytan; 
  Symbol      x;

  ZbPytan.WstawZestawPytan(ZestawPytan);

  cout << "Wprowadz symbol [a-e] > " << flush;
  cin >> x;

  cout << "___ Wprowadzono symbol: " << x << endl;
  return 0;
}
