#ifndef PRZESZKODA
#define PRZESZKODA

#include "InterfejsDrona.hh"

class Przeszkoda {
public:
  virtual bool czy_kolizja(InterfejsDrona *Inter) =0;

};


#endif
