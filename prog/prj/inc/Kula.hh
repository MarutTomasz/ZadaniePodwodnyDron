#ifndef KULA
#define KULA

#include "Obiekt3D.hh"

class Kula : public Obiekt3D {
public:
  /*!
   * \brief Długość średnicy
   *
   * Zmienna przechowująca długość średnicy kuli.
   */
  double srednica;
  /*!
   * \brief Konstruktor bezparametryczny kuli
   *
   * Kontruktor tworzy kule bez inicjacji średnicy.
   */
  Kula(); 
  /*!
   * \brief Konstruktor jednoparametryczny kuli
   *
   * Konstruktor tworzy kule o zadanej średnicy.
   */
  Kula(srednica A_bok);
  
  unsigned int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) const override;
  void ustaw_pozycje(const Wektor3D &Wektor) override;
  void ustaw_orientacje(const MacierzOb &Macierz) override;

  /*!
   * \brief Metoda orientująca wektor
   *
   * Metoda orientuje wektor z układu współrzędnych zintegrowanych z obiektem
   * na globalny układ współrzędnych
   * \param[in] W - Orientowany wektor.
   */
  void Orientuj_wektor(Wektor3D &W) const;
  /*!
   * \brief Uzyskiwanie wspołrzędnych wierzchołków
   *
   * Metoda uzyskuje współrzędne wierzchiłków w układzie globalnym
   * wykorzystując relację między długością boków, orientacją i 
   * punktem odniesienia;
   * \param[in] tablica_wspolrzednych - tablica na współrzędne wierzchołków
   * względem globalnego układu współrzędnych.
   */
  void Uzyskaj_wspolrzedne(Wektor3D* tablica_wspolrzednych) const;
};


#endif
