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
#include "MacierzOb.hh"

/*!
 * \brief Modeluje pojęcie InterfejsDrona
 *
 * Zawiera deklaracje funkcji służących do
 * obsługi drona.
 */
class InterfejsDrona {
protected:
  /*!
   * \brief Promień kuli opisanej na dronie
   */
  double promien;
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
   * \brief Metoda zwracająca promień
   *
   * Metoda zwraca promień kuli opisanej na dronie.
   * \return - promień kuli. 
   */
  double Wez_Promien()const { return promien; }
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
  /*!
   * \brief Metoda przesuwania drona
   *
   * Metoda dokonująca przesuwania drona 
   * na punkt o zadanych współrzędnych.
   * \param[in] X - współrzędna X nowego środka drona.
   * \param[in] Y - współrzędna Y nowego środka drona.
   * \param[in] Z - współrzędna Z nowego środka drona.
   */
  virtual void Przesun(double X, double Y, double Z) =0;
  /*!
   * \brief Metoda przesuwania drona
   *
   * Metoda dokonująca przesuwania drona 
   * na punkt o współrzędnych opisanych wektorem.
   * \param[in] Wektor - wektor współrzędnych nowego środka drona.
   */
  virtual void Przesun(const Wektor3D Wektor) =0;
};

  
#endif
