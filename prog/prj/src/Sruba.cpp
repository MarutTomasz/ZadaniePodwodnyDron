#include "Sruba.hh"

Sruba::Sruba() {}

Sruba::Sruba(double A_bok, double H_bok) {
  if(A_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(H_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  A = A_bok;
  H = H_bok;
}

void Sruba::Set_Wymiary(double A_bok, double H_bok) {
  if(A_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(H_bok < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  A = A_bok;
  H = H_bok;
}
  

void Sruba::Obracaj() {
  
  
  
  
  
  
}
