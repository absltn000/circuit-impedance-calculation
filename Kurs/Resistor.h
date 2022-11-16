#pragma once
#include <iostream>
#include "Component.h"
class Resistor : public Component
{
  double resistn;
  int number;
public:
  Resistor() : resistn(1), number(-1) {};
  Resistor(double res) : resistn(res), number(-1) {}
  Resistor(double res, int num) : resistn(res), number (num) {};
  Resistor(const Resistor& x);
  virtual double getresistn();
  double getres() const { return resistn; };
  void push(int x);
  void pushnumber(int x);
  virtual ~Resistor() {};
  virtual char preobraz();
  virtual bool getel(std::string y);
  virtual void printel(std::ostream& out) const;
  virtual Component& plus(Component& x);
  virtual Component& mnozh(Component& x);
  virtual Component& impedans(Component& x, bool v);
  int getnumber() const;
  void setnumber(int x);
  void setres(int x);
  Component& pls(Component& x, Component& y) {
    return x + y;
  }
  Component& mn(Component& x, Component& y) {
    return x * y;
  }
};


