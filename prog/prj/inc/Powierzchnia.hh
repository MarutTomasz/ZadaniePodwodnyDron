#ifndef POWIERZCHNIA
#define POWIERZCHNIA
/*!
 * \file
 * \brief Definicja klasy Powierzchnia
 *
 * Plik zawiera definicje klasy Powierzchnia, która
 * dziedzicy publicznie po klasie Obiekt3D \n
 * Zawiera także deklaracje metod operujących 
 * na powierzchni.
 */

#include "Obiekt3D.hh"

/*!
 * \brief Modeluje pojęcie Powierzchnia
 *
 * Klasa Powierzchnia dziedziczy publicznie po klasie Obiekt3D.\n
 * Reprezentuje ona płaszczyzne w przestrzeni.
*/
class Powierzchnia : public Obiekt3D {
protected:
  /*!
   * \brief Bezparametryczny konstruktor powierzchni
   *
   * Bezparametryczny konstruktor używany przez klasy dziedziczące.
   */
  Powierzchnia();
  /*!
   * \brief Pole pamiętające wymiar układu współrzędnych 
   *
   * Pole zapamiętuje wymiary ukłądu współrzędnych. 
   */
  double wymiar_palety;
   /*!
   * \brief Uzyskiwanie wspołrzędnych punktów
   *
   * Metoda uzyskuje współrzędne punktów siatki w układzie globalnym
   * wykorzystując znany rozmiar powierzni i głębokość.
   * \param[in] tablica_wspolrzednych - tablica na współrzędne wierzchołków
   * względem globalnego układu współrzędnych.
   */
  void Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych) const;

  void Orientuj_wektor(Wektor3D &W) const override;
public:
  /*!
   * \brief Konstruktor dwuparametryczny powierzchni 
   *
   * Konstruktor tworzy powierzchnie na zadanej głebokości.\n
   * Wymiary powierzchni są dostosowane do rozmiaru układu.
   * współrzędnych
   * \param[in] glebokosc - współrzędna Z na której rysowana ma byś powierzchnia.
   * \param[in] wymiar_palety - rozmiar układu współrzędnych w gnuplocie
   */
  Powierzchnia(double glebokosc, double wymiar_palety);
  
  void Narysuj() override;
  
  
  
  
};


#endif
