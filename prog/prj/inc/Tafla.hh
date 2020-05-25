#ifndef TAFLA
#define TAFLA
/*!
 * \file
 * \brief Definicja klasy Tafla
 *
 * Plik zawiera definicje klasy Tafla, która
 * dziedzicy publicznie po klasie Powierzchnia \n
 * Zawiera także deklaracje metod operujących 
 * na powierzchni reprezentującej tafle wody.
 */

#include "Powierzchnia.hh"

/*!
 * \brief Modeluje pojęcie Tafla
 *
 * Klasa Tafla dziedziczy publicznie po klasie Powierzchnia.\n
 * Reprezentuje ona płaszczyznę tafli wody zbiornika, w którym ma pływać dron.
 */
class Tafla : public Powierzchnia {
public:
  /*!
   * \brief Usunięcie bezparametrycznego kontrukotra tafli
   */
  Tafla() = delete;
  /*!
   * \brief Konsturktor jednoparametryczny tafli
   *
   * Konstruktor tworzy powierzchnie tafli wody dopasowaną do 
   * rozmiarów ukłądu współrzędnych w gnuplocie. \n
   * Ustawa kolor rysowania na niebieski.
   * \param[in] wielkosc_palety - rozmiar osi gnuplota od 0 do MAX.
   */
  Tafla(double wielkosc_palety);

};

#endif