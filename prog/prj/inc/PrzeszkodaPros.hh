#ifndef PRZESZKODAPROS
#define PRZESZKODAPROS

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"

class PrzeszkodaPros: public Prostopadloscian, public Przeszkoda {
public:
  PrzeszkodaPros() = delete;
  PrzeszkodaPros(double A_bok,
		 double B_bok,
		 double C_bok);
  bool czy_kolizja(InterfejsDrona *Inter) override;

};

#endif
