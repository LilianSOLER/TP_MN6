#include "mnblas.h"
#include "complexe.h"

double sqrt(double number)
{
    double error = 0.00001; //define the precision of your result
    double s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    return s;
}

float sqrtf(float number)
{
    float error = 0.00001; //define the precision of your result
    float s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    return s;
}

float  mnblas_sasum(const int N, const float *X, const int incX){
  register unsigned int i = 0;
  float  sum = 0;

  for (; i < N; i += incX)
  {
    sum += sqrtf(X[i] * X[i]);
  }

  return sum;
}

double mnblas_dasum(const int N, const double *X, const int incX){
  register unsigned int i = 0;
  double sum = 0;

  for (; i < N; i += incX)
  {
    sum += sqrt(X[i] * X[i]);
  }

  return sum;
}

float mnblas_scasum(const int N, const void *X, const int incX){
  register unsigned int i = 0;
  float  sum = 0;
  complexe_float_t *X_tmp = (complexe_float_t *)X;

  for (; i < N; i += incX)
  {
    sum += sqrtf(X_tmp[i].real * X_tmp[i].real + X_tmp[i].imaginary * X_tmp[i].imaginary);
  }

  return sum;
}

double mnblas_dzasum(const int N, const void *X, const int incX){
  register unsigned int i = 0;
  double sum = 0;
  complexe_double_t *X_tmp = (complexe_double_t *)X;

  for (; i < N; i += incX)
  {
    sum += sqrt(X_tmp[i].real * X_tmp[i].real + X_tmp[i].imaginary * X_tmp[i].imaginary);
  }

  return sum;
}