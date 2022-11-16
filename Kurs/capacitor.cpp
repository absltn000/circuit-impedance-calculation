#pragma once
#include "capacitor.h"

Copasitor::Copasitor(const Copasitor& x)
{
  setres(x.getres());
  setnumber(x.getnumber());
  chastota = x.chastota;
}

Copasitor Copasitor::operator=(const Copasitor& x)
{
  setres(x.getres());
  setnumber(x.getnumber());
  chastota = x.chastota;
  return x;
}

double Copasitor::getresistn()
{
  return ((double)1/(getres() * chastota));
}

char Copasitor::preobraz()
{
  return 'C';
}

void Copasitor::pushchastota(int x)
{
  chastota = x;
}

bool Copasitor::getel(std::string y)
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
    if (y1[0] != 'C' && y[0] != 'c')
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
  this->pushnumber(stoi(y1));
  this->push(stod(y2));
  return true;
}

void Copasitor::printel(std::ostream& out) const
{
  if (this->getnumber() != -1)
    out << "C" << this->getnumber() << ": " << this->getres() << " F" << std::endl;
  else
    out << "Undefined capacitor";
}

Component& Copasitor::plus(Component& x)
{
  Copasitor* y = new Copasitor(this->getresistn() + x.getresistn(), chastota);
  return *y;
}

Component& Copasitor::mnozh(Component& x)
{
  Copasitor* y = new Copasitor(this->getresistn() * x.getresistn() / (this->getresistn() + x.getresistn()), chastota);
  return *y;
}

Component& Copasitor::impedans(Component& x, bool v)
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

double Copasitor::getchastota() const
{
  return chastota;
}
