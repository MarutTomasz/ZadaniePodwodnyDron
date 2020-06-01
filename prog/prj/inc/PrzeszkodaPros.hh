#ifndef PRZESZKODAPROS
#define PRZESZKODAPROS
/*!
 * \file
 * \brief Definicja klasy PrzeszkodaPros
 *
 * Plik zawiera definicje klasy PrzeszkodaPros, która
 * dziedzicy publicznie po klasach Prostopadloscian
 * i Przeszkoda \n
 * Zawiera także deklaracje metod operujących 
 * na prostopadłościennej przeszkodzie.
 */

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"
/*!
 * \brief Modeluje pojęcie PrzeszkodaPros
 *
 * Klasa PrzeszkodaPros dziedziczy publicznie po klasach Prostopadloscian i Przeszkoda.\n
 * Reprezentuje ona przeszkodę o prostopadłościennym kształcie.
 */
class PrzeszkodaPros: public Prostopadloscian, public Przeszkoda {
public:
  /*!
   * \brief Usunięcie bezparametrycznego kontrukotra przeszkody
   */
  PrzeszkodaPros() = delete;
  /*!
   * \brief Konstruktor trójparametryczny prostopadłościennej przeszkody
   *
   * Konstruktor tworzy prostopadłościan o zadanych w argumentach 
   * wymiarach.
   * \param[in] A_bok - długość boku w osi X
   * \param[in] B_bok - długość boku w osi Y
   * \param[in] C_bok - długość boku w osi Z
   */
  PrzeszkodaPros(double A_bok,
		 double B_bok,
		 double C_bok);
  bool czy_kolizja(InterfejsDrona *Inter) override;

};

#endif
