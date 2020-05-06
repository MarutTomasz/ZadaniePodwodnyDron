#ifndef MACIERZ_OB
#define MACIERZ_OB

#include "SMacierzKw.hh"

/*!
 * \file
 * \brief Definicja klasy MacierzOb
 *
 * Plik zawiera definicje klasy MacierzOb, która
 * dziedzicy publicznie po klasie MacierzKw \n
 * Zawiera także deklaracje metod działających 
 * na macierzach obrotu.
 */
class MacierzOb: public MacierzKw<double,3> {
public:
  /*!
   * \brief Konstruktor bezparametryczny macierzy obrotu
   *
   * Konstruktor tworzy macierz jednostkową wymiaru 3x3. 
   */
  MacierzOb();
  /*!
   * \brief Konstruktor jednoparametryczny macierzy obrotu
   *
   * Konstruktor kopiujący z macierzy kwadratowej, jeśli 
   * macierz podana w argumencie jest ortonormalna.
   * \param[in] M - macierz, która jest kopiowana na macierz obrotu. 
   */
  MacierzOb(const MacierzKw<double,3> &M);
  
};

#endif
