#pragma once
#include "document.h"
#include <cstdlib>

void document::nuchalo1(int argc, char* argv[])
{
  std::ifstream y;
  y.open(argv[1]);
  std::string g;
  std::string v;
  
  if (!y.eof())
  {
    std::string a;
    getline(y, a);
    formula(a);
  }
  if (!y.eof())
  {
    std::string a;
    getline(y, a);
    chastota_pr(a);
  }
  while (!y.eof()) {
    std::string z;
    getline(y, z);
    element(z);
  }
  y.close();
}

void document::nuchalo2(int argc, char* argv[])
{
  bool er2 = true;
  std::ofstream m;
  m.open(argv[2]);
  std::string answer;
  do {
    std::cout << "Would you take data from file? (Yes/No)" << std::endl;
    getline(std::cin, answer);
  } while (answer != "No" && answer != "Yes");
  if (answer == "Yes") nuchalo1(argc, argv);
  do {
    std::cout << "Enter number 0-10:" << std::endl;
    std::cout << "1-Add formula" << std::endl;
    std::cout << "2-Add frequency" << std::endl;
    std::cout << "3-Add one element" << std::endl;
    std::cout << "4-Add any elements" << std::endl;
    std::cout << "5-Check errors" << std::endl;
    std::cout << "6-Check formula" << std::endl;
    std::cout << "7-Check frequency" << std::endl;
    std::cout << "8-Check all elements" << std::endl;
    std::cout << "9-Check all components" << std::endl;
    std::cout << "10-Do calculations" << std::endl;
    std::cout << "11-Exit from the programm" << std::endl;
    std::string a;
    getline(std::cin, a);
    bool er = true;
    int b;
    if (a.length() == 1)
    {
      if (a[0] >= '1' && a[0] <= '9')
        b = std::stoi(a);
    }
    else
      if (a.length() == 2)
      {
        if ((a[0] == '1' && a[1] == '0') || (a[0] == '1' && a[1] == '1'))
          b = std::stoi(a);
        else
          er = false;
      }
      else er = false;
    if (er != false)
    {
      switch (b)
      {
      case (1):
      {
        bool er1 = true;
        std::string n = "";
        do {
          std::cout << "Enter the formula or \"-1\" to exit for the menu" << std::endl;

          getline(std::cin, n);
          if (n == "-1")
            er1 = true;
          else
            er1 = formula(n);
        } while (er1 != true);
      }
      break;
      case (2):
      {
        bool er1 = true;
        std::string n;
        do {
          std::cout << "Enter the frequency or \"-1\" to exit for the menu" << std::endl;

          getline(std::cin, n);
          if (n == "-1")
            er1 = true;
          else
            er1 = chastota_pr(n);
        } while (er != true);
      }
      break;
      case (3):
      {
        bool er1 = false;
        std::string n;
        do {
          std::cout << "Enter the element or \"-1\" to exit for the menu" << std::endl;

          getline(std::cin, n);
          if (n == "-1")
            er1 = true;
          else
            er1 = element(n);
        } while (er != true);
      }
      break;
      case (4):
      {
        bool er1 = false;
        std::string n;
        do {
          std::cout << "Enter the elements or \"-1\" to exit for the menu" << std::endl;
          getline(std::cin, n);
          if (n == "-1")
            er1 = true;
          else
            element(n);
        } while (er1 != true);
      }
      break;
      case (5):
      {
        if (fv == true && fg == true && x.error_element(false) == true)
          std::cout << "You haven\'t errors." << std::endl;
        if (fv == false)
          std::cout << "Formul is not defined." << std::endl;
        if (fg == false)
          std::cout << "Frequency is not defined." << std::endl;
        x.error_element(true);
      }
      break;
      case (6):
        if (fv == true)
        {
          std::cout << "Formul: ";
          x.printformul(std::cout);
        }
        else
          std::cout << "Formul is not defined." << std::endl;
        break;
      case (7):
        if (fg == true)
        {
          std::cout << "Frequency: " << gg << std::endl;
        }
        else
          std::cout << "Frequency is not defined." << std::endl;
        break;
      case (8):
        x.elements(std::cout);
        break;
      case(9):
        if (fv == true)
        {
          std::cout << "Formul:";
          x.printformul(std::cout);
        }
        else
          std::cout << "Formul is not defined." << std::endl;
        if (fg == true)
        {
          std::cout << "Frequency: " << gg << std::endl;
        }
        else
          std::cout << "Frequency is not defined." << std::endl;
        x.elements(std::cout);
        break;
      case (10):
      {
        std::string ans;
        if (fv == true && fg == true && x.error_element(false) == true)
        {
          std::cout.precision(10);
          std::cout << "Valid decision:" << (x.eval(x.infx2pstfx()))->getresistn() << " Om" << std::endl;
          complex y(x.eval1(x.infx2pstfx()).getreal(), x.eval1(x.infx2pstfx()).getimaginary());
          std::cout << "An imaginary solution: ";
          if (y.getreal() == 0 && y.getimaginary() == 0)
            std::cout << "0 Om" << std::endl;
          else
            if (y.getimaginary() == 0)
              std::cout << y.getreal() << " Om" << std::endl;
            else
              if (y.getreal() == 0)
                std::cout << y.getimaginary() << "i Om" << std::endl;
              else
                if (y.getimaginary() >= 0)
                  std::cout << y.getreal() << "+" << y.getimaginary() << "i Om" << std::endl;
                else
                  std::cout << y.getreal() << y.getimaginary() << "i Om" << std::endl;
          do {
            std::cout << "Do you want to save all output data in file? (Yes/No)" << std::endl;
            getline(std::cin, ans);
          } while (ans != "No" && ans != "Yes");
          if (ans == "Yes")
          {
            m << "Formul:";
            x.printformul(m);
            m << "Frequency: " << gg << std::endl;
            x.elements(m);
          }
        }
        else
        {
          std::cout << "You have error in data:" << std::endl;
          if (fv != true)
            std::cout << "You haven\'t correct formul." << std::endl;
          if (fv != true)
            std::cout << "You haven\'t correct frequency." << std::endl;
          x.error_element(true);
        }
      }
      break;
      case (11):
        exit(1);
        break;
      }
    }
  } while (er2!=false);
}

bool document::formula(std::string v)
{
  if (x.pr_formula(v))
  {
    fv = true;
    std::cout << "Formula have been wrotten successied: " << v << std::endl;
    return true;
  }
  else 
  {
      std::cout << "Formula haven`t been wrotten successied: " << v << std::endl;
      return false;
  }
}

bool document::element(std::string z)
{
  Resistor* r = new Resistor;
  Katushka* l = new Katushka;
  Copasitor* c = new Copasitor;
  if (r->getel(z))
  {
    x.pushres(*r);
    std::cout << *r;
    return true;
  }
  else
    if (l->getel(z))
    {
      if (fg == true)
        l->pushchastota(gg);
      x.pushkat(*l);
      std::cout << *l;
      return true;
    }
    else
      if (c->getel(z))
      {
        if (fg == true)
          c->pushchastota(gg);
        x.pushcop(*c);
        std::cout << *c;
        return true;
      }
      else
      {
        std::cout << "Element not defined: " << z << std::endl;
        return false;
      }
}

bool document::chastota_pr(std::string g)
{
  if (x.pr_chastota(g)) {
    std::cout << "Frequency have been wrotten successied: " << g << std::endl;
    gg= stod(g);
    fg = true;
    x.pushchastota(gg);
    return true;
  }
  else {
    std::cout << "Frequency haven`t been wrotten successied: " << g << std::endl;
    return false;
  }
}
