#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
#include "SMacierzKw.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"

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
  Dron R2D2(20,15,8);
  int liczba = 0;
  double kat;
  double odleglosc;
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a = R2D2.Narysuj(api);
  
  while (liczba != 3){
    cout << "Menu wyboru: \n 1 - obroc drona o kat\n 2 - przesun drona\n 3 - zakoncz dzialanie\n\n Twoj wybor:    ";
    cin >> liczba;
  
    switch(liczba) {
    case 1: {
      cout << "Podaj kat obrotu:    ";
      cin >> kat;
    
      while (kat){
	if (kat >= 1) {
	  kat = kat - 1;
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_Z(1);
	  a = R2D2.Narysuj(api);
	}
	else if (kat <= -1){
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_Z(-1);
	  kat = kat + 1;
	  a = R2D2.Narysuj(api);
	}
	else {
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_Z(1);
	  kat = 0;
	  a = R2D2.Narysuj(api);
	}
      }
    
      break;
    }
      
    case 2: {
      cout << "Podaj odleglosc:    ";
      cin >> odleglosc;
      cout << "Podaj kat nachylenia:    ";
      cin >> kat;
      double kat_kopia = kat;

      while (kat){
	if (kat >= 1) {
	  kat = kat - 1;
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(1);
	  a = R2D2.Narysuj(api);
	}
	else if (kat <= -1){
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(-1);
	  kat = kat + 1;
	  a = R2D2.Narysuj(api);
	}
	else {
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(kat);
	  kat = 0;
	  a = R2D2.Narysuj(api);
	}
      }

      while(odleglosc) {
	if (odleglosc >= 1) {
	  api->erase_shape(a); //usuwa kształt o id a
	  odleglosc = odleglosc - 1;
	  R2D2.Przesun(1);
	  a = R2D2.Narysuj(api);
	}
	else if(odleglosc <= -1) {
	  api->erase_shape(a); //usuwa kształt o id a
	  odleglosc = odleglosc + 1;
	  R2D2.Przesun(-1);
	  a = R2D2.Narysuj(api);
	}
	else {
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Przesun(odleglosc);
	  odleglosc = 0;
	  a = R2D2.Narysuj(api);
	}  
      }
      
      while (kat_kopia){
	if (kat >= 1) {
	  kat_kopia = kat_kopia - 1;
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(-1);
	  a = R2D2.Narysuj(api);
	}
	else if (kat <= -1){
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(1);
	  kat_kopia = kat_kopia + 1;
	  a = R2D2.Narysuj(api);
	}
	else {
	  api->erase_shape(a); //usuwa kształt o id a
	  R2D2.Obrot_X(-kat_kopia);
	  kat_kopia = 0;
	  a = R2D2.Narysuj(api);
	}
      }
 

      break;
    }
      
    case 3: {
      cout << "Program konczy dzialanie!! :) " << endl << endl;
      break;
    }
    }
  }  
  return 0;
}


























/*
  int a= api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  cout << endl << "pojawiły się 2 linie: czarna" << endl;  
  wait4key();
  
  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();
  
  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
  */


