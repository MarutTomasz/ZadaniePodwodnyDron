#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN

#include "Obiekt3D.hh"

class Prostopadloscian : public Obiekt3D {
public:
  unsigned int A;
  unsigned int B;
  unsigned int C;
  Prostopadloscian() = delete;
  Prostopadloscian(unsigned int A_bok,
		   unsigned int B_bok,
		   unsigned int C_bok);
  unsigned int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) override;
  void ustaw_pozycje(const Wektor3D &Wektor) override;
  void ustaw_orientacje(const MacierzOb &Macierz)override;

  void Orientuj_wektor(Wektor3D &W);
  void Uzyskaj_wspolrzedne(Wektor3D* tablica_wspolrzednych);
};


#endif
