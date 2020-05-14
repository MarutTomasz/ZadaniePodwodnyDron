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
   * \brief Macierz orietnacji obiektu.
   *
   * Macierz jest macierzą obrotu układu współrzędnych
   * zaczepionego w obiekcie względem głównego układu
   * współrzędnych.
   */
  MacierzOb Orientacja;
  /*!
   * \brief ID figury w gnuplocie
   *
   * Zmienna obiektu wykorzystywana 
   * przez gnuplota to zapamiętywania 
   * obiektów;
   */
  int ID;
  /*!
   * \brief wskaznik na gnuplota
   *
   * Przechowuje wskaznik do otwartego
   * programu gnuplot;
   */
  std::shared_ptr<drawNS::Draw3DAPI> api;
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
   * \brief Ustawia nowy wektor środka obiektu
   *
   * Metoda zmienia wektor położenia obiektu, tzn. przesuwa obiekt 
   * na nowe położenie w przestrzeni.
   * \param[in] Wektor - nowy wektor położenia obiektu.
   */
  void ustaw_pozycje(const Wektor3D &Wektor) { Pozycja_srodka = Wektor; }
  /*!
   * \brief Ustawia nowy macierz orientacje obiektu
   * 
   * Metoda zmienia macierz orientacji obiektu w przestrzeni, tzn
   * obraca obiekt.
   * \param[in] Macierz - nowa macierz orientacji obiektu w przestrzeni.
   */
  void ustaw_orientacje(const MacierzOb &Macierz) { Orientacja = Macierz; }
  /*!
   * \brief Ustawia wskaznik na gnuplot
   * 
   * Metoda inicjuje wskaznik na gnuplot
   * \param[in] API - wskaznik na gnuplot.
   */
  void set_api(std::shared_ptr<drawNS::Draw3DAPI> API) {api = API;}
  /*!
   * \brief Rysowanie obiektu
   *
   * Funkcja wykonuje rysunek obiektu w zadanym programie zewnętrznym.
   * Wykorzystywane są wektory położenia środka obiekty i punktu odniesienia
   * oraz macierz orientacji obiektu w przestrzeni.
   */
  virtual void Narysuj() = 0;
};


#endif
