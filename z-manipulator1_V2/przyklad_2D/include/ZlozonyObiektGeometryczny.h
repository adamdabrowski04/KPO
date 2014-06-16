#ifndef ZLOZONYOBIEKTGEOMETRYCZNY_H
#define ZLOZONYOBIEKTGEOMETRYCZNY_H
#include<string>

class ZlozonyObiektGeometryczny
{
    public:
        virtual const char* TypPrzeszkody()const {return "ObiektGeometryczny"; }
        ZlozonyObiektGeometryczny();
        virtual ~ZlozonyObiektGeometryczny();
       std:: string nazwa;
    protected:
    private:
};

#endif // ZLOZONYOBIEKTGEOMETRYCZNY_H
