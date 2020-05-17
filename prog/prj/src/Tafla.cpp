#include "Tafla.hh"
/*!
 * \file
 * \brief Definicja metod klasy Tafla
 *
 * Zawiera także definicje metod służących opisu
 * powierzchni tafli wody.
 */

Tafla::Tafla(double wymiar) {
  Wektor3D W(0.0,0.0,(wymiar));
  Pozycja_srodka = W;
  wymiar_palety = wymiar;
  string K = "blue";
  kolor = K;
}
