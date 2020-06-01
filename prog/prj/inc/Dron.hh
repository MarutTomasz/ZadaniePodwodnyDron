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
 * po klasach InterfejsDrona, Prostopadloscian i
 * Przeszkoda.\n
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
   * \brief Wskazniki na przeszkody
   *
   * Pole przechowujące wskaźniki na wszystkie 
   * przzeszkody znajdujące się w zbiorniku.
   */
  std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;
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
  void Narysuj() override;
  /*!
   * \brief Metoda inicjalizuje w dronie wskaźnik na kolekcje przeszkód.
   */
  void set_kolekcja_przeszkod( std::vector<std::shared_ptr<Przeszkoda> > kolekcja);
  void Plyn(double odleglosc, double kat) override;
  void Obrot_Z_Animowany(double stopnie) override;
  bool czy_kolizja(InterfejsDrona *Inter) override;
  void Przesun(double X, double Y, double Z) override;
  void Przesun(const Wektor3D Wektor) override;

};

#endif
