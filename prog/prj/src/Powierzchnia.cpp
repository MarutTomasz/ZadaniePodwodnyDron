#include "Powierzchnia.hh"
/*!
 * \file
 * \brief Definicja metod klasy Powierzchnia
 *
 * Zawiera także definicje metod służących opisu
 * powierzchni w przestrzeni.
 */

Powierzchnia::Powierzchnia() {}

Powierzchnia::Powierzchnia(double glebokosc, double wymiar) {
  Wektor3D W(0.0,0.0,glebokosc);
  Pozycja_srodka = W;
  wymiar_palety = wymiar;
}

void Powierzchnia::Orientuj_wektor(Wektor3D &W)const {
  W = Orientacja * W;
}

void Powierzchnia::Uzyskaj_wspolrzedne(std::vector<Wektor3D> &siatka_powierzchni) const {
  for (double l = 3.0; l >= 0.0; l -= 1.0){
    for (double k = 3.0; k >= 1.0; k -= 1.0){
      Wektor3D Punkt_siatki(wymiar_palety * k/(-3.0),wymiar_palety * l/(-3.0),Pozycja_srodka[2]);
      siatka_powierzchni.push_back(Punkt_siatki);
    }
    Wektor3D linia_srodka(0.0,wymiar_palety * l/(-3.0), Pozycja_srodka[2]);
    siatka_powierzchni.push_back(linia_srodka);
    for (double k = 1.0; k <= 3.0; k += 1.0){
      Wektor3D Punkt_siatki(wymiar_palety * k/3.0,wymiar_palety * l/(-3.0),Pozycja_srodka[2]);
      siatka_powierzchni.push_back(Punkt_siatki);
    }
  }
  for (double l = 1.0; l <= 3.0; l += 1.0){
    for (double k = 3.0; k >= 0.0; k -= 1.0){
      Wektor3D Punkt_siatki(wymiar_palety * k/(-3.0),wymiar_palety * l/3.0,Pozycja_srodka[2]);
      siatka_powierzchni.push_back(Punkt_siatki);
    }
    for (double k = 1.0; k <= 3.0; k += 1.0){
      Wektor3D Punkt_siatki(wymiar_palety * k/3.0,wymiar_palety * l/3.0,Pozycja_srodka[2]);
      siatka_powierzchni.push_back(Punkt_siatki);
    }
  }  
}




void Powierzchnia::Narysuj() {
  std::vector<Wektor3D> tab;
  Uzyskaj_wspolrzedne(tab);
  ///// ????
  api->erase_shape(ID); //usuwa kształt o id a
  ///// ????
  cout  << "JEDEN" << endl;
  api->draw_surface(vector<vector<Point3D> > {{
   drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]),
    drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2])
      },{
   drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2]), drawNS::Point3D(tab[8][0],tab[8][1],tab[8][2]), drawNS::Point3D(tab[9][0],tab[9][1],tab[9][2]), drawNS::Point3D(tab[10][0],tab[10][1],tab[10][2]),
    drawNS::Point3D(tab[11][0],tab[11][1],tab[11][2]), drawNS::Point3D(tab[12][0],tab[12][1],tab[12][2]), drawNS::Point3D(tab[13][0],tab[13][1],tab[13][2])
      },{
   drawNS::Point3D(tab[14][0],tab[14][1],tab[14][2]), drawNS::Point3D(tab[15][0],tab[15][1],tab[15][2]), drawNS::Point3D(tab[16][0],tab[16][1],tab[16][2]), drawNS::Point3D(tab[17][0],tab[17][1],tab[17][2]),
    drawNS::Point3D(tab[18][0],tab[18][1],tab[18][2]), drawNS::Point3D(tab[19][0],tab[19][1],tab[19][2]), drawNS::Point3D(tab[20][0],tab[20][1],tab[20][2])
      },{
   drawNS::Point3D(tab[21][0],tab[21][1],tab[21][2]), drawNS::Point3D(tab[22][0],tab[22][1],tab[22][2]), drawNS::Point3D(tab[23][0],tab[23][1],tab[23][2]), drawNS::Point3D(tab[24][0],tab[24][1],tab[24][2]),
    drawNS::Point3D(tab[25][0],tab[25][1],tab[25][2]), drawNS::Point3D(tab[26][0],tab[26][1],tab[26][2]), drawNS::Point3D(tab[27][0],tab[27][1],tab[27][2])
      },{
   drawNS::Point3D(tab[28][0],tab[28][1],tab[28][2]), drawNS::Point3D(tab[29][0],tab[29][1],tab[29][2]), drawNS::Point3D(tab[30][0],tab[30][1],tab[30][2]), drawNS::Point3D(tab[31][0],tab[31][1],tab[31][2]),
    drawNS::Point3D(tab[32][0],tab[32][1],tab[32][2]), drawNS::Point3D(tab[33][0],tab[33][1],tab[33][2]), drawNS::Point3D(tab[34][0],tab[34][1],tab[34][2])
      },{
   drawNS::Point3D(tab[35][0],tab[35][1],tab[35][2]), drawNS::Point3D(tab[36][0],tab[36][1],tab[36][2]), drawNS::Point3D(tab[37][0],tab[37][1],tab[37][2]), drawNS::Point3D(tab[38][0],tab[38][1],tab[38][2]),
    drawNS::Point3D(tab[39][0],tab[39][1],tab[39][2]), drawNS::Point3D(tab[40][0],tab[40][1],tab[40][2]), drawNS::Point3D(tab[41][0],tab[41][1],tab[41][2])
      },{
   drawNS::Point3D(tab[42][0],tab[42][1],tab[42][2]), drawNS::Point3D(tab[43][0],tab[43][1],tab[43][2]), drawNS::Point3D(tab[44][0],tab[44][1],tab[44][2]), drawNS::Point3D(tab[45][0],tab[45][1],tab[45][2]),
    drawNS::Point3D(tab[46][0],tab[46][1],tab[46][2]), drawNS::Point3D(tab[47][0],tab[47][1],tab[47][2]), drawNS::Point3D(tab[48][0],tab[48][1],tab[48][2])
 	  }},kolor);//rysuje szarą powierzchnie




}
