#include "MacierzOb.hh"
/*!
 * \file
 * \brief Definicja metod klasy MacierzOb
 *
 * Plik zawiera definicje metod działających 
 * na macierzach obrotu.
 */


MacierzOb::MacierzOb(const Macierz3D &M) : Macierz3D(M) {
  double epsilon = 0.000000001;
  if(abs(tab[0] * tab[1]) > epsilon){
    cout << "Macierz nie jest ortonormalna 1" << endl;
    exit(1);
  }
  if(abs(tab[1] * tab[2]) > epsilon){
    cout << "Macierz nie jest ortonormalna 2" << endl;
    exit(1);
  }
  if(abs(tab[0] * tab[2]) > epsilon){
    cout << "Macierz nie jest ortonormalna 3" << endl;
    exit(1);
  }
  if(abs((*this).wyznacznik(Laplace) - 1) > epsilon){
    cout << "Macierz nie jest ortonormalna 4" << endl;
    exit(1);
  }
}

MacierzOb::MacierzOb(){
  (*this).MacierzJednostkowa();
  
}

MacierzOb::MacierzOb(char os, double stopnie){
  switch(os){
  case 'z' : {
    tab[0][0] = cos(stopnie * PI/180);
    tab[0][1] = -sin(stopnie * PI/180);
    tab[0][2] = 0.0;
    tab[1][0] = sin(stopnie * PI/180);
    tab[1][1] = cos(stopnie * PI/180);
    tab[1][2] = 0.0;
    tab[2][0] = 0.0;
    tab[2][1] = 0.0;
    tab[2][2] = 1.0;
    break;
  }
  case 'x' : {
    tab[0][0] = 1.0;
    tab[0][1] = 0.0;
    tab[0][2] = 0.0;
    tab[1][0] = 0.0;
    tab[1][1] = cos(stopnie * PI/180);
    tab[1][2] = -sin(stopnie * PI/180);
    tab[2][0] = 0.0;
    tab[2][1] = sin(stopnie * PI/180);
    tab[2][2] = cos(stopnie * PI/180);
    break;
  }
  case 'y' : {
    tab[0][0] = cos(stopnie * PI/180);
    tab[0][1] = 0.0;
    tab[0][2] = sin(stopnie * PI/180);
    tab[1][0] = 0.0;
    tab[1][1] = 1.0;
    tab[1][2] = 0.0;
    tab[2][0] = -sin(stopnie * PI/180); 
    tab[2][1] = 0.0;
    tab[2][2] = cos(stopnie * PI/180);
    break;
  }
  default: {
    cout << "Nieprawidlowa os obtoru. Nie mozna stworzyc macierzy." << endl;
    exit(1);
    break;
  }
  }
}
