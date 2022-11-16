#include "electricalcircuit.h"
electricalcircuit::electricalcircuit() {
  arr = new Resistor[102];
  arr1 = new Katushka[102];
  arr2 = new Copasitor[102];
}
electricalcircuit::~electricalcircuit()
{
  delete[] arr;
  delete[] arr1;
  delete[] arr2;
}
std::string electricalcircuit::infx2pstfx() {
  TStack<char> kkk;
  std::string p = "";
  TStack<std::string> hhh;
  TStack<int> mmm;
  int t[1000];
  t['*'] = 1;
  t['+'] = 1;
  std::string a;
  int coef = 0;
  a = form;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '(') {
      coef += 2;
    }
    else if (a[i] == ')') {
      coef -= 2;
    }
    else if (((a[i] >= '0') && (a[i] <= '9')) || (a[i] == 'R') || (a[i] == 'r') || (a[i] == 'l') || (a[i] == 'L') || (a[i] == 'C') || (a[i] == 'c')) {
      std::string z = "";
      do {
        z += a[i];
        i++;
      } while ((i < a.length()) && (((a[i] >= '0') && (a[i] <= '9')) || a[i] == 'R'));
      i--;
      hhh.push(z);
    }
    else if (kkk.isEmpty()) {
      kkk.push(a[i]);
      mmm.push(t[a[i]] + coef);
    }
    else if (t[a[i]] + coef > mmm.get()) {
      kkk.push(a[i]);
      mmm.push(t[a[i]] + coef);
    }
    else {
      bool er = true;
      while ((!kkk.isEmpty()) && (er == true)) {
        if (mmm.get() >= t[a[i]] + coef) {
          std::string b = "";
          b += kkk.get();
          hhh.push(b);
          kkk.pop();
          mmm.pop();
        }
        else {
          er = false;
        }
      }
      kkk.push(a[i]);
      mmm.push(t[a[i]] + coef);
    }
  }
  while (!kkk.isEmpty()) {
    std::string b = "";
    b += kkk.get();
    hhh.push(b);
    kkk.pop();
    mmm.pop();
  }
  while (!hhh.isEmpty()) {
    p += (hhh.get() + ' ');
    hhh.pop();
  }
  std::string s = "";
  std::string x;
  for (int i = 0; i < p.length(); i++) {

    if (!((i == 0) && (p[p.length() - 1] == ' ')))
      if (p[p.length() - 1 - i] == ' ') {
        std::string l = "";
        for (int i = 0; i < x.length(); i++) {
          l += x[x.length() - i - 1];
        }
        l += " ";
        x = "";
        s = s + l;
      }
      else {
        x += p[p.length() - 1 - i];
      }
  }
  std::string l = "";
  for (int i = 0; i < x.length(); i++) {
    l += x[x.length() - i - 1];
  }
  x = "";
  s = s + l;
  return s;
}
Component* electricalcircuit::eval(std::string pst) {
  TStack<Component*> x;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      char m = pst[i - 1];
      std::string z = "";
      do {
        z += pst[i];
        i++;
      } while ((i < pst.length()) && ((pst[i] >= '0') && (pst[i] <= '9')));
      i--;
      if (m == 'R' || m == 'r') {
        x.push(&arr[stoi(z)]);
      }
      else if (m == 'L' || m == 'l') {
        x.push(&arr1[stoi(z)]);
      }
      else if (m == 'c' || m == 'C') {
        x.push(&arr2[stoi(z)]);
      }
    }
    else if (pst[i] == '+') {
      Component* b = x.get();
      x.pop();
      Component* v = x.get();
      x.pop();
      x.push(&pls(*v, *b));
    }
    else if (pst[i] == '*') {
      Component* b = x.get();
      x.pop();
      Component* v = x.get();
      x.pop();
      x.push(&mn(*v, *b));
    }
  }
  Component* z = x.get();
  return z;
}
complex electricalcircuit::eval1(std::string pst) {
  TStack<complex> x;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      char m = pst[i - 1];
      std::string z = "";
      do {
        z += pst[i];
        i++;
      } while ((i < pst.length()) && ((pst[i] >= '0') && (pst[i] <= '9')));
      i--;
      if (m == 'R' || m == 'r') {
        complex y(arr[stoi(z)].getresistn());
        x.push(y);
      }
      else if (m == 'L' || m == 'l') {
        complex y(0, arr1[stoi(z)].getresistn());
        x.push(y);
      }
      else if (m == 'c' || m == 'C') {
        complex y(0, arr2[stoi(z)].getresistn());
        x.push(y);
      }
    }
    else if (pst[i] == '+') {
      complex b = x.get();
      x.pop();
      complex v = x.get();
      x.pop();
      x.push(v + b);
    }
    else if (pst[i] == '*') {
      complex b = x.get();
      x.pop();
      complex v = x.get();
      x.pop();
      complex k = v * b;
      complex n = v + b;
      x.push(k / n);
    }
  }
  complex z = x.get();
  return z;
}
void electricalcircuit::getres3() {
  std::cout << "Enter nubers of resistor" << std::endl;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    std::cout << "Enter resistor quantity" << std::endl;
    std::cin >> x;
    arr[i].push(x);
  }
}
std::string electricalcircuit::getequation()
{
  std::string x;
  std::cout << "Enter equation" << std::endl;
  std::cin >> x;
  return x;
}
bool electricalcircuit::pr_chastota(std::string x) {
  std::string y2 = "";
  for (int j = 0; j < x.length(); j++)
    if (x[j] != ' ')
      y2 += x[j];
  int i = 0;
  int k = 0;
  for (i = 0; y2.length() > i; i++) {
    if (y2[i] > '9' || y2[i] < '0')
      return false;
    else
      if (y2[i] == '.')
        k++;
    if (k > 1) return false;
  }
  return true;
}
bool  electricalcircuit::pr_formula(std::string x) {
  if (x.length() == 0) {
    return false;
  }
  else {
    std::string x1 = "";
    if (x[0] == 'R' || x[0] == 'r' || x[0] == 'L' || x[0] == 'l' || x[0] == 'c' || x[0] == 'C' || x[0] == '(') {}
    else
      return false;
    if (x[x.length() - 1] == ')' || (x[x.length() - 1] >= '0' && x[x.length() - 1] <= '9')) {}
    else
      return 0;
    int k = 0;
    int k1 = 0;
    if (x[0] == '(') k++;
    for (int i = 1; i < x.length() - 1; i++)
    {

      if (x[i] == '(')
        if (x[i - 1] != '+' && x[i - 1] != '*' && x[i - 1] != '(')
          return false;
        else if (!(x[i + 1] == 'R' || x[i + 1] == 'r' || x[i + 1] == 'L' || x[i + 1] == 'l' || x[i + 1] == 'c' || x[i + 1] == 'C' || x[i + 1] == '('))
          return false;
        else
          k++;
      if (x[i] == ')')
        if (x[i + 1] != '+' && x[i + 1] != '*' && x[i + 1] != ')')
          return false;
        else if (!((x[i - 1] >= '0' && x[i - 1] <= '9') || x[i + 1] == ')'))
          return false;
        else
          k1++;
      if (k - k1 < 0)
        return false;
    }
    if (x[x.length() - 1] == ')') k1++;
    if (k - k1 < 0)
      return false;
    for (int i = 0; i < x.length(); i++)
    {
      if (x[i] != ')' && x[i] != '(')
        x1 += x[i];
    }
    std::string y1 = "";
    for (int j = 0; j < x1.length(); j++)
      if (x1[j] == '*' || x1[j] == '+')
      {
        int i = 0;
        if (y1.length() < 2 || y1.length() > 4)
          return false;
        else
        {
          char m = 0;
          if (!(y1[0] == 'R' || y1[0] == 'r' || y1[0] == 'L' || y1[0] == 'l' || y1[0] == 'c' || y1[0] == 'C'))
            return false;
          else
          {
            m = y1[0];
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
            if (m == 'r' || m == 'R') {
              if (arr[(stoi(y11))].getnumber() == -1)
                arr[(stoi(y11))].setnumber(-2);
              y1 = "";
            }
            else if (m == 'L' || m == 'l') {
              if (arr1[(stoi(y11))].getnumber() == -1) {
                Katushka c(-2);
                arr1[(stoi(y11))] = c;
              }
              y1 = "";
            }
            else if (m == 'c' || m == 'C') {
              if (arr2[(stoi(y11))].getnumber() == -1) {
                Copasitor b(-2);
                arr2[(stoi(y11))] = b;
              }
              y1 = "";
            }
          }
        }
      }
      else
        y1 += x1[j];
    int i = 0;
    if (y1.length() < 2 || y1.length() > 4)
      return false;
    else
    {
      char m = 0;
      if (!(y1[0] == 'R' || y1[0] == 'r' || y1[0] == 'L' || y1[0] == 'l' || y1[0] == 'c' || y1[0] == 'C'))
        return false;
      else
      {
        m = y1[0];
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
        if (m == 'r' || m == 'R') {
          if (arr[(stoi(y11))].getnumber() == -1)
            arr[(stoi(y11))].setnumber(-2);
          y1 = "";
        }
        else if (m == 'L' || m == 'l') {
          if (arr1[(stoi(y11))].getnumber() == -1) {
            Katushka c(-2);
            arr1[(stoi(y11))] = c;
          }
          y1 = "";
        }
        else if (m == 'c' || m == 'C') {
          if (arr2[(stoi(y11))].getnumber() == -1) {
            Copasitor b(-2);
            arr2[(stoi(y11))] = b;
          }
          y1 = "";
        }
      }
    }
  }
  form = x;
  return true;
}
void electricalcircuit::pushkat(Katushka& x)
{
  arr1[x.getnumber()] = x;
}
void electricalcircuit::pushres(Resistor& x)
{
  arr[x.getnumber()] = x;
}
void electricalcircuit::pushcop(Copasitor& x)
{
  arr2[x.getnumber()] = x;
}
bool electricalcircuit::error_element(bool vis)
{
  for (int i = 0; i <= 100; i++)
    if (arr[i].getnumber() == -2)
      if (vis == true)
        std::cout << "R" << i << " is not defined." << std::endl;
      else
        return false;
  for (int i = 0; i <= 100; i++)
    if (arr1[i].getnumber() == -2)
      if (vis == true)
        std::cout << "L" << i << " is not defined." << std::endl;
      else
        return false;
  for (int i = 0; i <= 100; i++)
    if (arr2[i].getnumber() == -2)
      if (vis == true)
        std::cout << "C" << i << " is not defined." << std::endl;
      else
        return false;
  return true;
}
void electricalcircuit::printformul(std::ostream& y)
{
  y << form << std::endl;
}
void electricalcircuit::elements(std::ostream& y)
{
  for (int i = 0; i <= 100; i++)
    if (arr[i].getnumber() >= 0)
      y << "R" << i << ": " << arr[i].getres() << " Om" << std::endl;
  for (int i = 0; i <= 100; i++)
    if (arr1[i].getnumber() >= 0)
      y << "L" << i << ": " << arr1[i].getres() << " G" << std::endl;
  for (int i = 0; i <= 100; i++)
    if (arr2[i].getnumber() >= 0)
      y << "C" << i << ": " << arr2[i].getres() << " F" << std::endl;
}

void electricalcircuit::pushchastota(double x)
{
  for (int i = 0; i <= 100; i++)
    if (arr1[i].getnumber() >= 0)
      arr1[i].pushchastota(x);
  for (int i = 0; i <= 100; i++)
    if (arr2[i].getnumber() >= 0)
      arr2[i].pushchastota(x);
}
