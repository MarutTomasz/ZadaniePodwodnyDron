#include "SWektor.cpp"
/*!
 * \file
 * \brief Jawne konkretyzacje szablonu klasy Wektor
 *
 * Plik zawiera jawne konkretyzacje szablonu i funkcji 
 * nie należących do klasy Wektor. \n
 * \attention Funkcje w tym pliku nie są udokumentowane,
 * ponieważ są to tylko konkretyzacje opisanych już funkcji.
 * 
 */

// NA STALE 3
template class Wektor<double,3>;
template std::istream & operator>>(std::istream &strm, Wektor<double,3> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,3> &W);
template Wektor<double,3> operator * (double liczba, const Wektor<double,3> &W);
template void wyswietl_wektor_bledu (const Wektor<double,3> &W);

// 2
template class Wektor<double,2>;
template Wektor<double,2> operator * (double liczba, const Wektor<double,2> &W);

// 1
template class Wektor<double,1>;
template Wektor<double,1> operator * (double liczba, const Wektor<double,1> &W);

