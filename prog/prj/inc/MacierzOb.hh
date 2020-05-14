#ifndef MACIERZ_OB
#define MACIERZ_OB

#include "SMacierzKw.hh"

/*!
 * \brief Definicja liczby PI
 *
 * Definiuje stałą, która reprezentuje 
 * przybliżoną wartość liczby PI.
 */
#define PI 3.141592653589


/*!
 * \file
 * \brief Definicja klasy MacierzOb
 *
 * Plik zawiera definicje klasy MacierzOb, która
 * dziedzicy publicznie po klasie MacierzKw \n
 * Zawiera także deklaracje metod działających 
 * na macierzach obrotu.
 */
class MacierzOb: public Macierz3D {
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
  MacierzOb(const Macierz3D &M);
  /*!
   * \brief Konstruktor dwuparametryczny macierzy obrotu
   *
   * Konstruktor macierzy obrotowej względem osi określonej w 
   * pierwszym argumencie o liczbe stopni podaną w drugim argumencie
   * \param[in] os - znak, który określa os obrotu. 
   * \param[in] stopnie - liczba stopni obrotu. 
   */
  MacierzOb(char os, double stopnie); 
};

#endif
