#ifndef FIGURAGEOMETRYCZNA_HH
#define FIGURAGEOMETRYCZNA_HH

/*!
 * \file
 * \brief Definicja klasy FiguraGeometryczna oraz typu TypFiguryGeometrycznej
 *
 *  Plik zawiera definicję klasy FiguraGeometryczna, która modeluje ogólne
 *  pojęcie figury geometrycznej. Ponadto zawiera definicję typu wyliczeniowego
 *  TypFiguryGeometrycznej, którego wartości stanowią zestawieniem
 *  identyfikatorów wybranych typów figur geometrycznych.
 */


/*!
 * \brief Rodzaj figury geometrycznej modelowanej przez daną klasę
 *
 *  Wartości tego typu służą jako indentyfikatory dostępnych rodzai
 *  figur geometrycznych.
 */
enum TypFiguryGeometrycznej {
      TF_Zadna   /* Nie jest to żadna konkretna figura geometryczna */,
      TF_Kwadrat /* Figura geometryczna jest kawadratem */,
      TF_Kolo    /* Figura geometryczna jest kołem */
   };


/*!
 * \brief Modeluje pojęcie figury geometrycznej
 *
 *  Klasa modeluje pojęcie figury geometrycznej.
 *  Jest ona wykorzystywana jako klasa bazowa
 *  dla klas typu Kwadrat i Okrag.
 *  Jedynym jej atrybutem jest pole, które w przypadek, gdy
 *  klasa ta jest dziedziczona, pozwala
 *  określić rodzaj figury, która modelowana jest
 *  przez klasę pochodną.
 */
class FiguraGeometryczna {
  private:
   /*!
    *\brief Identyfikator rodzaju figury geometrycznej
    *
    * Pole zawiera identyfikator danego rodzaju figury geometrycznej.
    * Ma ono znaczenie w przypadku obiektów klas pochodnych, dla których
    * klasą bazową jest FiguraGeometryczna.
    * Jeżeli występuje niejawne rzutowanie w górę, zawartość tego pola
    * pozwala rozpoznać w jakim obiekcie klasy potomnej zanurzony jest
    * obiekt klasy FiguraGeometryczna.
    *
    * Wartość tego pola jest inicjalizowana tylko raz w momencie
    * tworzenia obiektu.
    */
    const TypFiguryGeometrycznej  _TypFigury;

  protected:
   /*!
    * Inicjalizuje typ figury geometrycznej
    *
    * Konstruktor domyślnie inicjalizuje obiekt jako taki, który nie
    * reprezentuje żadnego rodzaju figury geometrycznej. Jest on dostępny
    * tylko dla klasy pochodnej. To tylko w jej konstruktorze można
    * zmodyfikować sposób inicjalizacji.
    *
    * TypFig - identyfikator typu figury geoemtrycznej.
    */
   FiguraGeometryczna(TypFiguryGeometrycznej  TypFig = TF_Zadna):
                                             _TypFigury(TypFig) {}

  public:
   /*!
    * \brief Udostępnia indentyfikator typu figury geometrycznej
    *
    * Metoda zwraca zawartość pola _TypFigury,
    * która identyfikuje daną figurę. Wartości te są elementami
    * typu wyliczeniowego.
    *
    * \param[in] TF_Zadna - obiekt nie reprezentuje żadnej figury geometrycznej.
    * TF_Kwadrat - obiekt reprezentuje kwadrat.
    *                  W konstrukcji tego oprogramowania oznacza to, że obiekt
    *                  klasy FiguraGeometryczna jest składnikiem obiektu klasy
    *                  Kwadrat.
    * TF_Kolo - obiekt reprezentuje kolo. W konstrukcji
    *                  tego oprogramowania oznacza to, że obiekt klasy
    *                  FiguraGeometryczna jest składnikiem obiektu klasy Kolo.
    */
    TypFiguryGeometrycznej TypFigury() const { return _TypFigury; }

   /*
    *  Czy obiekt reprezentuje jakąś konkretną figurę geometryczną
    *
    *  Informuje czy obiekt reprezentuje konkretną figurę geometryczną,
    *  np. kolo lub kwadrat.
    *
    *  true - obiekt reprezentuje konkretną figurę geometryczną,
    *  false - w przypadku przeciwnym.
    */
    bool CzyKonkretnaFigura() const { return _TypFigury != TF_Zadna; }
};



#endif
