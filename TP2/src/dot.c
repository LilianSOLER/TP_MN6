#include "mnblas.h"
#include <stdio.h>
#include "complexe.h"

/*
float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  register float dot = 0.0 ;
  
  for (; ((i < N) && (j < N)) ; i += incX, j+=incY)
    {
      dot = dot + X [i] * Y [j] ;
    }

  return dot ;
}
*/

float mncblas_sdot(const int N, const float *X, const int incX, 
                 const float *Y, const int incY)
{
 // register unsigned int i = 0 , j = 0 ;
  float dot = 0.0 ;

//#pragma omp parallel for reduction(+:dot)  
  for (unsigned int i=0,j=0 ;(i < N) && (j < N); i += incX, j += incY)
    {
      dot += X [i] * Y [j] ;
    }

  return dot ;
}

double mncblas_ddot(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
{
  //register unsigned int i = 0, j = 0 ;
  double dot = 0.0 ;

  //#pragma omp parallel for reduction(+:dot)
  for (unsigned int i=0,j=0 ;(i < N) && (j < N); i += incX, j += incY)
    {
      dot += X [i] * Y [j] ;
    }

  return dot ;
}

void   mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  /* a completer */
  
  return ;
}

void   mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  //register unsigned int i = 0, j = 0 ;
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  complexe_float_t *Y_tmp = (complexe_float_t *)Y;
  complexe_float_t *dotc_tmp = (complexe_float_t *)dotc;

  //#pragma omp parallel for private(tmp) reduction(+:dotreal) reduction(+:dotimaginary) 
  for (unsigned int i=0,j=0 ; (i < N) && (j < N); i += incX, j += incY)
    {
      dotc_tmp[j].real = X_tmp[i].real * Y_tmp[j].real - X_tmp[i].imaginary * Y_tmp[j].imaginary ;
      dotc_tmp[j].imaginary = X_tmp[i].real * Y_tmp[j].imaginary + X_tmp[i].imaginary * Y_tmp[j].real ;
    }
  dotc = (void *)dotc_tmp;
  return ;
}

void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
  /* a completer */
  
  return ;
}
  
void   mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
  /* a completer */
  
  return ;
}




