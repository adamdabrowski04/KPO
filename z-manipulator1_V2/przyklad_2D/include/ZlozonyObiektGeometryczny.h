#ifndef ZLOZONYOBIEKTGEOMETRYCZNY_H
#define ZLOZONYOBIEKTGEOMETRYCZNY_H


class ZlozonyObiektGeometryczny
{
    public:
        virtual const char* TypPrzeszkody()const {return "ObiektGeometryczny"; }
        ZlozonyObiektGeometryczny();
        virtual ~ZlozonyObiektGeometryczny();
    protected:
    private:
};

#endif // ZLOZONYOBIEKTGEOMETRYCZNY_H
