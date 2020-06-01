#include "PrzeszkodaPros.hh"
/*!
 * \file
 * \brief Definicja metod klasy PrzeszkodaPros
 *
 * Plik zawiera definicje metod działających 
 * na obiektach klasy PrzeszkodaPros.
 */


PrzeszkodaPros::PrzeszkodaPros(double A_bok,double B_bok,double C_bok) {
  if(A_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(B_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(C_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  A = A_bok;
  B = B_bok;
  C = C_bok;
}

bool PrzeszkodaPros::czy_kolizja(InterfejsDrona *Inter) {
  Dron *R2D2 =  static_cast<Dron*> (Inter);
  double promien = R2D2->Wez_Promien();
  Wektor3D srodek_drona = R2D2->get_pozycja_srodka();
  if(srodek_drona[0] > Pozycja_srodka[0] - (A/2) - promien)
    if(srodek_drona[0] < Pozycja_srodka[0] + (A/2) + promien)
      if(srodek_drona[1] > Pozycja_srodka[1] - (B/2) - promien)
	if(srodek_drona[1] < Pozycja_srodka[1] + (B/2) + promien)
	  if(srodek_drona[2] > Pozycja_srodka[2] - (C/2) - promien)
	    if(srodek_drona[2] < Pozycja_srodka[2] + (C/2) + promien)
	      return 1;
  return 0;
}
