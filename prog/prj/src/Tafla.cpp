#include "Tafla.hh"
/*!
 * \file
 * \brief Definicja metod klasy Tafla
 *
 * Zawiera także definicje metod służących opisu
 * powierzchni tafli wody.
 */

Tafla::Tafla(double wymiar) {
  Wektor3D W(0.0,0.0,(wymiar*4/5));
  Pozycja_srodka = W;
  wymiar_palety = wymiar;
  string K = "blue";
  kolor = K;
}

bool Tafla::czy_kolizja(InterfejsDrona *Inter) {
  Dron *R2D2 =  static_cast<Dron*> (Inter);
  return (R2D2->get_pozycja_srodka()[2] > wymiar_palety*4/5);  
}
