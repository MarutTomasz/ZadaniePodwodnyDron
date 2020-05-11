#ifndef OBIEKT_3D
#define OBIEKT_3D

/*!
 * \file
 * \brief Definicja abstrakcyjnej klasy Obiekt3D
 *
 * Plik zawiera definicje abstrakcyjnej klasy Obiekt3D.
 * Zawiera deklaracje podstawowych pojęć charakteruzujących
 * obiekt w przestrzeni trójwymiarowej.
 */

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;



/*!
 * \brief Modeluje pojęcie Obiekt3D
 *
 * Zawiera elementy charakteryzujące każdy
 * obiekt w przestrzni i deklaracje funkcji
 * do zmiany tych elementów
 */
class Obiekt3D {
protected:
  /*!
   * \brief Wektor położenia środka obiektu.
   */
  Wektor3D Pozycja_srodka;
  /*!
   * \brief Wektor położenia punktu odniesienia.
   *
   * Punkt odniesienia służy do określenia wierzchołków lub
   * innych istotnych punktów obiektu 3D. Najczęsciej jest 
   * to jeden z wierzchołków figury.
   */
  Wektor3D Punkt_Odniesienia;
  /*!
   * \brief Macierz orietnacji obiektu.
   *
   * Macierz jest macierzą obrotu układu współrzędnych
   * zaczepionego w obiekcie względem głównego układu
   * współrzędnych.
   */
  MacierzOb Orientacja;
  /*!
   * \brief Bezparametryczny konstruktor obiektu.
   *
   * Konstruktor wykorzystywany przy tworzeniu 
   * obiektów klas pochodnych. Nie pozwala samemu 
   * stworzyć obiektu 3D. 
   */
  Obiekt3D() {};
public:
  /*!
   * \brief Rysowanie obiektu
   *
   * Funkcja wykonuje rysunek obiektu w zadanym programie zewnętrznym.
   * Wykorzystywane są wektory położenia środka obiekty i punktu odniesienia
   * oraz macierz orientacji obiektu w przestrzeni.
   * \param[in] api - wskaźnik na zewnętrzny program graficzny.
   * \return Id w którym przechowywany jest obiekt w gnuplocie.
   */
  virtual unsigned int Narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) const = 0;
  /*!
   * \brief Ustawia nowy wektor środka obiektu
   *
   * Metoda zmienia wektor położenia obiektu, tzn. przesuwa obiekt 
   * na nowe położenie w przestrzeni.
   * \param[in] Wektor - nowy wektor położenia obiektu.
   */
  virtual void ustaw_pozycje(const Wektor3D &Wektor) = 0;
  /*!
   * \brief Ustawia nowy macierz orientacje obiektu
   * 
   * Metoda zmienia macierz orientacji obiektu w przestrzeni, tzn
   * obraca obiekt.
   * \param[in] Macierz - nowa macierz orientacji obiektu w przestrzeni.
   */
  virtual void ustaw_orientacje(const MacierzOb &Macierz) = 0;

};


#endif
