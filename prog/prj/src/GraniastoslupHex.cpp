#include "GraniastoslupHex.hh"


/*!
 * \file
 * \brief Definicja metod klasy GraniastoslupHex
 *
 * Plik zawiera definicje metod działających 
 * na obiektach klasy GraniastoslupHex.
 */

GraniastoslupHex::GraniastoslupHex() {}

GraniastoslupHex::GraniastoslupHex(double A_bok,double H_bok) {
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

void GraniastoslupHex::Orientuj_wektor(Wektor3D &W)const {
  W = Orientacja * W;
}

void GraniastoslupHex::Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych)const {
  Wektor3D przesuniecie_x(H/2,0,0);
  Wektor3D przesuniecie_y(0,A,0);
  Wektor3D przesuniecie_y2(0,A/2,0);
  Wektor3D przesuniecie_z(0,0,A*sqrt(3)/2);
  Orientuj_wektor(przesuniecie_x);
  Orientuj_wektor(przesuniecie_y);
  Orientuj_wektor(przesuniecie_y2);
  Orientuj_wektor(przesuniecie_z);
  
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x + przesuniecie_y);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x + przesuniecie_y2 + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x - przesuniecie_y2 + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x - przesuniecie_y);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x - przesuniecie_y2 - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka + przesuniecie_x + przesuniecie_y2 - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x + przesuniecie_y);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x + przesuniecie_y2 + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x - przesuniecie_y2 + przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x - przesuniecie_y);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x - przesuniecie_y2 - przesuniecie_z);
  tablica_wspolrzednych.push_back(Pozycja_srodka - przesuniecie_x + przesuniecie_y2 - przesuniecie_z);
}

void GraniastoslupHex::Narysuj() {
  std::vector<Wektor3D> tab;
  Uzyskaj_wspolrzedne(tab);
  if (ID != -1)
    api->erase_shape(ID);

  ID = api->draw_polyhedron(vector<vector<Point3D> > {{
       drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]),
       drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]), drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])
      },{
       drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2]), drawNS::Point3D(tab[8][0],tab[8][1],tab[8][2]),
    drawNS::Point3D(tab[9][0],tab[9][1],tab[9][2]), drawNS::Point3D(tab[10][0],tab[10][1],tab[10][2]), drawNS::Point3D(tab[11][0],tab[11][1],tab[11][2])
	  }},kolor);
}
