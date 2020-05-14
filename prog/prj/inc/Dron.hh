#ifndef DRON
#define DRON
/*!
 * \file
 * \brief Definicja klasy Dron
 *
 * Plik zawiera definicje klasy Dron.\n
 * Zawiera także deklaracje metod i funkcji służących do 
 * obsługi drona.
 */

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"

/*!
 * \brief Modeluje pojęcie Dron
 *
 * Definiuje klase Dron, ktora dziedziczy publicznie
 * po klasie InterfejsDrona i Prostopadloscian.\n
 * Zawiera deklaracje funkcji służących
 * do obsługi drona.
 */
class Dron: public Prostopadloscian, public InterfejsDrona {
protected:
  Sruba Prawa;
  Sruba Lewa;
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
  void Plyn(double odleglosc, double kat) override;
  void Obrot_Animowany(double stopnie) override;


  void Rysuj();

  
};

#endif
