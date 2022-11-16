
#include "Component.h"

std::ostream& operator<<(std::ostream& out, const Component& x)
{
  x.printel(out);
  return out;
}





Component& operator+( Component& x,  Component& y)
{
  if (x.preobraz() == x.preobraz())
    return x.plus(y);
  else
    if (x.preobraz() != 'R' && y.preobraz() != 'R')
      return x.impedans(y, false);
    else
      return x.impedans(y, true);
}

Component& operator*(Component& x,Component& y)
{
    return x.mnozh(y);
}

Component& pls(Component& x, Component& y)
{
    return x + y;
}

Component& mn(Component& x, Component& y)
{
  return x * y;
}
