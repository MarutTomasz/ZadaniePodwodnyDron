#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
#include "SMacierzKw.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "InterfejsDrona.hh"
#include "GraniastoslupHex.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Tafla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  double A = 100;
  double B = 15;
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-A,A,-A,A,-A,A,0));
  Dron R2D2(3*B,4*B,2*B);
  Dno Nr1(A);
  Tafla Nr2(A);
  char znak = 'i';
  double kat;
  double odleglosc;

  R2D2.set_api(api);
  Nr1.set_api(api);
  Nr2.set_api(api);

  Nr1.Narysuj();
  Nr2.Narysuj();
  R2D2.Narysuj();
  
 
  while (znak != 'q'){
    cout << "Menu wyboru: \n o - obroc drona o kat\n p - przesun drona\n q - zakoncz dzialanie\n\n Twoj wybor:    ";
    cin >> znak;
  
    if(znak == 'o'){
      cout << "Podaj kat obrotu:    ";
      cin >> kat;
      R2D2.Obrot_Z_Animowany(kat);
    }
    
    else if(znak == 'p'){
      cout << "Podaj odleglosc:    ";
      cin >> odleglosc;
      cout << "Podaj kat nachylenia:    ";
      cin >> kat;
      R2D2.Plyn(odleglosc,kat);
    }
      
    else if(znak == 'q'){
      cout << "Program konczy dzialanie!! :) " << endl << endl;
    }
    else
      cout << "Niepoprawny znak opcji" << endl << endl;
    
  }
  return 0;
}



