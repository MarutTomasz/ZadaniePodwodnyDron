#ifndef DRON
#define DRON

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"

class Dron: public Prostopadloscian, public InterfejsDrona {
public:
  Dron(double bok_A, double bok_B, double bok_C);
  void Obrot_Z(double stopnie) override;
  void Obrot_X(double stopnie) override;
  
  void Przesun(double odleglosc) override;

  
};

#endif
