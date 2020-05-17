#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA
/*!
 * \file
 * \brief Definicja abstrakcyjnej klasy InterfejsDrona
 *
 * Plik zawiera definicje klasy InterfejsDrona.\n
 * Zawiera także deklaracje metod służących do 
 * obsługi drona.
 */
#include <unistd.h>
#include <math.h>
#include "MacierzOb.hh"
#include "SWektor.hh"

/*!
 * \brief Modeluje pojęcie InterfejsDrona
 *
 * Zawiera deklaracje funkcji służących do
 * obsługi drona.
 */
class InterfejsDrona {
protected:
  /*!
   * \brief Konstruktor bezparametryczny interfejsu
   *
   * Używany w tworzeniu obiektów klas pochodnych. Nie 
   * pozwala na utworzenie osobnego interfejsu, bez 
   * przypisanego drona.
   */
  InterfejsDrona() {};
  /*!
   * \brief Metoda obrotu drona w osi Z
   *
   * Metoda dokonująca obrotu drona wokół 
   * osi Z o zadaną ilość stopi.
   * \param[in] stopnie - kąt obrotu. 
   */
  virtual void Obrot_Z(double stopnie) = 0;
  /*!
   * \brief Metoda obrotu drona w osi X
   *
   * Metoda dokonująca obrotu drona wokół 
   * osi X o zadaną ilość stopi.
   * \param[in] stopnie - kąt obrotu. 
   */
  virtual void Obrot_X(double stopnie) = 0;
  /*!
   * \brief Metoda obrotu drona w osi Y
   *
   * Metoda dokonująca obrotu drona wokół 
   * osi Y o zadaną ilość stopi.
   * \param[in] stopnie - kąt obrotu. 
   */
  virtual void Obrot_Y(double stopnie) = 0;
  /*!
   * \brief Metoda przesuwania drona
   *
   * Metoda dokonująca przesuwania drona 
   * wzdłuż lokalnej osi X o zadaną odległość.
   * \param[in] odleglosc - odległość, o jaka przesuwany jest dron.
   */
  virtual void Przesun(double odleglosc) = 0;
public:
  /*!
   * \brief Płynięcie drona z animacją
   *
   * Metoda animująca pływanie drona 
   * wzdłuż osi X (lokalną oś) o zadaną odległość pod 
   * zadanym kątem.
   * \param[in] odleglosc - odległość, o jaka musi przesunąć się dron.
   * \param[in] kat - kąt, pod jakim musi przesunąć się dron. 
   */
  virtual void Plyn(double odleglosc, double kat) = 0;
  /*!
   * \brief Metoda animowanego obrotu drona
   *
   * Metoda dokonująca obrotu drona z animacją wokół 
   * osi Z o zadaną ilość stopi.
   * \param[in] stopnie - kąt obrotu. 
   */
  virtual void Obrot_Z_Animowany(double stopnie) = 0;
  
};

  
#endif
