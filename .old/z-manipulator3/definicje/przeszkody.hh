
class Wektor;


class Przeszkoda {
 public:
   virtual ~Przeszkoda() {}
   virtual bool CzyPrzeciecieZOdcinkiem(  const Wektor& Po, 
                                          const Wektor& Pn
                                       ) const;
};



class Przeszkoda_Wielobok: public Przeszkoda {
 public:
   bool CzyPrzeciecieZOdcinkiem(  const Wektor& Po, 
                                  const Wektor& Pn
                               ) const;
};



class Przeszkoda_Okrag: public Przeszkoda {
 public:
   bool CzyPrzeciecieZOdcinkiem(  const Wektor& Po, 
                                  const Wektor& Pn
                               ) const;
};


