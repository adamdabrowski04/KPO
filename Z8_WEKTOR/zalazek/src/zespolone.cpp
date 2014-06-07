#include<iostream>
#include<string>
#include<limits>
#include<cmath>
#include "../inc/zespolone.hh"
using namespace std;
/*!
 *\file
 *\brief Definicje operatorów  i funkcji klasy Zespolona
 *
 *Zawiera definicję oeratorów i funkcji klasy Zespolona
 */

istream &  operator >> (istream & StrmWe, Zespolona &LZ){
  char Nawias,JU, Operator; //JU - jednostka urojona
  double Liczba=0;
  StrmWe>>Nawias;
  if(Nawias!='(') StrmWe.setstate(ios::failbit);
  StrmWe>>Liczba;
  if(StrmWe.peek()=='i'||StrmWe.peek()==')'){
    cin>>JU;
    if(JU=='i'){
      LZ.Im=Liczba;
      LZ.Re=0;
      StrmWe>>Nawias;
      if(Nawias!=')') StrmWe.setstate(ios::failbit);
    }
    else{
      LZ.Im=0;
      LZ.Re=Liczba;
    }
  }
  else{
    LZ.Re=Liczba;
    StrmWe>>Operator;
    if(Operator!='+'&&Operator!='-')StrmWe.setstate(ios::failbit);
    if(StrmWe.peek()=='i') Liczba=1;
    else StrmWe>>Liczba;
    if(Operator=='-') Liczba=-Liczba;
    StrmWe>>JU;    ///Jednostka urojona
    if(JU!='i') StrmWe.setstate(ios::failbit);
    StrmWe>>Nawias;
    if(Nawias!=')') StrmWe.setstate(ios::failbit);
    LZ.Im=Liczba;
  }
  if(StrmWe.fail())StrmWe.unget();
  return StrmWe;
}


ostream & operator << (ostream & StrmWy,const Zespolona LZ ){
return StrmWy<<'('<<LZ.Re<<showpos<<LZ.Im<<noshowpos<<"i)";
}

Zespolona operator + (Zespolona LZ1, Zespolona LZ2 ){
  Zespolona LZ;
  LZ.Re=LZ1.Re+LZ2.Re;
  LZ.Im=LZ1.Im+LZ2.Im;
  return LZ;
}

Zespolona operator - (Zespolona LZ1, Zespolona LZ2 ){
  Zespolona LZ;
  LZ.Re=LZ1.Re-LZ2.Re;
  LZ.Im=LZ1.Im-LZ2.Im;
  return LZ;
}

Zespolona operator -(Zespolona LZ){
  Zespolona LZa;
  LZa.Re=-LZ.Re;
  LZa.Im=-LZ.Im;
  return LZa;
}


Zespolona operator * (Zespolona LZ1, Zespolona LZ2 ){
  Zespolona LZ;
  LZ.Re=(LZ1.Re*LZ2.Re)-(LZ1.Im*LZ2.Im);
  LZ.Im=(LZ1.Im*LZ2.Re)+(LZ1.Re*LZ2.Im);
  return LZ;
}

Zespolona operator / (Zespolona LZ1, Zespolona LZ2 ){
  Zespolona LZ;
  LZ=(LZ1*sprzezona(LZ2))/(modul(LZ2)*modul(LZ2));
  return LZ;
}

Zespolona operator / (Zespolona LZ1, double a ){
  Zespolona LZ;
  LZ.Re=LZ1.Re/a;
  LZ.Im=LZ1.Im/a;
  return LZ;
}

Zespolona operator * (Zespolona LZ1, double a ){
  Zespolona LZ;
  LZ.Re=LZ1.Re*a;
  LZ.Im=LZ1.Im*a;
  return LZ;
}

double modul(Zespolona LZ){
  double a;
  a=sqrt(LZ.Re*LZ.Re+LZ.Im*LZ.Im);
  return a;
}
Zespolona sprzezona(Zespolona LZ){
  Zespolona LZa;
  LZa.Re=LZ.Re;
  LZa.Im=-LZ.Im;
  return LZa;
}

bool operator == (Zespolona LZ1, Zespolona LZ2){
  return ( LZ1.Re==LZ2.Re&&LZ1.Im==LZ2.Im)?true:false;
}

void Zeruj (Zespolona& Zm){
  Zm.Re=0;
  Zm.Im=0;
}


bool operator  < (Zespolona LZ1, Zespolona LZ2)
{
    return LZ1.Re<LZ2.Re;
}
bool operator  > (Zespolona LZ1, Zespolona LZ2)
{
    return LZ1.Re>LZ2.Re;
}
