#include "mnblas.h"
#include <stdio.h>
#include "complexe.h"
#include <math.h>

float mncblas_sdot(const int N, const float *X, const int incX,
                   const float *Y, const int incY)
{
  // register unsigned int i = 0 , j = 0 ;
  float dot = 0.0;

  /*for (unsigned int i=0,j=0 ;(i < N) && (j < N); i += incX, j += incY)
    {
      dot += X [i] * Y [j] ;
    } //on a changer pour open MP toutes les fonctions
*/
  const int max = (incX < incY) ? ceil((float)N / (float)incY) : ceil((float)N / (float)incX);
  const int diff = (incY - incX + 1);
  //#pragma omp parallel for reduction(+:dot)
  for (register unsigned int i = 0; i < max; i++)
    dot += X[i] * Y[diff * i];
  return dot;
}

double mncblas_ddot(const int N, const double *X, const int incX,
                    const double *Y, const int incY)
{
  // register unsigned int i = 0, j = 0 ;
  double dot = 0.0;

  /*  for (unsigned int i=0,j=0 ;(i < N) && (j < N); i += incX, j += incY)
      {
        dot += X [i] * Y [j] ;
      }
  */
  const int max = (incX < incY) ? ceil((float)N / (float)incY) : ceil((float)N / (float)incX);
  const int diff = (incY - incX + 1);
  //#pragma omp parallel for reduction(+:dot)
  for (register unsigned int i = 0; i < max; i++)
    dot += X[i] * Y[diff * i];
  return dot;
}

void mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  register unsigned int i = 0, j = 0;
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  complexe_float_t *Y_tmp = (complexe_float_t *)Y;
  complexe_float_t *dotu_tmp = (complexe_float_t *)dotu;

  for (i = 0, j = 0; (i < N) && (j < N); i += incX, j += incY)
  {
    dotu_tmp[0].real += X_tmp[i].real * Y_tmp[j].real - X_tmp[i].imaginary * Y_tmp[j].imaginary;
    dotu_tmp[0].imaginary += X_tmp[i].real * Y_tmp[j].imaginary + X_tmp[i].imaginary * Y_tmp[j].real;
  }

  dotu = (void *)dotu_tmp;
}

void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  // register unsigned int i = 0, j = 0 ;
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  complexe_float_t *Y_tmp = (complexe_float_t *)Y;
  complexe_float_t *dotc_tmp = (complexe_float_t *)dotc;

  //#pragma omp parallel for private(tmp)
  /*for (unsigned int i=0,j=0 ; (i < N) && (j < N); i += incX, j += incY)
    {
      dotc_tmp[j].real = X_tmp[i].real * Y_tmp[j].real - X_tmp[i].imaginary * Y_tmp[j].imaginary ;
      dotc_tmp[j].imaginary = X_tmp[i].real * Y_tmp[j].imaginary + X_tmp[i].imaginary * Y_tmp[j].real ;
    }
  dotc = (void *)dotc_tmp;
  */
  const int max = (incX < incY) ? ceil((float)N / (float)incY) : ceil((float)N / (float)incX);
  const int diff = (incY - incX + 1);
  //#pragma omp parallel for private(Y_tmp)
  for (register unsigned int i = 0; i < max; i++)
  {
    dotc_tmp[diff * i].real = X_tmp[i].real * Y_tmp[diff * i].real - X_tmp[i].imaginary * Y_tmp[diff * i].imaginary;
    dotc_tmp[diff * i].imaginary = X_tmp[i].real * Y_tmp[diff * i].imaginary + X_tmp[i].imaginary * Y_tmp[diff * i].real;
  }
  dotc = (void *)dotc_tmp;
}

void mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  /* a completer */
  register unsigned int i = 0, j = 0;
  complexe_double_t *X_tmp = (complexe_double_t *)X;
  complexe_double_t *Y_tmp = (complexe_double_t *)Y;
  complexe_double_t *dotu_tmp = (complexe_double_t *)dotu;

  for (i = 0, j = 0; (i < N) && (j < N); i += incX, j += incY)
  {
    dotu_tmp[0].real += X_tmp[i].real * Y_tmp[j].real - X_tmp[i].imaginary * Y_tmp[j].imaginary;
    dotu_tmp[0].imaginary += X_tmp[i].real * Y_tmp[j].imaginary + X_tmp[i].imaginary * Y_tmp[j].real;
  }

  dotu = (void *)dotu_tmp;
}

void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  /* a completer */
  register unsigned int i = 0, j = 0;
  complexe_double_t *X_tmp = (complexe_double_t *)X;
  complexe_double_t *Y_tmp = (complexe_double_t *)Y;
  complexe_double_t *dotc_tmp = (complexe_double_t *)dotc;

  for (i = 0, j = 0; (i < N) && (j < N); i += incX, j += incY)
  {
    dotc_tmp[0].real += X_tmp[i].real * Y_tmp[j].real + X_tmp[i].imaginary * Y_tmp[j].imaginary;
    dotc_tmp[0].imaginary += -(X_tmp[i].real * Y_tmp[j].imaginary) + X_tmp[i].imaginary * Y_tmp[j].real;
  }

  dotc = (void *)dotc_tmp;
}
