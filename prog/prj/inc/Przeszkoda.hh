#ifndef PRZESZKODA
#define PRZESZKODA

class Przeszkoda {
public:
  virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> Inter) =0;

};


#endif
