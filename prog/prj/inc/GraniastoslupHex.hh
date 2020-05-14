#ifndef GRANIASTOSLUPHEX
#define GRANIASTOSLUPHEX

#include "Obiekt3D.hh"

/*!
 * \file
 * \brief Definicja klasy GraniastoslupHex
 *
 * Plik zawiera definicje klasy GraniastoslupHex, która
 * dziedzicy publicznie po klasie Obiekt3D\n
 * Zawiera także deklaracje metod operujących na 
 * graniastosłupie prawidłowym sześciokątnym.
 */
class GraniastoslupHex : public Obiekt3D {
protected:
  /*!
   * \brief Długość boku podstawy
   *
   * Zmienna przechowująca długość podstawy
   * graniastosłupa.
   */
  double A;
  /*!
   * \brief Wysokość graniastosłupa
   *
   * Zmienna przechowująca wysokość
   * graniastosłupa/
   */
  double H;
  /*!
   * \brief Konstruktor bezparametryczny graniastoslupa
   *
   * Kontruktor tworzy graniastoslup bez inicjacji wymiarów.
   */
  GraniastoslupHex(); 
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
   * punktem środka obiektu;
   * \param[in] tablica_wspolrzednych - tablica na współrzędne wierzchołków
   * względem globalnego układu współrzędnych.
   */
  void Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych) const;

public:
  /*!
   * \brief Konstruktor dwuparametryczny graniastoslupa
   *
   * Konstruktor tworzy graniastoslup prawidlowy
   * sześciokątny o zadanych w argumentach wymiarach.
   * \param[in] A_bok - długość krawędzi podstawy.
   * \param[in] H_bok - długość wysokości.
   */
  GraniastoslupHex(double A_bok,
		   double H_bok);
  void Narysuj() override;
};


#endif
