#include "Dno.hh"
/*!
 * \file
 * \brief Definicja metod klasy Dno
 *
 * Zawiera także definicje metod służących do 
 * opisu dna.
 */

Dno::Dno(double wymiar) {
  Wektor3D W(0.0,0.0,(-1* wymiar));
  Pozycja_srodka = W;
  wymiar_palety = wymiar;
  string K = "black";
  kolor = K;
}
