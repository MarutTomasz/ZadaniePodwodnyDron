#include "Dno.hh"
/*!
 * \file
 * \brief Definicja metod klasy Dno
 */

Dno::Dno(double wymiar) {
  Wektor3D W(0.0,0.0,(-1* wymiar));
  Pozycja_srodka = W;
  wymiar_palety = wymiar;
  kolor = "grey";
}

bool Dno::czy_kolizja(std::shared_ptr<InterfejsDrona> Inter) const {
  double nowy_poziom = -1*wymiar_palety + Inter->Wez_Promien();
  std::shared_ptr<Dron> R2D2 = std::static_pointer_cast<Dron> (Inter);
  return (R2D2->get_pozycja_srodka()[2] <= nowy_poziom);  
}
