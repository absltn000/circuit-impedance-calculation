#pragma once
#include <string>
#include <fstream>
#include <iostream>
class Component
{
public:
  Component() {};
  virtual void printel(std::ostream& out) const = 0;
  virtual char preobraz() = 0;
  virtual double getresistn() = 0;
  virtual ~Component() {};
  virtual bool getel(std::string y) = 0;
  virtual Component& plus(Component& x) = 0;
  virtual Component& mnozh(Component& x) = 0;
  friend Component& operator*(  Component& x, Component& y);
  friend Component& operator+( Component& x, Component& y);
  virtual Component& impedans(Component& x, bool v) = 0;

}; 
std::ostream& operator<<(std::ostream& out, const Component& x);
Component& pls(Component& x, Component& y);
Component& mn(Component& x, Component& y);





