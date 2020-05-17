#ifndef DNO
#define DNO
/*!
 * \file
 * \brief Definicja klasy Dno
 *
 * Plik zawiera definicje klasy Dno, która
 * dziedzicy publicznie po klasie Powierzchnia \n
 * Zawiera także deklaracje metod operujących 
 * na powierzchni reprezentującej dno.
 */

#include "Powierzchnia.hh"

/*!
 * \brief Modeluje pojęcie Dno
 *
 * Klasa Dno dziedziczy publicznie po klasie Powierzchnia.\n
 * Reprezentuje ona płaszczyznę dna zbiornika, w którym ma pływać dron.
 */
class Dno : public Powierzchnia {
public:
  /*!
   * \brief Usunięcie bezparametrycznego kontrukotra dna
   */
  Dno() = delete;
  /*!
   * \brief Konsturktor jednoparametryczny dna
   *
   * Konstruktor tworzy powierzchnie dna dopasowaną do 
   * rozmiarów ukłądu współrzędnych w gnuplocie. \n
   * Ustawa kolor rysowania na czarny.
   * \param[in] wielkosc_palety - rozmiar osi gnuplota od 0 do MAX.
   */
  Dno(double wielkosc_palety);
};

#endif
