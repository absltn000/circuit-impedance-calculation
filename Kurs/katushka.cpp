#include "katushka.h"

Katushka::Katushka(const Katushka& x)
{
  setres(x.getres());
  setnumber(x.getnumber());
  chastota = x.chastota;
}

Katushka Katushka::operator=(const Katushka& x)
{
  setres(x.getres());
  setnumber(x.getnumber());
  chastota = x.chastota;
  return x;
}

double Katushka::getresistn()
{
  return getres() * chastota;
}

//int Katushka::getnuberkatushka()
//{
  //return getnumber();
//}

char Katushka::preobraz()
{
  return 'L';
}

bool Katushka::getel(std::string y)
{
  std::string y1 = "";
  std::string y2 = "";

  int i = 0;
  std::string prom = "";
  for (int j = 0; j < y.length(); j++)
    if (y[j] != ' ')
      prom += y[j];
  y = prom;
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
    if (y1[0] != 'L' && y[0] != 'l')
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

void Katushka::pushchastota(int x)
{
  chastota = x;
}

void Katushka::printel(std::ostream& out) const
{
  if (this->getnumber() != -1)
    out << "L" << this->getnumber() << ": " << this->getres() << " Gn" << std::endl;
  else
    out << "Undefined coil";
}

Component& Katushka::plus(Component& x)
{
  Katushka* y = new Katushka(this->getresistn() + x.getresistn(), chastota);
  return *y;
}

Component& Katushka::mnozh(Component& x)
{
  Katushka* y = new Katushka(this->getresistn() * x.getresistn() / (this->getresistn() + x.getresistn()),chastota);
  return *y;
}

Component& Katushka::impedans(Component& x, bool v)
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

double Katushka::getchastota() const
{
  return chastota;
}
