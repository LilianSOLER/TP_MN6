#include "mnblas.h"
#include <stdio.h>
#include "complexe.h"
#include "math.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

void mncblas_sgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const float alpha, const float *A,
                 const int lda, const float *B, const int ldb,
                 const float beta, float *C, const int ldc)
{
   register float tmp = 0.0;
#pragma omp parallel for
   for (unsigned int i = 0; i < M; i++) {
      for (unsigned int j = 0; j < N; j++) {
         tmp = 0.0;
         for (unsigned int k = 0; k < K; k++) {
            tmp += alpha*A[i*K+k]*B[k*N+j]; 
         }
         tmp += beta*C[i*N+j];
         C[i*N+j] = tmp;
      }
   }
}

void mncblas_dgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc)
{
   register double tmp = 0.0;
#pragma omp parallel for
   for (unsigned int i = 0; i < M; i++) {
      for (unsigned int j = 0; j < N; j++) {
         tmp = 0.0;
         for (unsigned int k = 0; k < K; k++) {
            tmp += alpha*A[i*K+k]*B[k*N+j]; 
         }
         tmp += beta*C[i*N+j];
         C[i*N+j] = tmp;
      }
   }
}

void mncblas_cgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc)
{
   register complexe_float_t tmp;
#pragma omp parallel for
   for (unsigned int i = 0; i < M; i++) {
      for (unsigned int j = 0; j < N; j++) {
         tmp.real = 0.0;
         tmp.imaginary = 0.0;
         for (unsigned int k = 0; k < K; k++) {
            tmp = add_complexe_float(tmp, mult_complexe_float(mult_complexe_float(*(complexe_float_t*)alpha, ((complexe_float_t*)A)[i*K+k]), ((complexe_float_t*)B)[k*N+j]));
         }
         tmp = add_complexe_float(tmp, mult_complexe_float(*(complexe_float_t*)beta, ((complexe_float_t*)C)[i*N+j]));
         ((complexe_float_t*)C)[i*N+j] = tmp;
      }
   }
}

void mncblas_zgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc)
{
   register complexe_double_t tmp;
#pragma omp parallel for
   for (unsigned int i = 0; i < M; i++) {
      for (unsigned int j = 0; j < N; j++) {
         tmp.real = 0.0;
         tmp.imaginary = 0.0;
         for (unsigned int k = 0; k < K; k++) {
            tmp = add_complexe_double(tmp, mult_complexe_double(mult_complexe_double(*(complexe_double_t*)alpha, ((complexe_double_t*)A)[i*K+k]), ((complexe_double_t*)B)[k*N+j])); 
         }
         tmp = add_complexe_double(tmp, mult_complexe_double(*(complexe_double_t*)beta, ((complexe_double_t*)C)[i*N+j]));
         ((complexe_double_t*)C)[i*N+j] = tmp;
      }
   }
}