#ifndef SMACIERZ_S
#define SMACIERZ_S
/*!
 * \file
 * \brief Definicja szablonu klasy MacierzKw
 *
 * Plik zawiera definicje szablonu klasy MacierzKw o 
 * zmiennym rozmiarze i typie danych. \n
 * Zawiera także deklaracje metod i funkcji działających 
 * na macierzach kwadratowych.
 */

#include "SWektor.hh"

 /*!
   * \brief Określa metodę wyliczania wyznacznika
   *
   * Typ wyliczeniowy określające dopuszczalne metody wyliczania
   * wyznacznika macierzy. 
   */
enum Wyz_Metoda {
		 /*!
		  * - oznacza wyliczanie wyznacznika metodą Laplace'a.
		  */
		 Laplace,
		 /*!
		  * - oznacza wyliczanie wyznacznika metodą eliminacji 
		  * Gaussa.
		  */
		 Gauss
};


 /*!
   * \brief Określa metodę odwracania macierzy
   *
   * Typ wyliczeniowy określające dopuszczalne metody 
   * odwracania macierzy.
   */
enum Odw_Metoda {
		 /*!
		  * - oznacza odwracanie macierzy metodą 
		  * eliminacji Gaussa-Jordana.
		  */
		 Gauss_Jordan,
		 /*!
		  * - oznacza odwracanie macierzy korzystając
		  * z definicji macierzy odwrotnej.
		  */
		 Definicja
};

/*!
 * \brief Modeluje pojęcie MacierzKw
 *
 * Szablon klasy MacierzKw jest parametryzowany typem 
 * przechowywanych zmiennych oraz rozmiarem (ilością wierszy). \n
 * \param TYP - typ zmiennych tworzących wektory macierzy.
 * \param ROZMIAR - ilość wierszy tworzących macierz.
 * \attention KOLEJNE WEKTORY SA INTERPRETOWANE JAKO WIERSZE MACIERZY !! \n
 * W CELU OTRZYMANIA POPRAWNYCH WYNIKÓW NALEŻY WPROWADZAĆ MACIERZ W POSTACI
 * TRANSPONOWANEJ.
*/
template<class TYP, unsigned int ROZMIAR>
class MacierzKw {
protected:
  /*!
   * \brief Tablica zawierająca wiersze macierzy w postaci wektorów.
   * 
   * Tablica zawiera wiersze macierzy w postaci wektorów.
   * \param ROZMIAR - wielkość tablicy, liczba wierszy macierzy.
   */
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
 
public:
/*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego wektora macierzy
   * oraz daje możliwość zmiany go.
   * \param[in] index - index wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego wektora.
   */
  Wektor<TYP,ROZMIAR> & operator[] (unsigned int index);
  /*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego wektora, 
   * ale nie daje możliwości zmiany go.
   * \param[in] index - index wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego wektora.
   */
  const Wektor<TYP,ROZMIAR> & operator[] (unsigned  int index) const;
  
  /*!
   * \brief Konstruktor bezparametryczny macierzy
   *
   * Konstruktor inicjalizuje wszystkie elementy macierzy wartością 0. 
   */
  MacierzKw();
  /*!
   * \brief Konstruktor jednoparametryczny macierzy
   *
   * Konstruktor inicjalizuje elementy macierzy wartościami z tablicy o
   * jednakowym rozmiarze i typie przechowywanych danych co macierz.  
   * \param[in] tabela - tablica z wartościami inicjalizującymi macierz.
   */
  MacierzKw(Wektor<TYP,ROZMIAR> *tabela);
  /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla typu MacierzKw - MacierzKw.
   * Dokonuje operacji dodania wartości argumentów.
   * \param[in] M - składnik w postaci macierzy.
   * \return Zwraca macierz po dokonaniu operacji dodawania.
   */
  MacierzKw<TYP,ROZMIAR> operator +(const MacierzKw<TYP,ROZMIAR> &M) const;
  /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla typu MacierzKw - MacierzKw.
   * Dokonuje operacji odejmowania od siebie wartości argumentów.
   * \param[in] M - odjemnik w postaci macierzy.
   * \return Zwraca macierz po dokonaniu operacji odejmowania.
   */
  MacierzKw<TYP,ROZMIAR> operator -(const MacierzKw<TYP,ROZMIAR> &M) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu MacierzKw - MacierzKw.
   * Dokonuje operacji mnożenie wartości argumentów.
   * \param[in] M - czynnik w postaci macierzy.
   * \return Zwraca macierz po dokonaniu operacji mnożenia.
   */
  MacierzKw<TYP,ROZMIAR> operator *(const MacierzKw<TYP,ROZMIAR> &M) const; 
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu MacierzKw - double.
   * Dokonuje operacji mnożenie wartości argumentów.
   * \param[in] liczba - czynnik w postaci skalara (TYP).
   * \return Zwraca macierz po dokonaniu operacji mnożenia.
   */
  MacierzKw<TYP,ROZMIAR> operator *(TYP liczba) const;
   /*!
   * \brief Przeciążenie operatora dzielenia
   *
   * Przeciążenie operatora dzielenia dla typu MacierzKw - TYP.
   * Dokonuje operacji dzielenia macierzy przez skalar (TYP).
   * \param[in] liczba - dzielnik w postaci skalara (TYP) .
   * \return Zwraca macierz po dokonaniu operacji dzielenia.
   */
  MacierzKw<TYP,ROZMIAR> operator /(TYP liczba) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu MacierzKw - Wektor.
   * Dokonuje operacji mnożenie wartości argumentów.
   * \param[in] W - czynnik w postaci wektora.
   * \return Zwraca wektor po dokonaniu operacji mnożenia.
   */
  Wektor<TYP,ROZMIAR> operator *(const Wektor<TYP,ROZMIAR> &W) const;
  
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu MacierzKw - MacierzKw.
   * Sprawdza, czy macierze podane w argumentach są równe.
   * \param[in] M - porównywana macierz.
   * \retval true - jeśli macierze są równe,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator == (const MacierzKw<TYP,ROZMIAR> &M) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu MacierzKw - MacierzKw.
   * Sprawdza, czy macierze podane w argumentach są różne.
   * \param[in] M - porównywana macierz.
   * \retval true - jeśli macierze są różne,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator != (const MacierzKw<TYP,ROZMIAR> &M) const;
  
  /*!
   * \brief Transponuje macierz
   *
   * Funkcja dokonuje operacji transpozycji
   * macierzy.
   */
  void transponuj();
  /*!
   * \brief Podmienia kolumne macierzy
   *
   * Funkcja dokonuje wymiany całej kolumny macierzy o indeksie
   * podanym na wejściu funkcji. Kolumna jest zamieniana na
   * wektor podany jako arument funkcji.
   * \param[in] index - indeks kolummy do wymiany.
   * \param[in] W - wektor z nowymi wartościami kolumny.
   */
  void zmien_kolumne(unsigned int index, const Wektor<TYP,ROZMIAR> W);
  /*!
   * \brief Podmienia wiersz macierzy
   *
   * Funkcja dokonuje wymiany całego wiersza macierzy o indeksie
   * podanym na wejściu funkcji. Wiersz jest zamieniany na
   * wektor podany jako arument funkcji.
   * \param[in] index - indeks wiersza do wymiany.
   * \param[in] W - wektor z nowymi wartościami wiersza.
   */
  void zmien_wiersz(unsigned int index, const Wektor<TYP,ROZMIAR> W);
  /*!
   * \brief Zamienia miejscami dwa wiersze
   *
   * Funkcja dokonuje zamiany miejscami dwóch wierszy 
   * macierzy o indekas odpowiadających argumentom funkcji.
   * \param[in] index1 - indeks pierwszego wiersza do zamiany.
   * \param[in] index2 - indeks drugiego wiersza do zamiany.
   */
  void przestaw_wiersze(unsigned int index1, unsigned int index2);
  /*!
   * \brief Zamienia miejscami dwie kolumny
   * 
   * Funkcja dokonuje zamiany miejscami dwóch kolumny 
   * macierzy o indekas odpowiadających argumentom funkcji.
   * \param[in] index1 - indeks pierwszej kolumny do zamiany.
   * \param[in] index2 - indeks drugiej kolumny do zamiany.
   */
  void przestaw_kolumny(unsigned int index1, unsigned int index2);
  /*!
   * \brief Zmiana macierzy na jednostkową
   * 
   * Funkcja zmienia wszystkie elementy macierzy tworząc 
   * jednostkową.
   */
  void MacierzJednostkowa(); 
  /*!
   * \brief Oblicza wyznacznik macierzy
   * 
   * Funkcja oblicza wyznacznik macierzy metodą podaną jako 
   * argument. Dostępne są metody Gaussa i Laplace'a.
   * \param[in] metoda - określa metodę wyliczania wyznacznika macierzy.
   * \return Zwraca obliczony wyznacznik.
   */
  TYP wyznacznik(Wyz_Metoda metoda) const; 
  /*!
   * \brief Tworzy macierz odwrotną
   * 
   * Funkcja tworzy macierz odwrotną do macierzy na której wywoływana 
   * jest metoda. Dostępne są metody Gaussa-Jordan i korzystając z definicji.
   * \param[in] metoda - określa metodę jaką teorzona jest macierz odwrotna.
   * \return Zwraca nową macierz odwrotną.
   */
  MacierzKw<TYP,ROZMIAR> odwroc(Odw_Metoda metoda) const;
  /*!
   * \brief Tworzy macierz dopełniej algebraicznych
   * 
   * Funkcja tworzy macierz dopełnień algebraicznych macierzy na której wywoływana 
   * jest metoda.
   * \return Zwraca nową macierz dopełnień algebraicznych..
   */
  MacierzKw<TYP,ROZMIAR> macierz_dopelnien() const;
};
  
/*!
 * \brief Przeciążenie operatora wczytywania
 *
 * Przeciążenie operatora wczytywania dla obiektów klasy MacierzKw. \n
 * \param[in] &strm - strumień danych.
 * \param[in] M - macierz, do której wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
 */
template<class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, MacierzKw<TYP,ROZMIAR> &M);

/*!
 * \brief Przeciążenie operatora wyświetlania
 *
 * Przeciążenie operatora wyświetlania dla obiektów klasy MacierzKw. \n
 * \param[in] &strm - strumień danych.
 * \param[in] M - macierz, ktorej wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 */
template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const MacierzKw<TYP,ROZMIAR> &M);

/*!
 * \brief Przeciążenie operatora mnożenia
 *
 * Przeciążenie operatora mnożenia dla typu double - MacierzKw.
 * Dokonuje operacji mnożenie wartości argumentów.
 * \param[in] liczba - czynnik w postaci skalara (TYP).
 * \param[in] M - czynnik w postaci macierzy.
 * \return Zwraca macierz po dokonaniu operacji mnożenia.
 */
template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> operator *(TYP liczba, const MacierzKw<TYP,ROZMIAR> &M); 

/*!
 * \brief Tworzy macierz pomniejszoną względem wybranego elementu
 * 
 * Funkcja tworzy macierz pomniejszoną względem wybranego elementu.
 * \param[in] index1 - pierrszy index elementu, względem którego pomniejszamy macierz.
 * \param[in] index2 - drugi index elementu, względem którego pomniejszamy macierz.
 * \param[in] M - macierz, którą będziemy pomniejszać.
 * \return Zwraca nową macierz o mniejszym rozmiarze.
 */
template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR-1> pomniejsz_macierz(const MacierzKw<TYP,ROZMIAR> &M, unsigned int index1, unsigned int index2);


/*!
 * \brief Definicja typu Macierz
 *
 * Definicja skróconego zapisu macierzy o rozmiarze 3, 
 * uzywanego w macierzy obrotu. 
 */
typedef MacierzKw<double,3> Macierz3D;

#endif
