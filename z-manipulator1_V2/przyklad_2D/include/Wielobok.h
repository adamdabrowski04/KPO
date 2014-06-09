#ifndef WIELOBOK_H
#define WIELOBOK_H
#include "../include/ZlozonyObiektGeometryczny.h"


class Wielobok:public ZlozonyObiektGeometryczny
{
    public:
    virtual const char* TypPrzeszkody()const{return "Wielobok"; }
        Wielobok();
        virtual ~Wielobok();
    protected:
    private:
};

#endif // WIELOBOK_H
