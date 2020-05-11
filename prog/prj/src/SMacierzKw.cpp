#include "SMacierzKw.hh"
/*!
 * \file
 * \brief Definicje metod i funkcji klasy MacierzKw
 *
 * Plik zawiera definicje metod i funkcji działających
 * na klasie MacierzKw oraz specjalizacje wybranych metod. \n
 */

/********** SET I GET  **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> & MacierzKw<TYP,ROZMIAR>::operator[] (unsigned int index) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP, unsigned int ROZMIAR>
const Wektor<TYP,ROZMIAR> & MacierzKw<TYP,ROZMIAR>::operator[] (unsigned int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR>::MacierzKw() {
  Wektor<TYP,ROZMIAR> W;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    tab[i] = W;  
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR>::MacierzKw(Wektor<TYP,ROZMIAR> *tabela) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    tab[i] = tabela[i];
}

/********** WCZYTYWANIE I WYSWIETLANIE **********/
template<class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, MacierzKw<TYP,ROZMIAR> &M) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    cin >> M[i];
  M.transponuj();
  return strm;
}

template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const MacierzKw<TYP,ROZMIAR> &M) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    cout << M[i] << endl;
  return strm;
}

/********** OPERACJE MATEMATYCZNE **********/
template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator + (const MacierzKw<TYP,ROZMIAR> &M) const {
  MacierzKw<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik [i] = tab[i] + M[i];
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator - (const MacierzKw<TYP,ROZMIAR> &M) const {
  MacierzKw<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik [i] = tab[i] - M[i];
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(const MacierzKw<TYP,ROZMIAR> &M) const {
  MacierzKw<TYP,ROZMIAR> Wynik;
  MacierzKw<TYP,ROZMIAR> KopiaM = M;
  KopiaM.transponuj();
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      Wynik[i][j] = tab[i] * KopiaM[j];
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(TYP liczba) const {
  MacierzKw<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = tab[i] * liczba;
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator /(TYP liczba) const {
  MacierzKw<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = tab[i] / liczba;
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = tab[i] * W;
  return Wynik;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> operator *(TYP liczba, const MacierzKw<TYP,ROZMIAR> &M) {
  MacierzKw<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = M[i] * liczba;
  return Wynik;
}


/********** OPERACJE POROWNANIA  **********/
template<class TYP, unsigned int ROZMIAR>
bool MacierzKw<TYP,ROZMIAR>::operator == (const MacierzKw<TYP,ROZMIAR> &M) const {
  double epsilon = 0.000001;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      if(abs(tab[i][j] - M[i][j]) > epsilon)
	return false;
  return true;
}

template<class TYP, unsigned int ROZMIAR>
bool MacierzKw<TYP,ROZMIAR>::operator != (const MacierzKw<TYP,ROZMIAR> &M) const {
  if( *this == M)
    return false;
  return true;
}

/********** METODY MACIERZOWE **********/
template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::MacierzJednostkowa() {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      if (i == j)
   	tab[i][j] = 1;
}
  
template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::transponuj() {
  MacierzKw<TYP,ROZMIAR> Kopia = (*this);
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      tab[j][i] = Kopia[i][j];
 }

template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::przestaw_wiersze(unsigned int index1, unsigned int index2) {
  if (index1 < 0 || index1 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (index2 < 0 || index2 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
   Wektor<TYP,ROZMIAR> pomocniczy = tab[index1];
  tab[index1] = tab[index2];
  tab[index2] = pomocniczy;
}

template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::przestaw_kolumny(unsigned int index1, unsigned int index2) {
  (*this).transponuj();
  (*this).przestaw_wiersze(index1,index2);
  (*this).transponuj();
}

template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::zmien_wiersz(unsigned int index, const Wektor<TYP,ROZMIAR> W) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }   
    tab[index] = W;
}

template<class TYP, unsigned int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::zmien_kolumne(unsigned int index, const Wektor<TYP,ROZMIAR> W) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  (*this).transponuj();
  tab[index] = W;
  (*this).transponuj();
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR-1> pomniejsz_macierz(const MacierzKw<TYP,ROZMIAR> &M, unsigned int index1, unsigned int index2){
  MacierzKw<TYP,ROZMIAR-1> Mniejsza;
  if (index1 < 0 || index1 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (index2 < 0 || index2 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (ROZMIAR == 1){
    cerr << "Macierz jednoelementowa. Nie można pomniejszyc" << endl;
    exit(1);
  }
  
  unsigned int m=0;
  for (unsigned int i=0; i < ROZMIAR; ++i){
    if (i != index1){
      unsigned int n=0;
      for (unsigned int j=0; j < ROZMIAR; ++j){
  	if (j != index2){
  	  Mniejsza[m][n] = M[i][j];
  	  ++n;
  	}
      }
      ++m;
    }  
  }
  return Mniejsza;
}

// Metoda pozwalajaca na oblicznie wyznacznikow roznymi metodami
template<class TYP, unsigned int ROZMIAR>
TYP MacierzKw<TYP,ROZMIAR>::wyznacznik(Wyz_Metoda metoda) const {
  TYP det;
  det = 0;
  switch(metoda){
  case Gauss: {
    MacierzKw<TYP,ROZMIAR> P = *this;
    unsigned int k;
    double epsilon = 0.000000001;
    double zmian_miejsc = 1;
    det = 1;
    for(unsigned int i=0; i < ROZMIAR; ++i){
      for(k = i+1; abs(P[i][i]) < epsilon; ++k){   // Uzyskiwanie wartosci roznej od 0
	if(k >= ROZMIAR)         // na przekatnej macierzy kwadratowej
	  return (det = 0); 
	P.przestaw_wiersze(i,k);
	zmian_miejsc *= -1;
      }
      det = det * P[i][i];    
      P[i] = P[i] / P[i][i];                
      for(unsigned int j=i+1; j < ROZMIAR; ++j){    // Zerowanie elementow
	P[j] = P[j] - (P[i] * P[j][i]);    // pod przekatna
      }   
    }
    det *= zmian_miejsc;
    return det;
  }
    
  case Laplace: {
    det = 0;
    int parzystosc = 1;
    for (unsigned int i=0; i < ROZMIAR; ++i) {
      if (tab[i][0] != 0) {
	MacierzKw<TYP,ROZMIAR-1> Mniejsza;
	Mniejsza = pomniejsz_macierz((*this),i,0);
	det += tab[i][0] * parzystosc  * Mniejsza.wyznacznik(Laplace);
      }
      parzystosc *= -1;
    }
    return det;
  }
  }
  return det;
}

template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::macierz_dopelnien () const{
  if(ROZMIAR <= 1) {
    cerr << "Macierz jednoelementowa. Nie mozna wyznaczyc dopelnienia algebraicznego" << endl;
    exit(1);
  }
    
  MacierzKw<TYP,ROZMIAR> Dopelnien;
  double znak = 1;
  MacierzKw<TYP,ROZMIAR-1> Mniejsza;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j) {
      Mniejsza = pomniejsz_macierz((*this),i,j);
      Dopelnien[i][j] = Mniejsza.wyznacznik(Laplace) * znak;
      znak *= -1;
    }
  return Dopelnien;
}


template<class TYP, unsigned int ROZMIAR>
MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::odwroc(Odw_Metoda metoda) const {
  switch (metoda) {
  case Definicja: {   // wykorzystuje prowizorke dla 3x3
    double epsilon = 0.000000001;
    TYP wyznacznik;
    MacierzKw<TYP,ROZMIAR> Odwrotna;
    MacierzKw<TYP,ROZMIAR> Dopelnien;
    
    wyznacznik = (*this).wyznacznik(Laplace);
    if (abs(wyznacznik) < epsilon){
      cerr << "Macierz osobliwa, nieodwracalna" << endl;
      exit(1);
    }
    
    Dopelnien = (*this).macierz_dopelnien();
    Dopelnien.transponuj();
    
    Odwrotna = Dopelnien / wyznacznik;
    
    return Odwrotna;
  }

  case Gauss_Jordan: {
    MacierzKw<TYP,ROZMIAR> Odwrotna;
    Odwrotna.MacierzJednostkowa();
    MacierzKw<TYP,ROZMIAR> P = *this;
    double epsilon = 0.000000001;
    for(unsigned int i=0; i < ROZMIAR; ++i){
      for(unsigned int k=i+i; abs(P[i][i]) < epsilon; ++k){
	if(k >= ROZMIAR){  
	  cout << "Macierz jest nieodwracalna, bo jest osobliwa" << endl;
	  exit(1);
	}
	P.przestaw_wiersze(i,k);
	Odwrotna.przestaw_wiersze(i,k);
      }
      Odwrotna[i] = Odwrotna[i] / P[i][i];
      P[i] = P[i] / P[i][i];
      
      for(unsigned int j=i+1; j < ROZMIAR; ++j){  
	Odwrotna[j] = Odwrotna[j] - (Odwrotna[i] * P[j][i]);
	P[j] = P[j] - (P[i] * P[j][i]);
      }   
    }
    
    for(unsigned int i = ROZMIAR-1; i > 0; --i) {
      for(unsigned int j=0; j < i; ++j){  
	Odwrotna[j] = Odwrotna[j] - (Odwrotna[i] * P[j][i]);
	P[j] = P[j] - (P[i] * P[j][i]);
      }   
    }
    
    return Odwrotna;
  } 
  }
  return (*this);
}




/********** SPECJALIZACJE **********/

/*!
 * \brief Specjalizacja wyliczenia wyznacznika 
 *
 * Specjalizacja funkcji wylicza wyznacznik macierzy dla rozmiaru 1 z elementem 
 * typu double. Wyznacznik równy jest jedynemu elementowi.
 * \param[in] metoda - metoda obliczania wyznacznika.
 * \return Zwraca jedyny element macierzy jako wyznacznik.
 */
template<>
double MacierzKw<double,1>::wyznacznik(Wyz_Metoda metoda) const {
  return tab[0][0];
}

/*!
 * \brief Specjalizacja tworzenia macierzy dopełnień 
 *
 * Specjalizacja funkcji macierzy dopełnień, która zawsze kończy działanie 
 * programu, ponieważ nie można stworzyć dopełnienia algebraicznego macierzy 
 * jednoelementowej.
 * \return Zawsze kończy działanie programu.
 */
template<>
MacierzKw<double,1> MacierzKw<double,1>::macierz_dopelnien() const {
  cerr << "Macierz jednoelementowa. Nie mozna wyznaczyc dopelnienia algebraicznego" << endl;
  exit(1);
}
