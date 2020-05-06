#include "MacierzOb.hh"
/*!
 * \file
 * \brief Definicja metod klasy MacierzOb
 *
 * Plik zawiera definicje metod działających 
 * na macierzach obrotu.
 */


MacierzOb::MacierzOb(const MacierzKw<double,3> &M) : MacierzKw<double,3>(M) {
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
  MacierzKw<double,3> M;
  M.MacierzJednostkowa();
  tab[0] = M[0];
  tab[1] = M[1];
  tab[2] = M[2];
  
}
