#include "mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX, 
                 float *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;

  for (; ((i < N) && (j < N)) ; i += incX, j += incY)
    {
      Y [j] = X [i] ;
    }

  return ;
}

// void mncblas_dcopy(const int N, const double *X, const int incX, 
//                  double *Y, const int incY)
// {
// register unsigned int i = 0 ;
//   register unsigned int j = 0 ;

//   for (; ((i < N) && (j < N)) ; i += incX, j += incY)
//     {
//       Y [j] = X [i] ;
//     }

//   return ;
// }

// void mncblas_ccopy(const int N, const void *X, const int incX, 
// 		                    void *Y, const int incY)
// {
//   complexe_float_t *X_tmp = (complexe_float_t *) X;
//   complexe_float_t *Y_tmp = (complexe_float_t *) Y;
//   register unsigned int i = 0 ;
//   register unsigned int j = 0 ;

//   for (; ((i < N) && (j < N)) ; i += incX, j += incY)
//     {
//     Y_tmp[j].real = X_tmp[i].real;
//     Y_tmp[j].imaginary = X_tmp[i].imaginary;
//     }
//   /*X=X_tmp;
//   Y=Y_tmp;*/
//   return ;
// }

// void mncblas_zcopy(const int N, const void *X, const int incX, 
// 		                    void *Y, const int incY)
// {
// complexe_double_t *X_tmp = (complexe_double_t *) X;
//   complexe_double_t *Y_tmp = (complexe_doubley_t *) Y;
//   register unsigned int i = 0 ;
//   register unsigned int j = 0 ;

//   for (; ((i < N) && (j < N)) ; i += incX, j += incY)
//     {
//     Y_tmp[j].real = X_tmp[i].real;
//     Y_tmp[j].imaginary = X_tmp[i].imaginary;
//     }
//   /*X=X_tmp;
//   Y=Y_tmp;*/
//   return ;
// }

