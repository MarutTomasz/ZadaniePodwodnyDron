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
  string K = "grey";
  kolor = K;
}

bool Dno::czy_kolizja(InterfejsDrona *Inter) {
  double nowy_poziom = -1*wymiar_palety + Inter->Wez_Promien();
  Dron *R2D2 = static_cast<Dron*> (Inter);
  return (R2D2->get_pozycja_srodka()[2] <= nowy_poziom);  
}
