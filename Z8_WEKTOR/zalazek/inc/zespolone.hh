#ifndef ZESPOLONE_HH
#define ZESPOLONE_HH

/*!
 *\file
 *\brief Definicja klasy Zespolona
 *
 * Plik zawiera definicję klasy Zespolona,
 * która modeluje obiekt zdolny do przechowywania,
 * oraz wykonywania podstawowych operacji
 * arytmetycznych na liczbach zespolonych
 */

/*!
 *\brief Modeluje pojęcie liczby zespolonej
 *
 * Klasa modeluje pojęcie liczby zespolonej.
 * Jej atrybutami są część rzeczywista i urojona liczby zespolonej
 */
class Zespolona {
public:
 /*!
  *\brief Wartość rzeczywista
  *
  * Pole zawiera rzeczywistą część liczby urojonej
  */
  double  Re;

 /*!
  *\brief Wartość urojona
  *
  * Pole zawieta urojoną część liczby zespolonej
  */
  double  Im;

  /*!
   *\brief Operator przypisanis
   *
   * Przeciążenie operatora przypisani dla klasy Zespolona
   */
  Zespolona& operator = (Zespolona LZ){
    Re=LZ.Re;
    Im=LZ.Im;
    return *this;
  }
 Zespolona(double a =0, double b = 0)
 {Re=a; Im = b;}
};

/****************Przeciążenia operatorów*********************/


/*!
 *\brief Operator dodawania
 *
 *Przeciążenie operatora dodawania dla obiektu typu Zespolona.
 *\param[in] LZ1, LZ2 - Argumenty, na których jest wykonywana operacja dodawania.
 *                  Są to obiekty typu Zespolona.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator + (Zespolona LZ1, Zespolona LZ2);

/*!
 *\brief Operator odejmowania
 *
 *Przeciążenie operatora odejmowania dla obiektu typu Zespolona.
 *\param[in] LZ1, LZ2 - [We] Argumenty, na których jest wykonywana operacja odejmowania.
 *                  Są to obiekty typu Zespolona.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator - (Zespolona LZ1, Zespolona LZ2);

/*!
 *\brief Operator unarny
 *
 *Operator unarny "-" zwraca liczbę przeciwną
 *\param[in] LZ - [We] Argument, na którym jest wykonywana odpowiednia operacja.
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator - (Zespolona LZ);

/*!
 *\brief Operator mnożenia
 *
 *Przeciążenie operator mnożenia dla obiektu typu Zespolona.
 *\param[in] LZ1, LZ2 - [We] Argumenty, na których jest wykonywana operacja mnożenia.
 *                Są to obiekty typu Zespolona.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator * (Zespolona LZ1, Zespolona LZ2 );

/*!
 *\brief Operator dzielenia
 *
 *Przeciążenie operatora dzielenia  dla obiektu typu Zespolona.
 *\param[in] LZ1, LZ2 - [We] Argumenty, na których jest wykonywana operacja dzielenia.
 *                  Są to obiekty typu Zespolona.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */Zespolona operator / (Zespolona LZ1, Zespolona LZ2 );

/*!
 *\brief Operator dzielenia
 *
 *Przeciążenie operatora dzielenia dla liczby zespolonej i rzeczywistej
 *\param[in] LZ1 - [We] Argumenty, na którym jest wykonywana operacja dzielenia.
 *                  Jest to obiekty typu Zespolona.
 *\param[in] a   - [we] Liczba przez którą dzielimy. Obiekt typu double.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator / (Zespolona LZ1, double a );

/*!
 *\brief Operator mnożenia przez liczbę rzeczywistą
 *
 *Przeciążenie operatora mnożenia dla liczby zespolonej i rzeczywistej
 *\param[in] LZ1 - [We] Argumenty, na którym jest wykonywana operacja mnożenia.
 *                  Jest to obiekty typu Zespolona.
 *\param[in] a   - [we] Liczba przez którą mnożymy. Obiekt typu double.
 *
 *\return Wynik operacji jako obiekt typu Zespolona.
 */
Zespolona operator * (Zespolona LZ1, double a );

/*!
 *\brief Operator porównania
 *
 *Przeciążenie operatora porównania dla obiektu typu Zespolona.
 *\param[in] LZ1, LZ2 - [We] Argumenty, na których jest wykonywana operacja dzielenia.
 *                  Są to obiekty typu Zespolona.
 *
 *\return Wynik operacji jako obiekt typu bool.
 *true -liczby takie same
 *false - liczbye różne
 */
bool operator == (Zespolona LZ1, Zespolona LZ2);
bool operator  < (Zespolona LZ1, Zespolona LZ2);
bool operator  > (Zespolona LZ1, Zespolona LZ2);
/********operatory wczytywania i wypisywania************/
/*!
 *\brief Operator wczytywania
 *
 *Przeciążenie operatora wczytywania dla obiektu zespolona
 *\param[in] LZ - [Wy] Referencja do obiektu w którym zostaje zapisana licba zespolona
 *\param[in] StrmWe - Strumien, z którego wczytujemy dane
 *\return Strumień istream
 */
std::istream & operator >> (std::istream & StrmWe, Zespolona &LZ);

/*!
 *\brief Operator wypisania
 *
 *Przeciążenie operatora wypisywania dla obiektu typu Zespolona
 *\param[in]  LZ - [We] Obiekt który zostaje wypisany na podane wyjście;
 *\param[out] StrmWy - Strumien wyjsciowy, do którego wypisujemy dane
 *\return Strumień ostram
 */
std::ostream & operator << (std::ostream & StrmWy, const Zespolona LZ);

/*!
 *\brief Wczytuje wyrażenie
 *
 * Funkcja wczytuje argumenty operacji i znak operacji
 *\param[in]  LZ1 , Arg2   -[wy] Wczytane argumenty operacji. Obiekty typu Zespolona.
 *\param[in] Znak      -[wy] Wczytany znak przeprowadzanej operacji
 *\param[in] StrmWe - Strumien, z którego wczytujemy dane
 *
 *\post
 * W zmiennych, z którymi funkcja zostaje wywolana
 * zostają zapisane wczytane wartości
 */
std::istream& WczytajWyrazenie(Zespolona &LZ1, Zespolona &Arg2,char &Znak, std::istream &StrmWe);

/*!
 *\brief Moduł
 *
 *Oblicza moduł liczby zespolonej
 *
 *\param[in] LZ - Liczba zespolona dla którj zostaje policzony moduł
 *
 *\return Funkcj zwraca moduł liczby zespolonej
 */
double modul(Zespolona LZ);

/*!
 *\brief Liczba sprzężona
 *
 *Oblicza liczbę zespoloną sprzężoną.
 *
 *\param[in] LZ - Liczba zespolona, dla której zostaje policzona liczba sprzężona
 *
 *\return Funkcja zwraca liczbę zespoloną sprzęzoną do tej wczytannej.
 */
Zespolona sprzezona(Zespolona LZ);
/*!
 *\brief Zeruje zmienną
 *
 *Funkcja zeruj wczytaną zmienną, jest porzebna z uwagi na kostrukcję programu
 */
void Zeruj (Zespolona& Zm);

#endif
