#pragma once
#include "Resistor.h"

class Katushka : 
  public Resistor
{
  double chastota;
public:
  Katushka() :Resistor(1,-1), chastota(1) {};
  Katushka(double res, double chast, int number) :Resistor(res, number), chastota(chast) {};
  Katushka(double res, double chast) :Resistor(res, -1), chastota(chast) {};
  Katushka(int number) :Resistor(1, number), chastota(1) {};
  Katushka(const Katushka& x);
  Katushka operator=(const Katushka& x);
  virtual double getresistn();
  virtual ~Katushka() {};
  virtual char preobraz();
  virtual bool getel(std::string y);
  void pushchastota(int x);
  virtual void printel(std::ostream& out) const;
  virtual Component& plus(Component& x);
  virtual Component& mnozh(Component& x);
  virtual Component& impedans(Component& x, bool v);
  double getchastota() const;
};
