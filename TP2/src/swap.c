#include "mnblas.h"

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

void mncblas_cswap(const int nElmts, void *X, const int incX,
                   void *Y, const int incY)
{

  return;
}

void mncblas_zswap(const int nElmts, void *X, const int incX,
                   void *Y, const int incY)
{

  return;
}
