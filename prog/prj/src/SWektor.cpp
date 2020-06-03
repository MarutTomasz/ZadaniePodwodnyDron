#include "SWektor.hh"
/*!
 * \file
 * \brief Definicje metod i funkcji klasy Wektor
 *
 * Plik zawiera definicje metod i funkcji działających
 * na klasie Wektor oraz specjalizacje wybranych metod. \n
 */

/********** SET I GET **********/
template<class TYP, unsigned int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator [] (unsigned int index){
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP, unsigned int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator [] (unsigned int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor () {
  ++liczba_wektorow_istniejacych;
  ++liczba_wektorow_stworzonych;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    tab[i] = 0;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor (TYP *tabela) {
  ++liczba_wektorow_istniejacych;
  ++liczba_wektorow_stworzonych;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    tab[i] = tabela[i];
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor (const Wektor<TYP,ROZMIAR> &W) {
  ++liczba_wektorow_istniejacych;
  ++liczba_wektorow_stworzonych;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    tab[i] = W.tab[i];
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP x, TYP y, TYP z) {
  ++liczba_wektorow_istniejacych;
  ++liczba_wektorow_stworzonych;
  tab[0] = x;
  tab[1] = y;
  tab[2] = z;
}
  
/********** WCZYTYWANIE I WYSWIETLANIE  **********/
template<class TYP, unsigned int ROZMIAR>
std::istream & operator>>(std::istream &strm, Wektor<TYP,ROZMIAR> &W){
  for (unsigned int i=0; i<ROZMIAR; ++i)
    cin >> W[i];
  return strm;
}

template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W) {
  for (unsigned int i=0; i<ROZMIAR; ++i)
    cout << " " << W[i] << " ";
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] + W[i];
  return wynik;
} 

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] - W[i];
  return wynik;
} 

template<class TYP, unsigned int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> &W2) const {
  TYP wynik;
  wynik = 0.0;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    wynik += tab[i] * W2[i];
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] * liczba;
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  if(liczba == 0){
    cout << "Niedozwolone dzielenie przez 0" << endl;
    exit(1);
  }
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] / liczba;  
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W) {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = W[i] * liczba;
  return wynik;
}

/********** OPERACJE POROWNIANIA  **********/
template<class TYP, unsigned int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> &W) const {
  double epsilon = 0.000001;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    if (abs(tab[i]- W[i]) > epsilon)
      return false;
  return true;
}

template<class TYP, unsigned int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> &W) const {
  if (*this == W)
    return false;
  return true;
}

/********** OPERACJE WEKTOROWE  **********/
template<class TYP, unsigned int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const{
  double length = 0;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    length += (tab[i] * tab[i]);
  length = sqrt(length);
  return length;
}



template<class TYP, unsigned int ROZMIAR>
void Wektor<TYP,ROZMIAR>::przestaw_elementy(unsigned int index1, unsigned int index2) {
  if (index1 < 0 || index1 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (index2 < 0 || index2 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  
  TYP pomocniczy = tab[index1];
  tab[index1] = tab[index2];
  tab[index2] = pomocniczy;
}

template<class TYP, unsigned int ROZMIAR>
void wyswietl_wektor_bledu(const Wektor<TYP,ROZMIAR> &W) {
  cout << scientific;
  cout << setprecision(2);
  cout << "Wektor bledu:  Ax-b = (" << W << ")" << endl;
  cout << "Dlugosc wektora bledu: ||Ax-b|| = " << W.dlugosc() << endl << endl << endl;
  cout << defaultfloat;
}

template<class TYP, unsigned int ROZMIAR>
int Wektor<TYP,ROZMIAR>::liczba_wektorow_istniejacych(0);

template<class TYP, unsigned int ROZMIAR>
int Wektor<TYP,ROZMIAR>::liczba_wektorow_stworzonych(0);
