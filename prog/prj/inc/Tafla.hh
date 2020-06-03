#ifndef TAFLA
#define TAFLA
/*!
 * \file
 * \brief Definicja klasy Tafla
 *
 * Plik zawiera definicje klasy Tafla, która
 * dziedzicy publicznie po klasach Powierzchnia i Przeszkoda \n
 * Zawiera także deklaracje metod operujących 
 * na powierzchni reprezentującej tafle wody.
 */

#include "Przeszkoda.hh"
#include "Powierzchnia.hh"
#include "Dron.hh"

/*!
 * \brief Modeluje pojęcie Tafla
 *
 * Klasa Tafla dziedziczy publicznie po klasach Powierzchnia i Przeszkoda.\n
 * Reprezentuje ona płaszczyznę tafli wody zbiornika, w którym ma pływać dron.
 */
class Tafla : public Powierzchnia, public Przeszkoda {
protected:
  /*!
   * \brief Usunięcie bezparametrycznego kontrukotra tafli
   */
  Tafla() = delete;
public:
  /*!
   * \brief Konsturktor jednoparametryczny tafli
   *
   * Konstruktor tworzy powierzchnie tafli wody dopasowaną do 
   * rozmiarów ukłądu współrzędnych w gnuplocie. \n
   * Ustawa kolor rysowania na niebieski.
   * \param[in] wielkosc_palety - rozmiar osi gnuplota od 0 do MAX.
   */
  Tafla(double wielkosc_palety);
  bool czy_kolizja(std::shared_ptr<InterfejsDrona> Inter)const override;
  
};

#endif
