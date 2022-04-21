#include "mnblas.h"
#include "complexe.h"

void mnblas_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
  register unsigned int i = 0, j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] += alpha * X[i];
  }

  return;
}

void mnblas_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY){
  register unsigned int i = 0, j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] += alpha * X[i];
  }

  return;
}

void mnblas_caxpy(const int N, const void *alpha, const void *X,
                  const int incX, void *Y, const int incY);

void mnblas_zaxpy(const int N, const void *alpha, const void *X,
                  const int incX, void *Y, const int incY);