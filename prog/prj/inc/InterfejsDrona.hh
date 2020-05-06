#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include <math.h>
#include "MacierzOb.hh"
#include "SWektor.hh"

#define PI 3.141592653589

class InterfejsDrona {
public:
  virtual void Obrot_Z(double stopnie) = 0;
  virtual void Obrot_X(double stopnie) = 0;
  virtual void Przesun(double odleglosc) = 0;

};

  
#endif
