#ifndef DNO
#define DNO
/*!
 * \file
 * \brief Definicja klasy Dno
 *
 * Plik zawiera definicje klasy Dno.\n
 * Zawiera także deklaracje metod
 * operujących na powierzchni reprezentującej dno.
 */

#include "Powierzchnia.hh"
#include "Dron.hh"
#include "Przeszkoda.hh"

/*!
 * \brief Modeluje pojęcie Dno
 *
 * Klasa Dno dziedziczy publicznie po klasach Powierzchnia i Przeszkoda .\n
 * Reprezentuje ona płaszczyznę dna zbiornika, w którym ma pływać dron.
 */
class Dno : public Powierzchnia, public Przeszkoda {
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
   * Ustawa kolor rysowania na szary.
   * \param[in] wielkosc_palety - rozmiar osi gnuplota od 0 do MAX.
   */
  Dno(double wielkosc_palety);
  bool czy_kolizja(InterfejsDrona *Inter) override;

};

#endif
