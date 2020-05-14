#ifndef SRUBA
#define SRUBA


#include "GraniastoslupHex.hh"

class Sruba : public GraniastoslupHex {
public:
  /*!
   * \brief Kontruktor bezparametryczny śruby
   *
   * Tworzy obiekt klasy Sruba bez inicjalizacji 
   * wymiarów.
   */
  Sruba();
  /*!
   * \brief Kontruktor dwuparametryczny śruby
   *
   * Tworzy obiekt klasy Sruba inicjalizując wymiary obiektu
   * zadanymi argumentami.
   * \paran[in] A_bok - długość krawędzi podstawy. 
   * \paran[in] H_bok - długość wysokości.
   */
  Sruba(double A_bok, double H_bok);
  /*!
   * \brief Obracaj śrubę
   *
   * Metoda odpowiada za animacje obracania śrubami
   * podczas ruchu drona.
   */
  void Obracaj();
  /*!
   * \brief Metoda ustawiająca wymiary śruby
   *
   * Ustawia wymiary obiektu klasy Sruba
   * zadanymi argumentami.
   * \paran[in] A_bok - długość krawędzi podstawy. 
   * \paran[in] H_bok - długość wysokości.
   */
  void Set_Wymiary(double A_bok, double H_bok);
  
  
  
};

#endif
