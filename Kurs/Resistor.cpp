#include "Resistor.h"

void Resistor::push(int x)
{
  this->resistn = x;
}

void Resistor::pushnumber(int x)
{
  this->number = x;
}

Resistor::Resistor(const Resistor& x)
{
  resistn = x.getres();
  number = x.getnumber();
}

double Resistor::getresistn()
{
  return this->resistn;
}

char Resistor::preobraz()
{
  return 'R';
}

bool Resistor::getel(std::string y)
{
  std::string y1 = "";
  std::string y2 = "";
  std::string prom = "";
  for (int j = 0; j < y.length(); j++)
    if (y[j] != ' ')
      prom += y[j];
  y = prom;
  int i = 0;
  while (y[i] != ':' && i < y.length()) {
    if (y[i] != ' ')
    {
      y1 += y[i];
    }
    i++;
  }
  i++;
  while (i < y.length()) {
    y2 += y[i];
    i++;
  }
  if (y1.length() < 2 || y1.length() > 4)
    return false;
  else
  {
    if (y1[0] != 'R' && y[0] != 'r')
      return false;
    else
    {
      i = 1;
      std::string y11 = "";
      while (i < y1.length()) {
        if (y1[i] > '9' || y1[i] < '0')
          return false;
        else
          y11 += y1[i];
        i++;
      }
      if (stoi(y11) > 100)
        return false;
      else
        y1 = y11;
    }
  }
  i = 0;
  int k = 0;
  while (i < y2.length()) {
    if (y2[i] > '9' || y2[i] < '0')
      return false;
    else
      if (y2[i] == '.')
        k++;
    if (k > 1) return false;
    i++;
  }
  resistn = stod(y2);
  number = stoi(y1);
  return true;
}

void Resistor::printel(std::ostream& out) const
{
  if (number != -1)
    out << "R" << number << ": " << resistn << " Om" << std::endl;
  else
    out << "Undefined resistor";
}

Component& Resistor::plus(Component& x)
{
  Resistor *y = new Resistor(resistn + x.getresistn());
  return *y;
}

Component& Resistor::mnozh(Component& x)
{
  Resistor* y=new Resistor(resistn * x.getresistn() / (resistn + x.getresistn()));
  return *y;
}

int Resistor::getnumber() const
{
  return number;
}

void Resistor::setnumber(int x)
{
  number = x;
}

void Resistor::setres(int x)
{
  resistn = x;
}

Component& Resistor::impedans(Component& x, bool v)
{
  if (v == false) {
    Resistor* y = new Resistor(this->getresistn() * x.getresistn() / (sqrt(this->getresistn() * this->getresistn()) - sqrt(x.getresistn() * x.getresistn())));
    return *y;
  }
  else {
    Resistor* y = new Resistor(this->getresistn() * x.getresistn() / (sqrt(this->getresistn() * this->getresistn()) + sqrt(x.getresistn() * x.getresistn())));
    return *y;
  }
}

