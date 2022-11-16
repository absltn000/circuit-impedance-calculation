#pragma once
#include <string>
#include "electricalcircuit.h"
class document
{
  electricalcircuit x;
  bool fv;
  bool fg;
  double gg;
public:
  document() :x(), fv(false), fg(false), gg(1) {};
  void nuchalo1(int argc, char* argv[]);
  void nuchalo2(int argc, char* argv[]);
  bool formula(std::string v);
  bool element(std::string z);
  bool chastota_pr(std::string g);
  ~document() {};
};


