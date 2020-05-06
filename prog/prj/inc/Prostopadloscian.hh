#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN

#include "Obiekt3D.hh"

/*!
 * \file
 * \brief Definicja klasy Prostopadloscian
 *
 * Plik zawiera definicje klasy MacierzOb, która
 * dziedzicy publicznie po klasie MacierzKw \n
 * Zawiera także deklaracje metod działających 
 * na macierzach obrotu.
 */
class Prostopadloscian : public Obiekt3D {
public:
  /*!
   * \brief Długość boku w osi X
   *
   * Zmienna przechowująca długość boku 
   * prostopadłościanu w osi X
   */
  double A;
  /*!
   * \brief Długość boku w osi Y
   *
   * Zmienna przechowująca długość boku 
   * prostopadłościanu w osi Y
   */
  double B;
  /*!
   * \brief Długość boku w osi Z
   *
   * Zmienna przechowująca długość boku 
   * prostopadłościanu w osi Z
   */
  double C;
  /*!
   * \brief Konstruktor bezparametryczny prostopadloscianu
   *
   * Kontruktor tworzy prostopadloscian bez inicjacji wymiarów.
   */
  Prostopadloscian(); 
  /*!
   * \brief Konstruktor trójparametryczny prostopadłościanu
   *
   * Konstruktor tworzy prostopadłościan o zadanych w argumentach 
   * wymiarach.
   */
  Prostopadloscian(double A_bok,
		   double B_bok,
		   double C_bok);
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
