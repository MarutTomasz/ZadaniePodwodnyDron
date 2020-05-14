#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN

#include "Obiekt3D.hh"

/*!
 * \file
 * \brief Definicja klasy Prostopadloscian
 *
 * Plik zawiera definicje klasy Prostopadloscian, która
 * dziedzicy publicznie po klasie Obiekt3D \n
 * Zawiera także deklaracje metod operujących 
 * na prostopadłościanie.
 */
class Prostopadloscian : public Obiekt3D {
protected:
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
  void Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych) const;

public:
  /*!
   * \brief Konstruktor trójparametryczny prostopadłościanu
   *
   * Konstruktor tworzy prostopadłościan o zadanych w argumentach 
   * wymiarach.
   * \param[in] A_bok - długość boku w osi X
   * \param[in] B_bok - długość boku w osi Y
   * \param[in] C_bok - długość boku w osi Z
   */
  Prostopadloscian(double A_bok,
		   double B_bok,
		   double C_bok);
  void Narysuj() override;
};


#endif
