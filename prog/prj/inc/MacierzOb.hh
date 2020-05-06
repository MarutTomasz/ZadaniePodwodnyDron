#ifndef MACIERZ_OB
#define MACIERZ_OB

#include "SMacierzKw.hh"

class MacierzOb: public MacierzKw<double,3> {
public:
  MacierzOb();
  MacierzOb(const MacierzKw<double,3> &M);
  
};

#endif
