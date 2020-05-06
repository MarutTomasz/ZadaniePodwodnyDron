#include "Prostopadloscian.hh"


Prostopadloscian::Prostopadloscian(unsigned int A_bok, unsigned int B_bok,unsigned int C_bok) {
  A = A_bok;
  B = B_bok;
  C = C_bok;
  Wektor3D Pomocniczy(A/2,B/2,C/2);
  Punkt_Odniesienia = Pomocniczy;
}

void Prostopadloscian::Orientuj_wektor(Wektor3D &W) {
  W = Orientacja * W;
}

void Prostopadloscian::Uzyskaj_wspolrzedne(Wektor3D* tablica_wspolrzednych) {
  Wektor3D pomocniczy = Orientacja * Punkt_Odniesienia;
  Wektor3D przesuniecie_x(A,0,0);
  Wektor3D przesuniecie_y(0,B,0);
  Wektor3D przesuniecie_z(0,0,C);
  (*this).Orientuj_wektor(przesuniecie_x);
  (*this).Orientuj_wektor(przesuniecie_y);
  (*this).Orientuj_wektor(przesuniecie_z);
  
  tablica_wspolrzednych[0] = Pozycja_srodka + pomocniczy;
  tablica_wspolrzednych[1] = Pozycja_srodka + pomocniczy - przesuniecie_x;
  tablica_wspolrzednych[2] = Pozycja_srodka + pomocniczy - przesuniecie_x - przesuniecie_y;
  tablica_wspolrzednych[3] = Pozycja_srodka + pomocniczy - przesuniecie_y;
  tablica_wspolrzednych[4] = Pozycja_srodka + pomocniczy - przesuniecie_z;
  tablica_wspolrzednych[5] = Pozycja_srodka + pomocniczy - przesuniecie_x - przesuniecie_z;
  tablica_wspolrzednych[6] = Pozycja_srodka + pomocniczy - przesuniecie_y - przesuniecie_z - przesuniecie_x;
  tablica_wspolrzednych[7] = Pozycja_srodka + pomocniczy - przesuniecie_y - przesuniecie_z;
}


void Prostopadloscian::ustaw_pozycje(const Wektor3D &Wektor) {
  Pozycja_srodka = Wektor;
}

void Prostopadloscian::ustaw_orientacje(const MacierzOb &Macierz) {
  Orientacja = Macierz;
}



unsigned int Prostopadloscian::Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) {
  Wektor3D tab[8];
  (*this).Uzyskaj_wspolrzedne(tab);
  cout << "TUTAJ" << endl;
  unsigned int tmp = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
      },{
        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
	  }},"blue");//rysuje niebieski graniastosłup
 
  return tmp;
}