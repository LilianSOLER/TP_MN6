#include "mnblas.h"
#include "complexe.h"
#include <math.h>

void mncblas_scopy(const int N, const float *X, const int incX,
                   float *Y, const int incY)
{
  

  /*for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] = X[i];
  }*/ //on a changer pour open MP toutes les fonctions
  const int max = (incX < incY) ? ceil((float)N/(float)incY) : ceil((float)N/(float)incX);
  const int diff = (incY - incX + 1);
#pragma omp parallel for
  for (register unsigned int i = 0; i < max ; i++){
    Y [diff*i] = X [i];}

  return;
}

void mncblas_dcopy(const int N, const double *X, const int incX,
                   double *Y, const int incY)
{
  
  /*for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] = X[i];
  }*/
  const int max = (incX < incY) ? ceil((float)N/(float)incY) : ceil((float)N/(float)incX);
  const int diff = (incY - incX + 1);
#pragma omp parallel for
  for (register unsigned int i = 0; i < max ; i++){
    Y [diff*i] = X [i] ;}
}



void mncblas_ccopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  complexe_float_t *Y_tmp = (complexe_float_t *)Y;
  
/*  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y_tmp[j].real = X_tmp[i].real;
    Y_tmp[j].imaginary = X_tmp[i].imaginary;
  }*/
  /*X=X_tmp;
  Y=Y_tmp;*/

const int max = (incX < incY) ? ceil((float)N/(float)incY) : ceil((float)N/(float)incX);
  const int diff = (incY - incX + 1);
#pragma omp parallel for
  for (register unsigned int i = 0; i < max ; i++){
  Y_tmp[diff*i].real = X_tmp[i].real;
    Y_tmp[diff*i].imaginary = X_tmp[i].imaginary;
    }
    }

void mncblas_zcopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
  complexe_double_t *X_tmp = (complexe_double_t *)X;
  complexe_double_t *Y_tmp = (complexe_double_t *)Y;

/*  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y_tmp[j].real = X_tmp[i].real;
    Y_tmp[j].imaginary = X_tmp[i].imaginary;
  }
  */
  /*X=X_tmp;
  Y=Y_tmp;*/
const int max = (incX < incY) ? ceil((float)N/(float)incY) : ceil((float)N/(float)incX);
  const int diff = (incY - incX + 1);
#pragma omp parallel for
  for (register unsigned int i = 0; i < max ; i++){
    Y_tmp[diff*i].real = X_tmp[i].real;
    Y_tmp[diff*i].imaginary = X_tmp[i].imaginary;
    }
}
