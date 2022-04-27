#include "mnblas.h"
#include "complexe.h"

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,const MNCBLAS_TRANSPOSE TransA, const int M, const int N,const float alpha, const float *A, const int lda,const float *X, const int incX, const float beta,float *Y, const int incY)
{
   register float tmp;
   #pragma omp parallel for
   for (unsigned int i = 0; i < M; i += incX) {
      tmp = beta*Y[i];
      for (unsigned int j = 0; j < N; j += incY) {
         tmp += alpha*A[i*N+j]*X[j]; 
      }
      Y[i] = tmp;
   }

}

void mncblas_dgemv(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda,  const double *X, const int incX, const double beta,  double *Y, const int incY)
{
   register double tmp;
#pragma omp parallel for
   for (unsigned int i = 0; i < M; i += incX) {
      tmp = beta*Y[i];
      for (unsigned int j = 0; j < N; j += incY) {
         tmp += alpha*A[i*N+j]*X[j]; 
      }
      Y[i] = tmp;
   }
}

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                   MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const void *alpha, const void *A, const int lda,
                   const void *X, const int incX, const void *beta,
                   void *Y, const int incY)
{
   register complexe_float_t tmp ;
#pragma omp parallel for
   for (unsigned int i = 0; i < N; i += incX) {
      tmp = mult_complexe_float(*(complexe_float_t*)beta, ((complexe_float_t*)Y)[i]);
      for (unsigned int j = 0; j < N; j += incY) {
         tmp = add_complexe_float(tmp, mult_complexe_float(mult_complexe_float(*(complexe_float_t*)alpha, ((complexe_float_t*)A)[i*N+j]),((complexe_float_t*)X)[j]));
      }
      ((complexe_float_t*)Y)[i] = tmp;
   }
}

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                   MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const void *alpha, const void *A, const int lda,
                   const void *X, const int incX, const void *beta,
                   void *Y, const int incY)
{
   register complexe_double_t tmp;
    #pragma omp parallel for
    for (unsigned int i = 0; i < N; i += incX) {
      tmp = mult_complexe_double(*(complexe_double_t*)beta, ((complexe_double_t*)Y)[i]);
      for (unsigned int j = 0; j < N; j += incY) {
         tmp = add_complexe_double(tmp, mult_complexe_double(mult_complexe_double(*(complexe_double_t*)alpha, ((complexe_double_t*)A)[i*N+j]),((complexe_double_t*)X)[j]));
      }
      ((complexe_double_t*)Y)[i] = tmp;
   }
}