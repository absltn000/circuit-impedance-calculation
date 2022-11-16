#pragma once
#include "Resistor.h"
#include "stack.h"
#include "katushka.h"
#include "capacitor.h"
#include "complex.h"
#include "Component.h"

class electricalcircuit
{
  Resistor* arr;
  Katushka* arr1;
  Copasitor* arr2;
  std::string form;
public:
  electricalcircuit();
  ~electricalcircuit();
  std::string infx2pstfx();
  Component* eval(std::string pst);
  complex eval1(std::string pst);
  void getres3();
  std::string getequation();
  bool pr_chastota(std::string x);
  bool pr_formula(std::string x);
  void pushkat(Katushka& x);
  void pushres(Resistor& x);
  void pushcop(Copasitor& x);
  bool error_element(bool vis);
  void printformul(std::ostream& y);
  void elements(std::ostream& y);
  void pushchastota(double x);
};


