#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN
/*!
 * \file
 * \brief Definicja klasy Prostopadloscian
 *
 * Plik zawiera definicje klasy Prostopadloscian, która
 * dziedzicy publicznie po klasie Obiekt3D \n
 * Zawiera także deklaracje metod operujących 
 * na prostopadłościanie.
 */

#include "Obiekt3D.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"

/*!
 * \brief Modeluje pojęcie Prostopadloscian
 *
 * Klasa Prostopadloscian dziedziczy publicznie po klasie Obiekt3D.\n
 * Reprezentuje ona prostopadłościan w przestrzeni.
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

  void Orientuj_wektor(Wektor3D &W) const override;
  /*!
   * \brief Uzyskiwanie wspołrzędnych wierzchołków
   *
   * Metoda uzyskuje współrzędne wierzchiłków w układzie globalnym
   * wykorzystując relację między długością boków i orientacją i 
   * punktem środka obiektu.
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
  /*!
   * \brief Pobranie wybranego boku obiektu
   *
   * Metoda pobiera długość wskazanego boku.\n
   * 1 - Bok A, który leży w osi X\n
   * 2 - Bok B, który leży w osi Y\n
   * 3 - Bok C, który leży w osi Z\n
   * \param[in] bok - określa który bok mamy pobrać.
   * \return Długość wskazanego boku.
   */
  double get_bok(double bok) const;
  void Narysuj() override;
  
};


#endif
