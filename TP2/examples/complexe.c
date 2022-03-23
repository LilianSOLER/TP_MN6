#include <stdio.h>
#include <stdlib.h>
#include "complexe.h"

complexe_float_t add_complexe_float(const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r;

  r.real = c1.real + c2.real;
  r.imaginary = c1.imaginary + c2.imaginary;

  return r;
}

complexe_double_t add_complexe_double(const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r;

  r.real = c1.real + c2.real;
  r.imaginary = c1.imaginary + c2.imaginary;

  return r;
}

complexe_float_t mult_complexe_float(const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r;

  r.real = c1.real * c2.real - c1.imaginary * c2.imaginary; // i*i = i^2 = -1 so Re(r) = Mult(RE()) - Mult(Im())
  r.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;

  return r;
}

complexe_double_t mult_complexe_double(const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r;

  r.real = c1.real * c2.real - c1.imaginary * c2.imaginary; // i*i = i^2 = -1 so Re(r) = Mult(RE()) - Mult(Im())
  r.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;

  return r;
}

complexe_float_t div_complexe_float(const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r;

  float denum = c1.real * c1.real + c2.real * c2.real;
  r.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denum;
  r.imaginary = (c1.imaginary * c2.real + c1.real * c2.imaginary) / denum;

  return r;
}

complexe_double_t div_complexe_double(const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r;

  double denum = c1.real * c1.real + c2.real * c2.real;
  r.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denum;
  r.imaginary = (c1.imaginary * c2.real + c1.real * c2.imaginary) / denum;

  return r;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TESTs

void test_mult_float()
{
  complexe_float_t c1, c2, c3;
  float a = 1000.0; // max value of float
  for (int i = 0; i < 100; i++)
  {
    float x1 = ((float)rand() / (float)(RAND_MAX)) * a;
    float y1 = ((float)rand() / (float)(RAND_MAX)) * a; // create random number to generate random complexe number xi are real part
    float x2 = ((float)rand() / (float)(RAND_MAX)) * a;
    float y2 = ((float)rand() / (float)(RAND_MAX)) * a; // and yi are imaginary part
    c1 = (complexe_float_t){x1, y1};
    c2 = (complexe_float_t){x2, y2};
    c3 = mult_complexe_float(c1, c2);
    printf("%f;%f;%f;%f;%f;%f\n", c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary);
  }
}

void test_mult_double()
{
  complexe_double_t c1, c2, c3;
  double a = 1000.0; // max value of float
  for (int i = 0; i < 100; i++)
  {
    double x1 = ((double)rand() / (double)(RAND_MAX)) * a;
    double y1 = ((double)rand() / (double)(RAND_MAX)) * a; // create random number to generate random complexe number xi are real part
    double x2 = ((double)rand() / (double)(RAND_MAX)) * a;
    double y2 = ((double)rand() / (double)(RAND_MAX)) * a; // and yi are imaginary part
    c1 = (complexe_double_t){x1, y1};
    c2 = (complexe_double_t){x2, y2};
    c3 = mult_complexe_double(c1, c2);
    printf("%lf;%lf;%lf;%lf;%lf;%lf\n", c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary);
  }
}

void test_div_float(){
  complexe_float_t c1, c2, c3;
  float a = 1000.0; // max value of float
  for (int i = 0; i < 100; i++)
  {
    float x1 = ((float)rand() / (float)(RAND_MAX)) * a;
    float y1 = ((float)rand() / (float)(RAND_MAX)) * a; // create random number to generate random complexe number xi are real part
    float x2 = ((float)rand() / (float)(RAND_MAX)) * a;
    float y2 = ((float)rand() / (float)(RAND_MAX)) * a; // and yi are imaginary part
    c1 = (complexe_float_t){x1, y1};
    c2 = (complexe_float_t){x2, y2};
    c3 = div_complexe_float(c1, c2);
    printf("%f;%f;%f;%f;%f;%f\n", c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary);
  }
}

void test_div_double()
{
  complexe_double_t c1, c2, c3;
  double a = 1000.0; // max value of float
  for (int i = 0; i < 100; i++)
  {
    double x1 = ((double)rand() / (double)(RAND_MAX)) * a;
    double y1 = ((double)rand() / (double)(RAND_MAX)) * a; // create random number to generate random complexe number xi are real part
    double x2 = ((double)rand() / (double)(RAND_MAX)) * a;
    double y2 = ((double)rand() / (double)(RAND_MAX)) * a; // and yi are imaginary part
    c1 = (complexe_double_t){x1, y1};
    c2 = (complexe_double_t){x2, y2};
    c3 = div_complexe_double(c1, c2);
    printf("%lf;%lf;%lf;%lf;%lf;%lf\n", c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary);
  }
}
