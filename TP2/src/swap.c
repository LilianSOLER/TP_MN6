#include "mnblas.h"
#include "complexe.h"

void mncblas_sswap(const int N, float *X, const int incX,
                   float *Y, const int incY)
{
  register unsigned int i = 0;
  register unsigned int j = 0;
  register float save;

  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    save = Y[j];
    Y[j] = X[i];
    X[i] = save;
  }

  return;
}

void mncblas_dswap(const int N, double *X, const int incX,
                   double *Y, const int incY)
{
  double save;
  for (int i = 0, j = 0; ((i < N) && (j < N)); i += incX, j += incY)
  {
    save = Y[j];
    Y[j] = X[i];
    X[i] = save;
  }

  return;
}

void mncblas_cswap(const int N, void *X, const int incX,
                   void *Y, const int incY)
{
complexe_float_t save;
  complexe_float_t *X_tmp = (complexe_float_t *) X;
  complexe_float_t *Y_tmp = (complexe_float_t *) Y;
  for (int i = 0, j = 0; ((i < N) && (j < N)); i += incX, j += incY)
  {
    save.real = Y_tmp[j].real;
    save.imaginary = Y_tmp[j].imaginary;
    Y_tmp[j].real = X_tmp[i].real;
    Y_tmp[j].imaginary = X_tmp[i].imaginary;
    X_tmp[i].real = save.real;
    X_tmp[i].imaginary = save.imaginary;
  }
  /*
  X=X_tmp;
  Y=Y_tmp;*/
  return;
}

void mncblas_zswap(const int N, void *X, const int incX,
                   void *Y, const int incY)
{
  complexe_double_t save;
  complexe_double_t *X_tmp = (complexe_double_t *) X;
  complexe_double_t *Y_tmp = (complexe_double_t *) Y;
  for (int i = 0, j = 0; ((i < N) && (j < N)); i += incX, j += incY)
  {
    save.real = Y_tmp[j].real;
    save.imaginary = Y_tmp[j].imaginary;
    Y_tmp[j].real = X_tmp[i].real;
    Y_tmp[j].imaginary = X_tmp[i].imaginary;
    X_tmp[i].real = save.real;
    X_tmp[i].imaginary = save.imaginary;
  }
  /*
  X=X_tmp;
  Y=Y_tmp;*/
  return;
}
