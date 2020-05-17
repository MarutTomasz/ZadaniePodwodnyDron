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
  double B = 10;
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-A,A,-A,A,-A,A,0));
  
  Dron R2D2(3*B,4*B,2*B);
  R2D2.set_api(api);
  Dno Nr1(A);
  Tafla Nr2(A);
  Nr1.set_api(api);
  Nr2.set_api(api);

  int liczba = 0;
  double kat;
  double odleglosc;
  Nr1.Narysuj();
  Nr1.Narysuj();
  Nr2.Narysuj();
  R2D2.Rysuj();
  
 
  while (liczba != 3){
    cout << "Menu wyboru: \n 1 - obroc drona o kat\n 2 - przesun drona\n 3 - zakoncz dzialanie\n\n Twoj wybor:    ";
    cin >> liczba;
  
    switch(liczba) {
    case 1: {
      cout << "Podaj kat obrotu:    ";
      cin >> kat;
      R2D2.Obrot_Z_Animowany(kat);
      break;
    }
      
    case 2: {
      cout << "Podaj odleglosc:    ";
      cin >> odleglosc;
      cout << "Podaj kat nachylenia:    ";
      cin >> kat;
      R2D2.Plyn(odleglosc,kat);
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


