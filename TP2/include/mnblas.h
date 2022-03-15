#define CBLAS_INDEX size_t  /* this may vary between platforms */

typedef enum {MNCblasRowMajor=101, MNCblasColMajor=102} MNCBLAS_LAYOUT;
typedef enum {MNCblasNoTrans=111, MNCblasTrans=112, MNCblasConjTrans=113} MNCBLAS_TRANSPOSE;
typedef enum {MNCblasUpper=121, MNCblasLower=122} MNCBLAS_UPLO;
typedef enum {MNCblasNonUnit=131, MNCblasUnit=132} MNCBLAS_DIAG;
typedef enum {MNCblasLeft=141, MNCblasRight=142} MNCBLAS_SIDE;

/*
 * ===========================================================================
 * Prototypes for level 1 BLAS functions 
 * ===========================================================================
 */


/*
  BLAS copy
*/


void mncblas_scopy(const int N, const float *X, const int incX, 
                 float *Y, const int incY);

void mncblas_dcopy(const int N, const double *X, const int incX, 
                 double *Y, const int incY);


void mncblas_ccopy(const int N, const void *X, const int incX, 
                 void *Y, const int incY);


void mncblas_zcopy(const int N, const void *X, const int incX, 
                 void *Y, const int incY);


/*
  end COPY BLAS
*/

/*
  BLAS SWAP
*/

void mncblas_sswap(const int N, float *X, const int incX, 
                 float *Y, const int incY);

void mncblas_dswap(const int N, double *X, const int incX, 
                 double *Y, const int incY);

void mncblas_cswap(const int N, void *X, const int incX, 
                 void *Y, const int incY);

void mncblas_zswap(const int N, void *X, const int incX, 
                 void *Y, const int incY);

/*
  END SWAP
*/


/*

  BLAS DOT

*/

float  mncblas_sdot(const int N, const float  *X, const int incX,
                  const float  *Y, const int incY);

double mncblas_ddot(const int N, const double *X, const int incX,
                  const double *Y, const int incY);

void   mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu);

void   mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc);

void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu);

void   mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc);

/*
  END BLAS DOT
*/

/*
  BLAS AXPY
*/

/*

void mnblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY);

void mnblas_daxpy(const int N, const double alpha, const double *X,
                 const int incX, double *Y, const int incY);

void mnblas_caxpy(const int N, const void *alpha, const void *X,
                 const int incX, void *Y, const int incY);

void mnblas_zaxpy(const int N, const void *alpha, const void *X,
                 const int incX, void *Y, const int incY);

*/

/*

float  mnblas_sasum(const int N, const float *X, const int incX);

double mnblas_dasum(const int N, const double *X, const int incX);

float  mnblas_scasum(const int N, const void *X, const int incX);

double mnblas_dzasum(const int N, const void *X, const int incX);

*/

/*
CBLAS_INDEX mnblas_isamax(const int N, const float  *X, const int incX);

CBLAS_INDEX mnblas_idamax(const int N, const double *X, const int incX);

CBLAS_INDEX mnblas_icamax(const int N, const void   *X, const int incX);

CBLAS_INDEX mnblas_izamax(const int N, const void   *X, const int incX);
*/

/*
float  mnblas_snrm2(const int N, const float *X, const int incX);

double mnblas_dnrm2(const int N, const double *X, const int incX);

float  mnblas_scnrm2(const int N, const void *X, const int incX);

double mnblas_dznrm2(const int N, const void *X, const int incX);

 */


/*
 * ===========================================================================
 * Prototypes for level 1 BLAS routines
 * ===========================================================================
 */



/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */

/*

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                 const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY);

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const double alpha, const double *A, const int lda,
                 const double *X, const int incX, const double beta,
                 double *Y, const int incY);

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);

*/

/*
 * ===========================================================================
 * Prototypes for level 3 BLAS
 * ===========================================================================
 */

/*

void mncblas_sgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const float alpha, const float *A,
                 const int lda, const float *B, const int ldb,
                 const float beta, float *C, const int ldc);

void mncblas_dgemm(MNCBLAS_LAYOUT layout, CBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc);

void mncblas_cgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc);

void mncblas_zgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc);

*/

