#pragma once
#include <cmath>

class complex {
  double real;
  double imaginary;
public:
  complex() :real(0), imaginary(0) {};
  complex(double real) :real(real), imaginary(0) {};
  complex(double x, double y) :real(x), imaginary(y) {};
  double getreal() const
  {
    return real;
  }
  double getimaginary() const
  {
    return imaginary;
  }
  complex operator+ (complex& x) {
    complex res;
    res.real = real + x.real;
    res.imaginary = imaginary + x.imaginary;
    return res;
  }
  complex operator* (complex& x) {
    complex s;
    s.real = real * x.real + x.imaginary * imaginary;
    s.imaginary = imaginary * x.real + x.imaginary * real;
    return s;
  }
  complex operator/ (complex& x) {
    complex s;
    s.real = (x.real * real + x.imaginary * imaginary) / (x.real * x.real + x.imaginary * x.imaginary);
    s.imaginary = (imaginary * x.real - real * x.imaginary) / (x.real * x.real + x.imaginary * x.imaginary);
    return s;
  }
  ~complex() {};
};

