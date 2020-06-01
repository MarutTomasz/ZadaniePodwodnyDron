#ifndef PRZESZKODA
#define PRZESZKODA
/*!
 * \file
 * \brief Definicja klasy Przeszkoda
 *
 * Plik zawiera definicje klasy Przeszkoda.\n
 * Zawiera także deklaracje metod i funkcji działających 
 * na przeszkodach.
 */

#include "InterfejsDrona.hh"

/*!
 * \brief Modeluje pojęcie Przeszkoda
 * 
 * Klasa Przeszkoda zapewnie metody, które pozwalają traktować 
 * obiekt jako przeszkodę na trasie drona.
 */
class Przeszkoda {
public:
  /*!
   * \brief Metoda wykrywania kolizji
   *
   * Metooda wykrywa kolizje drona z obiektem.
   * \param[in] Inter - wskaznik na interfejs sterowanego drona.
   * \retval true - jeśli może nastąpić kolizja.
   * \retval false - w przeciwnym przypadku.
   */
  virtual bool czy_kolizja(InterfejsDrona *Inter) =0;

};


#endif
