#include "Dron.hh"
/*!
 * \file
 * \brief Definicja metod klasy Dron
 *
 * Zawiera także definicje metod służących do 
 * obsługi drona.
 */

Dron::Dron(double bok_A, double bok_B, double bok_C) {
  if(bok_A < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(bok_B < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  if(bok_C < 0){
    cout << "Dlugosc boku nie moze miec wartosci ujemnej" << endl;
    exit(1);
  }
  A = bok_A;
  B = bok_B;
  C = bok_C;
  Lewa.Set_Wymiary(C/3,A/5);
  Prawa.Set_Wymiary(C/3,A/5);
  
  Wektor3D Lewy((-A*3/5),(-B/4),0.0);
  Odsuniecie_sruby_lewej = Lewy;
  Lewa.set_pozycja_srodka(Lewy);
  
  Wektor3D Prawy((-A*3/5),(B/4),0.0);
  Odsuniecie_sruby_prawej = Prawy;
  Prawa.set_pozycja_srodka(Prawy);
}

void Dron::set_api(std::shared_ptr<drawNS::Draw3DAPI> API) {
  Prostopadloscian::set_api(API);
  Lewa.set_api(API);
  Prawa.set_api(API);
}

void Dron::Obrot_Z(double stopnie) {
  MacierzOb Obrot('z',stopnie);
  Orientacja = Orientacja * Obrot;
  Lewa.Obrot_z_dronem(Odsuniecie_sruby_lewej,Obrot,Orientacja);
  Prawa.Obrot_z_dronem(Odsuniecie_sruby_prawej,Obrot,Orientacja);
}

void Dron::Obrot_X(double stopnie) {
  MacierzOb Obrot('x',stopnie);
  Orientacja = Orientacja * Obrot; 
  Lewa.Obrot_z_dronem(Odsuniecie_sruby_lewej,Obrot,Orientacja);
  Prawa.Obrot_z_dronem(Odsuniecie_sruby_prawej,Obrot,Orientacja);
}

void Dron::Obrot_Y(double stopnie) {
  MacierzOb Obrot('y',stopnie);
  Orientacja = Orientacja * Obrot;
  Lewa.Obrot_z_dronem(Odsuniecie_sruby_lewej,Obrot,Orientacja);
  Prawa.Obrot_z_dronem(Odsuniecie_sruby_prawej,Obrot,Orientacja);
}

void Dron::Przesun(double odleglosc) {
  Wektor3D przesuniecie(odleglosc,0,0);      
  (*this).Orientuj_wektor(przesuniecie);
  Pozycja_srodka = Pozycja_srodka + przesuniecie;
  Lewa.Przesun(odleglosc);
  Prawa.Przesun(odleglosc);
}  

void Dron::Obrot_Z_Animowany(double kat) {
  while (kat){
    if (kat >= 1) {
      kat = kat - 1;
      Obrot_Z(1); 
      Lewa.Obracaj();
      Narysuj();
      usleep(10000);
    }
    else if (kat <= -1){
      Obrot_Z(-1);
      Prawa.Obracaj();
      kat = kat + 1;
      Narysuj();
      usleep(10000);
    }
    else {
      Obrot_Z(kat);
      Prawa.Obracaj();
      Lewa.Obracaj();
      kat = 0;
      Narysuj();
      usleep(10000);
    }
  }
}

void Dron::Plyn(double odleglosc, double kat) {
  double kat_kopia = kat;

  while (kat){
    if (kat >= 1) {
      kat = kat - 1;
      Obrot_Y(-1);
      Narysuj();
      usleep(10000);
    }
    else if (kat <= -1){
      Obrot_Y(1);
      kat = kat + 1;
      Narysuj();
      usleep(10000);
    }
    else {
      Obrot_Y(kat);
      kat = 0;
      Narysuj();
      usleep(10000);
    }
  }

  while(odleglosc) {
    if (odleglosc >= 1) {
      odleglosc = odleglosc - 1;
      Przesun(1);
      Prawa.Obracaj();
      Lewa.Obracaj();
      Narysuj();
      usleep(7000);
    }
    else if(odleglosc <= -1) {
      odleglosc = odleglosc + 1;
      Przesun(-1);
      Prawa.Obracaj();
      Lewa.Obracaj();
      Narysuj();
      usleep(7000);
    }
    else {
      Przesun(odleglosc);
      Prawa.Obracaj();
      Lewa.Obracaj();
      odleglosc = 0;
      Narysuj();
      usleep(7000);
    }  
  }
      
  while (kat_kopia){
    if (kat_kopia >= 1) {
      kat_kopia = kat_kopia - 1;
      Obrot_Y(1);
      Narysuj();
      usleep(10000);
    }
    else if (kat_kopia <= -1){
      Obrot_Y(-1);
      kat_kopia = kat_kopia + 1;
      Narysuj();
      usleep(10000);
    }
    else {
      Obrot_Y(-kat_kopia);
      kat_kopia = 0;
      Narysuj();
      usleep(10000);
    }
  }   
}


void Dron::Narysuj() {
  Prostopadloscian::Narysuj();
  Lewa.Narysuj();
  Prawa.Narysuj();
}


bool Dron::czy_kolizja(std::shared_ptr<InterfejsDrona> Inter) {
  cout << "YES or NO" << endl;
  return 1;
}
  
