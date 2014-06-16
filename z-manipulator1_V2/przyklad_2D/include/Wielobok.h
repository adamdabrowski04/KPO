#ifndef WIELOBOK_H
#define WIELOBOK_H
#include "../include/ZlozonyObiektGeometryczny.h"
#include<string>
#include<vector>

class Wielobok:public ZlozonyObiektGeometryczny
{
    public:
    virtual const char* TypPrzeszkody()const{return "Wielobok"; }
        Wielobok();
        virtual ~Wielobok();
   std:: vector<double> tablica_x;
   std::vector<double> tablica_y;
   bool ZapiszWierzcholkiDoPliku(std::string ) ;
   // string nazwa;
    bool WczytajWierzcholki();
    protected:
    private:
};

#endif // WIELOBOK_H
