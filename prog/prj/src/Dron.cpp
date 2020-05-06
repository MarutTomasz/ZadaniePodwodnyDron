#include "Dron.hh"

Dron::Dron(double bok_A, double bok_B, double bok_C) {
if(A < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(B < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(C < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  A = bok_A;
  B = bok_B;
  C = bok_C;
  Wektor3D Pomocniczy(A/2,B/2,C/2);
  Punkt_Odniesienia = Pomocniczy;
}
  

void Dron::Obrot_Z(double stopnie) {
  MacierzKw<double,3> Ob(cos(stopnie * PI/180),-sin(stopnie * PI/180),0.0,sin(stopnie * PI/180),cos(stopnie * PI/180),0.0,0.0,0.0,1.0);
  MacierzOb Obrot(Ob);

  Orientacja = Orientacja * Obrot;
  
}

void Dron::Obrot_X(double stopnie) {
  MacierzKw<double,3> Ob(1.0,0.0,0.0,0.0,cos(stopnie * PI/180),-sin(stopnie * PI/180),0.0,sin(stopnie * PI/180),cos(stopnie * PI/180));
  
  MacierzOb Obrot(Ob);
  Orientacja = Orientacja * Obrot;
  
}

void Dron::Przesun(double odleglosc) {
  Wektor3D przesuniecie(0,odleglosc,0);
  
  (*this).Orientuj_wektor(przesuniecie);
  
  Pozycja_srodka = Pozycja_srodka + przesuniecie;
}  
