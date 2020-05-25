#ifndef DRON
#define DRON
/*!
 * \file
 * \brief Definicja klasy Dron
 *
 * Plik zawiera definicje klasy Dron.\n
 * Zawiera także deklaracje metod służących do 
 * obsługi drona.
 */

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "Przeszkoda.hh"
 
/*!
 * \brief Modeluje pojęcie Dron
 *
 * Definiuje klase Dron, ktora dziedziczy publicznie
 * po klasie InterfejsDrona i Prostopadloscian.\n
 * Zawiera deklaracje metod służących
 * do obsługi drona.
 */
class Dron: public Prostopadloscian, public InterfejsDrona, public Przeszkoda {
protected:
  /*!
   * \brief Pole prawej śruby drona
   *
   * Pole reprezentuje prawą śrubę silnika drona
   */
  Sruba Prawa;
  /*!
   * \brief Pole lewej śruby drona
   *
   * Pole reprezentuje lewą śrubę silnika drona
   */
  Sruba Lewa;
  /*!
   * \brief Przesunięcie lewej śruby
   *
   * Pole reprezentuje odsunięcie lewej śruby od 
   * centralnego punktu drona. Wyrazone w stałym układzie
   * między dronem z śrubą. Ustalane jednokrotnie podczas
   * konstrukcji drona.
   */
  Wektor3D Odsuniecie_sruby_lewej;
  /*!
   * \brief Przesunięcie prawej śruby
   *
   * Pole reprezentuje odsunięcie prawej śruby od 
   * centralnego punktu drona. Wyrazone w stałym układzie
   * między dronem z śrubą. Ustalane jednokrotnie podczas
   * konstrukcji drona.
   */
  Wektor3D Odsuniecie_sruby_prawej;  
  /*!
   * \brief Usunięcie konstruktora bezparametrycznego
   */
  Dron() = delete;
  void Obrot_Z(double stopnie) override;
  void Obrot_X(double stopnie) override;
  void Obrot_Y(double stopnie) override;
  void Przesun(double odleglosc) override;

public:
  /*!
   * \brief Kontruktor trójparametryczny drona
   *
   * Tworzy obiekt klasy Dron o zadanych wymiarach.
   * \param[in] bok_A - długość boku w osi X.
   * \param[in] bok_B - długość boku w osi Y.
   * \param[in] bok_C - długość boku w osi Z.
   */
  Dron(double bok_A, double bok_B, double bok_C);
  /*!
   * \brief Ustawia wskaznik na gnuplot
   * 
   * Metoda inicjuje wskaznik na gnuplot do 
   * wszystkich elementów drona.
   * \param[in] API - wskaznik na gnuplot.
   */
  void set_api(std::shared_ptr<drawNS::Draw3DAPI> API);
  /*!
   * \brief Metoda rysuje wszystkie elementy drona
   * 
   * Metoda rysuje po kolei każdy element drona; 
   */
  void Rysuj();
  
  void Plyn(double odleglosc, double kat) override;
  void Obrot_Z_Animowany(double stopnie) override;
  
  bool czy_kolizja(std::shared_ptr<InterfejsDrona> Inter) override;
  
};

#endif
