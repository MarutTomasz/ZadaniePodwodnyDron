#ifndef SWEKTOR_S
#define SWEKTOR_S
/*!
 * \file
 * \brief Definicja szablonu klasy Wektor
 *
 * Plik zawiera definicje szablonu klasy Wektor o 
 * zmiennym rozmiarze i typie danych. \n
 * Zawiera także deklaracje metod i funkcji działających 
 * na wektorach.
 */

#include <iomanip>
#include <math.h>
#include <iostream>

using std::showpos;
using std::noshowpos;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

using std::setprecision;
using std::fixed;
using std::defaultfloat;
using std::scientific;



/*!
 * \brief Modeluje pojęcie Wektor
 *
 * Szablon klasy Wektor jest parametryzowany typem 
 * przechowywanych zmiennych oraz rozmiarem (ilością elementów). \n
 * \param TYP - typ zmiennych tworzących wektor.
 * \param ROZMIAR - ilość zmiennych tworzących wektor.
*/
template<class TYP, unsigned int ROZMIAR>
class Wektor {
  /*!
   * \brief Tablica zawierająca elementy wektora.
   * 
   * Tablica zawierająca elementy wektora.
   * \param ROZMIAR - wielkość tablicy elementów.
   */
TYP tab [ROZMIAR];
  
public:
  /*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego elementu wektora 
   * oraz daje możliwość zmiany go.
   * \param[in] index - index elementu wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego elementu wektora.
   */
  TYP & operator [] (unsigned int index);
  /*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego elementu wektora, 
   * ale nie daje możliwości zmiany go.
   * \param[in] index - index elementu wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego elementu wektora.
   */
  const TYP & operator [] (unsigned int index) const;
  
  /*!
   * \brief Konstruktor bezparametryczny wektora 
   *
   * Konstruktor inicjalizuje wszystkie elementy wektora wartością 0. 
   */
  Wektor();
  /*!
   * \brief Konstruktor jednoparametryczny wektora 
   *
   * Konstruktor inicjalizuje elementy wektora wartościami z tablicy o
   * jednakowym rozmiarze i typie przechowywanych danych co wektor.  
   * \param[in] tabela - tablica z wartościami inicjalizującymi wektor.
    */
  Wektor(TYP *tabela);
  /*!
   * \brief Konstruktor trójparametryczny wektora 
   *
   * Konstruktor inicjalizuje elementy wektora wartościami podanych
   * argumentów. Tworzy wektory trójwymiarowe.  
   * \param[in] x - wartość współrzędnej X.
   * \param[in] y - wartość współrzędnej Y.
   * \param[in] z - wartość współrzędnej Z.
    */
  Wektor(TYP x, TYP y, TYP z);
  
  /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla typu Wektor - Wektor.
   * Dokonuje operacji dodania wartości argumentów.
   * \param[in] W - składnik w postaci wektora.
   * \return Zwraca wektor po dokonaniu operacji dodawania.
   */
  Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla typu Wektor - Wektor.
   * Dokonuje operacji odejmowania od siebie wartości argumentów.
   * \param[in] W - odjemnik w postaci wektora.
   * \return Zwraca wektor po dokonaniu operacji odejmowania.
   */
  Wektor<TYP,ROZMIAR> operator - (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu Wektor - Wektor.
   * Dokonuje operacji mnożenie wartości argumentów.
   * Jest to odpowiednik mnożenia skalarnego wektorów.
   * \param[in] W - czynnik  w postaci wektora.
   * \return Zwraca wynik mnożenia skalarnego.
   */
  TYP operator * (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora odejmowania dla typu Wektor - TYP.
   * Dokonuje operacji mnożenia wartości argumentów.
   * \param[in] liczba - czynnik w postaci skalara (TYP).
   * \return Zwraca wektor po dokonaniu operacji mnożenia.
   */
  Wektor<TYP,ROZMIAR> operator * (TYP liczba) const;
  /*!
   * \brief Przeciążenie operatora dzielenia
   *
   * Przeciążenie operatora dzielenia dla typu Wektor - TYP.
   * Dokonuje operacji dzielenia wektora przez skalar (TYP).
   * \param[in] liczba - dzielnik w postaci skalara (TYP) .
   * \return Zwraca wektor po dokonaniu operacji dzielenia.
   */
  Wektor<TYP,ROZMIAR> operator / (TYP liczba) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu Wektor - Wektor.
   * Sprawdza, czy wektory podane w argumentach są równe.
   * \param[in] W - porównywany wektor.
   * \retval true - jeśli wektory są równe,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator == (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu Wektor - Wektor.
   * Sprawdza, czy wektory podane w argumentach są różne.
   * \param[in] W - porównywany wektor.
   * \retval true - jeśli wektory są różne,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator != (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Wyliczenie długości wektora
   *
   * Funkcja wylicza długość wektora jako pierwiastek z sumy 
   * kwadratów wszystkich elementów wektora. Dla elementów 
   * tylu LZespolona napisana jest specjalizacja
   * \return Zwraca długość wektora.
   */
  double dlugosc() const;
  /*!
   * \brief Zamiana miejscami elementow wektora
   *
   * Funkcja zamienia miejscami dwa elementy wektora o 
   * indexach podanych jako argumenty wywołania funkcji.
   * \param index1 - index pierwszego elementu do zmiany.
   * \param index2 - index drugiego elementu do zmiany.
   * \attention Funkcja dokonuje zmian w polach struktury.
   */
  void przestaw_elementy(unsigned int index1, unsigned int index2);

};

/*!
 * \brief Przeciążenie operatora wyświetlania
 *
 * Przeciążenie operatora wyświetlania dla obiektów klasy Wektor. \n
 * \param[in] &strm - strumień danych.
 * \param[in] W - wektor, ktorego wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 */
template<class TYP, unsigned int ROZMIAR>
std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Przeciążenie operatora wczytywania
 *
 * Przeciążenie operatora wczytywania dla obiektów klasy Wektor. \n
 * \param[in] &strm - strumień danych.
 * \param[in] W - wektor, do którego wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
 */
template<class TYP, unsigned int ROZMIAR>
std::istream & operator>> (std::istream &strm, Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Przeciążenie operatora mnożenia
 *
 * Przeciążenie operatora mnożenia dla typu TYP - Wektor.
 * Dokonuje operacji mnożenia wartości argumentów.
 * \param[in] liczba - czynnik w postaci skalara (TYP).
 * \param[in] W - czynnik w postaci wektora.
 * \return Zwraca wektor po dokonaniu operacji mnożenia.
 */
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Specjalne wyswietlanie bledu
 *
 * Specjalna funkcja zajmująca się wyświetlaniem wszystkich
 * informacji o wektorze błędu. \n
 * Przykład wyświetlania informacji o wektorze błędu dla danych typu double:
\verbatim
        Wektor bledu:  Ax-b = ( -1.78e-15  -1.78e-15  -1.78e-15  0.00e+00  -2.89e-15 )
        Dlugosc wektora bledu: ||Ax-b|| = 4.22e-15
\endverbatim
 * Przykład wyświetlania informacji o wektorze błędu dla danych typu LZespolona:
\verbatim
        Wektor bledu:  Ax-b = ( (3.55e-15+1.78e-15i)  (1.78e-15-4.00e-15i)  (-3.55e-15+0.00e+00i)  (0.00e+00-8.88e-16i)  (1.24e-14-6.44e-15i) )
        Dlugosc wektora bledu: ||Ax-b|| = 1.56e-14
\endverbatim
 * \param[in] W - wektor błędy do wyświetlenia.
 */
template<class TYP, unsigned int ROZMIAR>
void wyswietl_wektor_bledu(const Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Definicja typu Wektora
 *
 * Definicja skróconego zapisu wektora o rozmiarze 3, 
 * uzywanego w plikach, korzystających z tego rodzaju 
 * wektorów. 
 */
typedef Wektor<double,3> Wektor3D;

#endif
