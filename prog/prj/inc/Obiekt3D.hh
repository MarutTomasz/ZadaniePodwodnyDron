#ifndef OBIEKT_3D
#define OBIEKT_3D

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;



class Obiekt3D {
public:
  Wektor3D Pozycja_srodka;
  Wektor3D Punkt_Odniesienia;
  MacierzOb Orientacja;
  virtual unsigned int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;
  virtual void ustaw_pozycje(const Wektor3D &Wektor) = 0;
  virtual void ustaw_orientacje(const MacierzOb &Macierz) = 0;



};


#endif
