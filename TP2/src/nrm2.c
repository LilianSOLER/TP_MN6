#include "mnblas.h"
#include "complexe.h"

double sqrt_(double number)
{
    double error = 0.001; //define the precision of your result
    double s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    return s;
}

float sqrtf_(float number)
{
    float error = 0.001; //define the precision of your result
    float s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    return s;
}

float mnblas_snrm2(const int N, const float *X, const int incX)
{
  register unsigned int i = 0;
  float sum = 0;
  for (; i < N; i += incX)
  {
    sum += X[i] * X[i];
  }
  return sqrtf_(sum);
}

double mnblas_dnrm2(const int N, const double *X, const int incX)
{
  register unsigned int i = 0;
  double sum = 0;
  for (; i < N; i += incX)
  {
    sum += X[i] * X[i];
  }
  return sqrt_(sum);
}

float mnblas_scnrm2(const int N, const void *X, const int incX)
{
  register unsigned int i = 0;
  float sum = 0;
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  for (; i < N; i += incX)
  {
    sum += X_tmp[i].real * X_tmp[i].real + X_tmp[i].imaginary * X_tmp[i].imaginary;
  }
  return sqrtf_(sum);
}

double mnblas_dznrm2(const int N, const void *X, const int incX)
{
  register unsigned int i = 0;
  double sum = 0;
  complexe_double_t *X_tmp = (complexe_double_t *)X;
  for (; i < N; i += incX)
  {
    sum += X_tmp[i].real * X_tmp[i].real + X_tmp[i].imaginary * X_tmp[i].imaginary;
  }
  return sqrt_(sum);
}