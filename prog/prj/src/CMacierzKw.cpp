#include "SMacierzKw.cpp"
/*!
 * \file
 * \brief Jawne konkretyzacje szablonu klasy MacierzKw
 *
 * Plik zawiera jawne konkretyzacje szablonu i funkcji 
 * nie należących do klasy MacierzKw. \n
 * \attention Funkcje w tym pliku nie są udokumentowane,
 * ponieważ są to tylko konkretyzacje opisanych już funkcji.
 * 
 */


// NA STALE  RZECZYWISTE
template class MacierzKw<double,3>;
template std::istream & operator >> (std::istream &strm, MacierzKw<double,3> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<double,3> &M);
template MacierzKw<double,3> operator * (double liczba, const MacierzKw<double,3> &M);

// 
template class MacierzKw<double,2>;
template class MacierzKw<double,1>;
template MacierzKw<double,2> pomniejsz_macierz(const MacierzKw<double,3> &M, unsigned int index1, unsigned int index2);
template MacierzKw<double,1> pomniejsz_macierz(const MacierzKw<double,2> &M, unsigned int index1, unsigned int index2);

