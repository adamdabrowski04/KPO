#ifndef WIELOBOK_H
#define WIELOBOK_H


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
