#pragma once
#include "Resistor.h"
#include "Component.h"

class Copasitor : 
  public Resistor
{
  double chastota;
public:
  Copasitor() :Resistor(1, -1), chastota(1) {};
  Copasitor(double res, double chast, int number) :Resistor(res, number), chastota(chast) {};
  Copasitor(double res, double chast) :Resistor(res, -1), chastota(chast) {};
  Copasitor(int number) :Resistor(1, number), chastota(1) {};
  Copasitor(const Copasitor& x);
  Copasitor operator=(const Copasitor& x);
  virtual double getresistn();
  virtual ~Copasitor() {};
  virtual char preobraz();
  void pushchastota(int x);
  virtual bool getel(std::string y);
  virtual void printel(std::ostream& out) const;
  virtual Component& plus(Component& x);
  virtual Component& mnozh(Component& x);
  virtual Component& impedans(Component& x, bool v);
  double getchastota() const;
};
