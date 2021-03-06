#include "Prostopadloscian.hh"

/*!
 * \file
 * \brief Definicja metod klasy Prostopadloscian
 *
 * Plik zawiera definicje metod działających 
 * na obiektach klasy Prostopadloscian.
 */

Prostopadloscian::Prostopadloscian() {}

Prostopadloscian::Prostopadloscian(double A_bok,double B_bok,double C_bok) {
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

void Prostopadloscian::Orientuj_wektor(Wektor3D &W)const {
  W = Orientacja * W;
}

void Prostopadloscian::Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych) const {
  Wektor3D przesuniecie_x(A/2,0,0);
  Wektor3D przesuniecie_y(0,B/2,0);
  Wektor3D przesuniecie_z(0,0,C/2);
  (*this).Orientuj_wektor(przesuniecie_x);
  (*this).Orientuj_wektor(przesuniecie_y);
  (*this).Orientuj_wektor(przesuniecie_z);
  
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x + przesuniecie_y + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x - przesuniecie_y + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x - przesuniecie_y + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x + przesuniecie_y + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x + przesuniecie_y - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x - przesuniecie_y - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x - przesuniecie_y - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x + przesuniecie_y - przesuniecie_z);
 }

void Prostopadloscian::Narysuj() {
  std::vector<Wektor3D> tab;
  (*this).Uzyskaj_wspolrzedne(tab);
  if (ID != -1)
    api->erase_shape(ID);

  ID = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
      },{
        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
	  }},kolor);
}

double Prostopadloscian::get_bok(double bok) const {
  if(bok == 1)
    return A;
  else if(bok == 2)
    return B;
  else if(bok == 3)
    return C;
  else {
    cout << "Nieprawidlowy bok. Mozliwe do wyboru to A, B, C" << endl;
    exit(1);
  }
}
