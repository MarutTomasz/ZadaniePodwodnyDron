#ifndef SRUBA
#define SRUBA
/*!
 * \file
 * \brief Definicja klasy Sruba
 *
 * Plik zawiera definicje klasy Sruba, która
 * dziedzicy publicznie po klasie GraniastoslupHex \n
 * Zawiera także deklaracje metod operujących 
 * na "śrubie".
 */


#include "GraniastoslupHex.hh"

/*!
 * \brief Modeluje pojęcie Sruba
 *
 * Klasa Sruba dziedziczy publicznie po klasie GraniastoslupHex.\n
 * Reprezentuje ona "śrube" w przestrzeni i zawiera operacje 
 * konieczne do jej prawidłowego funkcjonowania.
*/
class Sruba : public GraniastoslupHex {
protected:
  /*!
   * \brief Macierz znająca aktualny obrót śruby podczas pracy
   */
  MacierzOb Rotacja;
  /*!
   * \brief Metoda orientująca wektor
   *
   * Metoda orientuje wektor wierzchołka z układu współrzędnych 
   * zintegrowanych z obiektem na globalny układ współrzędnych i 
   * dokonująca obrotu w lokalnej osi x śruby, która zmienia się podczas
   * pracy śruby.
   * \param[in] W - Orientowany wektor.
   */
  void Orientuj_wektor(Wektor3D &W) const;
  /*!
   * \brief Uzyskiwanie wspołrzędnych punktów
   *
   * Metoda uzyskuje współrzędne wierzchiłków w układzie globalnym
   * wykorzystując relację między długością boków i orientacją i 
   * punktem środka obiektu. Metoda przelicza wierzchołki inaczej niż 
   * samodzielny obiekt klasy GraniastoslupHex.
   * \param[in] tablica_wspolrzednych - tablica na współrzędne wierzchołków
   * względem globalnego układu współrzędnych.
   */
  void Uzyskaj_wspolrzedne(std::vector<Wektor3D> &tablica_wspolrzednych)const;
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
   * \param[in] A_bok - długość krawędzi podstawy. 
   * \param[in] H_bok - długość wysokości.
   */
  Sruba(double A_bok, double H_bok);
  /*!
   * \brief Metoda ustawiająca wymiary śruby
   *
   * Ustawia wymiary obiektu klasy Sruba
   * zadanymi argumentami.
   * \param[in] A_bok - długość krawędzi podstawy. 
   * \param[in] H_bok - długość wysokości.
   */
  void Set_Wymiary(double A_bok, double H_bok);
  /*!
   * \brief Metoda przesuwania śruby
   *
   * Metoda dokonująca przesuwania śruby
   * wzdłuż lokalnej osi X o zadaną odległość.
   * \param[in] odleglosc - odległość, o jaka przesuwany jest dron.
   */
  void Przesun(double odleglosc);

  /*!
   * \brief Obracaj śrubę
   *
   * Metoda odpowiada za animacje obracania śrubami
   * podczas ruchu drona.
   */
  void Obracaj();
  
  /*!
   * \brief Metoda obracania wirników względem osi drona
   *
   * Metoda dokonuje ustawienia nowego środka i orientacji, wymuszone
   * poprzez obrót śruby względem punktu śrudkowego drona, do którego przynależy.
   * \param[in] Odsuniecie - wektor, o jaki środek śruby jest odsunięty od środka drona.
   * \param[in] Obrot - obrót, jaki śruba musi wykonać względem własnego środka .
   * \param[in] Ort_Drona - orientacja drona po obrocie, potrzebna do odpowiedzniego pozycjonowania śruby.
   */
  void Obrot_z_dronem (Wektor3D Odsuniecie, MacierzOb Obrot, MacierzOb Ort_Drona);
  /*!
   * \brief Metoda rysowania śruby
   *
   * Metoda rysowanie śruby, która wykorzystuje inny sposób 
   * przeliczenia wierzchołków niż osobny obiekt klasy 
   * GraniastoslupHex.
   */
  void Narysuj();

};

#endif
