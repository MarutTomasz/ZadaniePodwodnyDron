#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "SMacierzKw.hh"
#include "MacierzOb.hh"
#include "Prostopadloscian.hh"
#include "GraniastoslupHex.hh"
#include "Powierzchnia.hh"
#include "InterfejsDrona.hh"
#include "Przeszkoda.hh"
#include "Dron.hh"
#include "Dno.hh"
#include "Tafla.hh"
#include "PrzeszkodaPros.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

int main() {
  // SEKCJA ZMIENNYCH POMOCNICZYCH
  char znak = 'i';
  double kat;
  double odleglosc;
  
  // SEKCJA PARAMETRYZOWANIA WYMIAROW OBIEKTOW
  double A = 200;
  double B = 10;
  double C = 15;
  double D = 13;
  
  // SEKCJA BUDOWANIA WSKAZNIKOW I KONTENEROW
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-A,A,-A,A,-A,A,0));
  std::shared_ptr<Dron> R2D1(new Dron(3*B,4*B,2*B));
  std::shared_ptr<Dron> R2D2(new Dron(3*C,4*C,2*C));
  std::shared_ptr<Dron> R2D3(new Dron(3*D,4*D,2*D));
  std::shared_ptr<Dno> Ziemia(new Dno(A));
  std::shared_ptr<Tafla> Woda(new Tafla(A));
  std::shared_ptr<PrzeszkodaPros> Obiekt_1(new PrzeszkodaPros(100,100,100));
  std::shared_ptr<PrzeszkodaPros> Obiekt_2(new PrzeszkodaPros(60,120,70));
  std::shared_ptr<PrzeszkodaPros> Obiekt_3(new PrzeszkodaPros(100,70,50));
  std::vector<std::shared_ptr<InterfejsDrona> > kolekcja_dronow;
  std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
  
  // SEKCJA WKLADANIA WSKAZNIKOW DO KONTENEROW
  kolekcja_przeszkod.push_back(R2D1);
  kolekcja_przeszkod.push_back(R2D2);
  kolekcja_przeszkod.push_back(R2D3);
  kolekcja_przeszkod.push_back(Ziemia);
  kolekcja_przeszkod.push_back(Woda);
  kolekcja_przeszkod.push_back(Obiekt_1);
  kolekcja_przeszkod.push_back(Obiekt_2);
  kolekcja_przeszkod.push_back(Obiekt_3);
  kolekcja_dronow.push_back(R2D1);
  kolekcja_dronow.push_back(R2D2);
  kolekcja_dronow.push_back(R2D3);
  
  // SEKCJA USTAWIANIA SPI
  R2D1->set_api(api);
  R2D2->set_api(api);
  R2D3->set_api(api);
  Ziemia->set_api(api);
  Woda->set_api(api);
  Obiekt_1->set_api(api);
  Obiekt_2->set_api(api);
  Obiekt_3->set_api(api);
  
  // SEKCJA USTALANIA POZYCJI 
  R2D1->Przesun(60.0,70.0,40.0);
  R2D3->Przesun(-90.0,130.0,-160.0);
  Obiekt_1->set_pozycja_srodka(-130,-100,-140);
  Obiekt_2->set_pozycja_srodka(140,100,-140);
  Obiekt_3->set_pozycja_srodka(100,-100,100);
  
  // SEKCJA DODAWANIA KOLEKCJI PRZESZOD
  R2D1->set_kolekcja_przeszkod(kolekcja_przeszkod);
  R2D2->set_kolekcja_przeszkod(kolekcja_przeszkod);
  R2D3->set_kolekcja_przeszkod(kolekcja_przeszkod);
  
  // SEKCJA RYSOWANIA PIERWOTNEGO
  Ziemia->Narysuj();
  Woda->Narysuj();
  Obiekt_1->Narysuj();
  Obiekt_2->Narysuj();
  Obiekt_3->Narysuj();
  R2D1->Narysuj();
  R2D2->Narysuj();
  R2D3->Narysuj();

  // SEKCJA PROGRAMU WYKONYWALNEGO
  while (znak != 'q'){
    cout << "Menu wyboru: \n o - obroc drona o kat\n p - przesun drona\n q - zakoncz dzialanie\n\n Twoj wybor:    ";
    cin >> znak;
  
    if(znak == 'o'){
      cout << "Podaj kat obrotu:    ";
      cin >> kat;
      R2D2->Obrot_Z_Animowany(kat);
    }
    
    else if(znak == 'p'){
      cout << "Podaj odleglosc:    ";
      cin >> odleglosc;
      cout << "Podaj kat nachylenia:    ";
      cin >> kat;
      R2D2->Plyn(odleglosc,kat);
    }
      
    else if(znak == 'q'){
      cout << "Program konczy dzialanie!! :) " << endl << endl;
    }
    else
      cout << "Niepoprawny znak opcji" << endl << endl;
    
  }
  return 0;
}



