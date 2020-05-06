#include "MacierzOb.hh"

MacierzOb::MacierzOb(const MacierzKw<double,3> &M) : MacierzKw<double,3>(M) {
  if(tab[0] * tab[1] != 0){
    cout << "Macierz nie jest ortonormalna" << endl;
    exit(1);
  }
  if(tab[1] * tab[2] != 0){
    cout << "Macierz nie jest ortonormalna" << endl;
    exit(1);
  }
  if(tab[0] * tab[2] != 0){
    cout << "Macierz nie jest ortonormalna" << endl;
    exit(1);
  }
  if((*this).wyznacznik(Laplace) != 1){
    cout << "Macierz nie jest ortonormalna" << endl;
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
