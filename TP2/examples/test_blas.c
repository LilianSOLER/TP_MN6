#include <stdio.h>
#include <string.h>
#include <math.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE 3
// #define VECSIZE 10

#define NB_FOIS 10

typedef float vfloat[VECSIZE];
typedef double vdouble[VECSIZE];
typedef complexe_double_t vcomp_double[VECSIZE];
typedef complexe_float_t vcomp_float[VECSIZE];


vfloat vec1, vec2;
vdouble vec1d, vec2d;
vcomp_double vec1cd, vec2cd;
vcomp_float vec1cf, vec2cf;
complexe_float_t tmpc = {2.0, 0.0};
complexe_double_t tmpz = {2.0, 0.0};
float alphaf = 2.0;
float betaf = 2.0;
int M = 3;
int N = 4;
int K = 4;
float alphad = 2.0;
float betad = 2.0;



void vector_init(vfloat V, float x)
{
  register unsigned int i;
  
  for (i = 0; i < VECSIZE; i++)
    V[i] = x;

  return;
}

void vector_init_double_random(vdouble V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    V[i] = rand() % 100;

  return;
}
void vector_init_comp_float_random(vcomp_float V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
  {
    V[i].real = rand() % 100;
    V[i].imaginary = rand() % 100;
  }

  return;
}
void vector_init_comp_double_random(vcomp_double V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
  {
    V[i].real = rand() % 100;
    V[i].imaginary = rand() % 100;
  }

  return;
}

void vector_print(vfloat V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%f ", V[i]);
  printf("\n");

  return;
}

void vector_print_double(vdouble V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%lf ", V[i]);
  printf("\n");

  return;
}
void vector_print_comp_float(vcomp_float V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%lf + %lf i ", V[i].real, V[i].imaginary);

  printf("\n");

  return;
}
void vector_print_comp_double(vcomp_double V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%lf + %lf i ", V[i].real, V[i].imaginary);

  printf("\n");

  return;
}

void test(int type, int fonction)
{
  float res_float = 0;
  double res_double = 0;
  complexe_float_t res_comp_float;
  complexe_float_t res_comp_float2;
  complexe_double_t res_comp_double;
  complexe_double_t res_comp_double2;
  printf("Test\n");
  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    switch (type)
    {
    case 1:
      vector_init(vec1, 1.0);
      vector_init(vec2, 2.0);
      vector_print(vec1);
      vector_print(vec2);
      switch (fonction)
      {
      case 1:
        mncblas_sswap(VECSIZE, vec1, 1, vec2, 1);
        break;
      case 2:
        mncblas_scopy(VECSIZE, vec1, 1, vec2, 1);
        break;
      case 3:
        res_float = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
        printf("%f\n", res_float);
        break;
      case 4:
        mnblas_saxpy(VECSIZE, 2.0, vec1, 1, vec2, 1);
        break;
      case 5:
        res_float = mnblas_sasum(VECSIZE, vec1, 1);
        printf("%f\n", res_float);
        break;
      case 8:
        res_float = mnblas_snrm2(VECSIZE, vec1, 1);
        printf("%f\n", res_float);
        break;
      }
      vector_print(vec1);
      vector_print(vec2);
      break;
    case 2:
      vector_init_double_random(vec1d);
      vector_init_double_random(vec2d);
      vector_print_double(vec1d);
      vector_print_double(vec2d);
      switch (fonction)
      {
      case 1:
        mncblas_dswap(VECSIZE, vec1d, 1, vec2d, 1);
        break;
      case 2:
        mncblas_dcopy(VECSIZE, vec1d, 1, vec2d, 1);
        break;
      case 3:
        res_double = mncblas_ddot(VECSIZE, vec1d, 1, vec2d, 1);
        printf("%lf\n", res_double);
        break;
      case 4:
        mnblas_daxpy(VECSIZE, 2.0, vec1d, 1, vec2d, 1);
        break;
      case 5:
        res_double = mnblas_dasum(VECSIZE, vec1d, 1);
        printf("%lf\n", res_double);
        break;
      case 8:
        res_double = mnblas_dnrm2(VECSIZE, vec1d, 1);
        printf("%lf\n", res_double);
        break;
      }
      vector_print_double(vec1d);
      vector_print_double(vec2d);
      break;
    case 3:
      vector_init_comp_float_random(vec1cf);
      vector_init_comp_float_random(vec2cf);
      vector_print_comp_float(vec1cf);
      vector_print_comp_float(vec2cf);
      switch (fonction)
      {
      case 1:
        mncblas_cswap(VECSIZE, vec1cf, 1, vec2cf, 1);
        break;
      case 2:
        mncblas_ccopy(VECSIZE, vec1cf, 1, vec2cf, 1);
        break;
      case 3:
        mncblas_cdotc_sub(VECSIZE, vec1cf, 1, vec2cf, 1, &res_comp_float);
        printf("%lf + %lf i\n", res_comp_float.real, res_comp_float.imaginary);
        break;
        case 4:
        mnblas_caxpy(VECSIZE, &tmpc, vec1cf, 1, vec2cf, 1);
        break;
      case 5:
        res_float = mnblas_scasum(VECSIZE, vec1cf, 1);
        printf("%f\n", res_float);
        break;
      case 8:
        res_float = mnblas_scnrm2(VECSIZE, vec1cf, 1);
        printf("%f\n", res_float);
        break;
      }
      vector_print_comp_float(vec1cf);
      vector_print_comp_float(vec2cf);
      break;
    case 4:
      vector_init_comp_double_random(vec1cd);
      vector_init_comp_double_random(vec2cd);
      vector_print_comp_double(vec1cd);
      vector_print_comp_double(vec2cd);
      switch (fonction)
      {
      case 1:
        mncblas_zswap(VECSIZE, vec1cd, 1, vec2cd, 1);
        break;
      case 2:
        mncblas_zcopy(VECSIZE, vec1cd, 1, vec2cd, 1);
        break;
      case 3:
        mncblas_zdotc_sub(VECSIZE, vec1cd, 1, vec2cd, 1, &res_comp_double);
        printf("%lf + %lf i\n", res_comp_double.real, res_comp_double.imaginary);
        mncblas_zdotu_sub(VECSIZE, vec1cd, 1, vec2cd, 1, &res_comp_double2);
        printf("%lf + %lf i\n", res_comp_double2.real, res_comp_double2.imaginary);
        break;
        case 4:
        mnblas_zaxpy(VECSIZE, &tmpz, vec1cd, 1, vec2cd, 1);
        break;
      case 5:
        res_double = mnblas_dzasum(VECSIZE, vec1cd, 1);
        printf("%lf\n", res_double);
        break;
      case 8:
        res_double = mnblas_dznrm2(VECSIZE, vec1cd, 1);
        printf("%lf\n", res_double);
        break;
      }
      vector_print_comp_double(vec1cd);
      vector_print_comp_double(vec2cd);
      break;
    }
    printf("\n");
  }
  printf("==========================================================\n");
}

void perf(int type, int fonction)
{
  float *fA = malloc(sizeof(float *) * 12);
  float *fx = malloc(sizeof(float *) * 4);
  float *fy = malloc(sizeof(float *) * 3);
 

   double *dA = malloc(sizeof(double *) * 12);
    double *dx = malloc(sizeof(double *) * 4);
    double *dy = malloc(sizeof(double *) * 3);
   
  float enter = 1.0;

    for (int i = 0; i < 12; i++)
    {
        fA[i] = enter;
        enter++;
    }

    enter = 1.0;

    for (int i = 0; i < 4; i++)
    {
        fx[i] = enter;
        enter++;
    }

    enter = 1.0;

    for (int i = 0; i < 3; i++)
    {
        fy[i] = enter;
        enter++;
    }
    double enterd = 1.0;

    for (int i = 0; i < 12; i++)
    {
        dA[i] = enterd;
        enterd++;
    }

    enterd = 1.0;

    for (int i = 0; i < 4; i++)
    {
        dx[i] = enterd;
        enterd++;
    }

    enterd = 1.0;

    for (int i = 0; i < 3; i++)
    {
        dy[i] = enterd;
        enterd++;
    }

    complexe_float_t *cfA = malloc(sizeof(complexe_float_t *) * 12);
    complexe_float_t *cfx = malloc(sizeof(complexe_float_t *) * 4);
    complexe_float_t *cfy = malloc(sizeof(complexe_float_t *) * 3);

    complexe_double_t *cdA = malloc(sizeof(double *) * 24);
    complexe_double_t *cdx = malloc(sizeof(double *) * 8);
    complexe_double_t *cdy = malloc(sizeof(double *) * 6);


    complexe_float_t *alphacf = malloc(sizeof(complexe_float_t *));
    complexe_float_t *betacf = malloc(sizeof(complexe_float_t *));
    complexe_double_t *alphacd = malloc(sizeof(double *) * 2);
    complexe_double_t *betacd = malloc(sizeof(double *) * 2);
    complexe_float_t entercf = {1.0, 1.0};

    for (int i = 0; i < 12; i++)
    {
        cfA[i].real = entercf.real;
        cfA[i].imaginary = entercf.imaginary;
        entercf.real++;
        entercf.imaginary++;
    }

    entercf.real = 1.0;
    entercf.imaginary = 1.0;

    for (int i = 0; i < 4; i++)
    {
        cfx[i].real = entercf.real;
        cfx[i].imaginary = entercf.imaginary;
        entercf.real++;
        entercf.imaginary++;
    }

    entercf.real = 1.0;
    entercf.imaginary = 1.0;

    for (int i = 0; i < 3; i++)
    {
        cfy[i].real = entercf.real;
        cfy[i].imaginary = entercf.imaginary;
        entercf.real++;
        entercf.imaginary++;
    }

    alphacf[0].real = 2.0;
    alphacf[0].imaginary = 2.0;
    betacf[0].real = 2.0;
    betacf[0].imaginary = 2.0;
    complexe_double_t entercd = {1.0, 1.0};

    for (int i = 0; i < 12; i++)
    {
        cdA[i].real = entercd.real;
        cdA[i].imaginary = entercd.imaginary;
        entercd.real++;
        entercd.imaginary++;
    }

    entercd.real = 1.0;
    entercd.imaginary = 1.0;

    for (int i = 0; i < 4; i++)
    {
        cdx[i].real = entercd.real;
        cdx[i].imaginary = entercd.imaginary;
        entercd.real++;
        entercd.imaginary++;
    }

    entercd.real = 1.0;
    entercd.imaginary = 1.0;

    for (int i = 0; i < 3; i++)
    {
        cdy[i].real = entercd.real;
        cdy[i].imaginary = entercd.imaginary;
        entercd.real++;
        entercd.imaginary++;
    }

    alphacd[0].real = 2.0;
    alphacd[0].imaginary = 2.0;
    betacd[0].real = 2.0;
    betacd[0].imaginary = 2.0;
  unsigned long long int start_tsc, end_tsc;
  complexe_float_t res_comp_float;
  complexe_double_t res_comp_double;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    switch (type)
    {
    case 1:
      vector_init(vec1, 1.0);
      vector_init(vec2, 2.0);
      break;
    case 2:
      vector_init_double_random(vec1d);
      vector_init_double_random(vec2d);
      break;
    case 3:
      vector_init_comp_float_random(vec1cf);
      vector_init_comp_float_random(vec2cf);
      break;
    case 4:
      vector_init_comp_double_random(vec1cd);
      vector_init_comp_double_random(vec2cd);
      break;
    }

    switch (type)
    {
    case 1:
      switch (fonction)
      {
      case 1:
        start_tsc = _rdtsc();
        mncblas_sswap(VECSIZE, vec1, 1, vec2, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_sswap", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 2:
        start_tsc = _rdtsc();
        mncblas_scopy(VECSIZE, vec1, 1, vec2, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_scopy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 3:
        start_tsc = _rdtsc();
        mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_sdot", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 4:
        start_tsc = _rdtsc();
        mnblas_saxpy(VECSIZE, 2.0, vec1, 1, vec2, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_saxpy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 5:
        start_tsc = _rdtsc();
        mnblas_sasum(VECSIZE, vec1, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_sasum", VECSIZE, end_tsc - start_tsc);
        break;
      case 6:
        start_tsc = _rdtsc();
        mnblas_isamin(VECSIZE, vec1, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_isamin", VECSIZE, end_tsc - start_tsc);
        break;
      case 7:
        start_tsc = _rdtsc();
        mnblas_isamax(VECSIZE, vec1, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_isamax", VECSIZE, end_tsc - start_tsc);
        break;
      case 8:
        start_tsc = _rdtsc();
        mnblas_snrm2(VECSIZE, vec1, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_snrm2", VECSIZE, end_tsc - start_tsc);
        break;
      case 9:
        start_tsc = _rdtsc();
        mncblas_sgemv(101,111,M,N,alphaf,fA,0,fx,1,betaf,fy, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_sgemv", VECSIZE, end_tsc - start_tsc);
        break;
      case 10:
        start_tsc = _rdtsc();
        mncblas_sgemm(101, 111, 111, M, N, K, alphaf, fA, 0, fx, 0, betaf, fy, 0);        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_sgemm", VECSIZE, end_tsc - start_tsc);
        break;
      default:
        printf("Error\n");
        break;
      }
      break;
    case 2:
      switch (fonction)
      {
      case 1:
        start_tsc = _rdtsc();
        mncblas_dswap(VECSIZE, vec1d, 1, vec2d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_dswap", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 2:
        start_tsc = _rdtsc();
        mncblas_dcopy(VECSIZE, vec1d, 1, vec2d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_dcopy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 3:
        start_tsc = _rdtsc();
        mncblas_ddot(VECSIZE, vec1d, 1, vec2d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_ddot", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 4:
        start_tsc = _rdtsc();
        mnblas_daxpy(VECSIZE, 2.0, vec1d, 1, vec2d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_daxpy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 5:
        start_tsc = _rdtsc();
        mnblas_dasum(VECSIZE, vec1d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_dasum", VECSIZE, end_tsc - start_tsc);
        break;
      case 6:
        start_tsc = _rdtsc();
        mnblas_idamin(VECSIZE, vec1d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_idamin", VECSIZE, end_tsc - start_tsc);
        break;
      case 7:
        start_tsc = _rdtsc();
        mnblas_idamax(VECSIZE, vec1d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_idamax", VECSIZE, end_tsc - start_tsc);
        break;
      case 8:
        start_tsc = _rdtsc();
        mnblas_dnrm2(VECSIZE, vec1d, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_dnrm2", VECSIZE, end_tsc - start_tsc);
        break;
      case 9:
        start_tsc = _rdtsc();
        mncblas_dgemv(101, 111, M, N, alphad, dA, 0, dx, 1, betad, dy, 1);    
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_sgemv", VECSIZE, end_tsc - start_tsc);
        break;
      case 10:
        start_tsc = _rdtsc();
        mncblas_dgemm(101, 111, 111, M, N, K, alphad, dA, 0, dx, 0, betad, dy, 0);        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_dgemm", VECSIZE, end_tsc - start_tsc);
        break;
      default:
        printf("Error\n");
        break;
      }
      break;
    case 3:
      switch (fonction)
      {
      case 1:
        start_tsc = _rdtsc();
        mncblas_cswap(VECSIZE, vec1cf, 1, vec2cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_cswap", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 2:
        start_tsc = _rdtsc();
        mncblas_ccopy(VECSIZE, vec1cf, 1, vec2cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_ccopy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 3:
        start_tsc = _rdtsc();
        mncblas_cdotc_sub(VECSIZE, vec1cf, 1, vec2cf, 1, &res_comp_float);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_cdotc", 2 * VECSIZE, end_tsc - start_tsc);
        printf("puis mncblas_cdotu_sub");
        start_tsc = _rdtsc();
        mncblas_cdotu_sub(VECSIZE, vec1cf, 1, vec2cf, 1, &res_comp_float);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_cdotu", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 4:
        start_tsc = _rdtsc();
        mnblas_caxpy(VECSIZE, &tmpc, vec1cf, 1, vec2cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_caxpy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 5:
        start_tsc = _rdtsc();
        mnblas_scasum(VECSIZE, vec1cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_scasum", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 6:
        start_tsc = _rdtsc();
        mnblas_icamin(VECSIZE, vec1cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_icamin", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 7:
        start_tsc = _rdtsc();
        mnblas_icamax(VECSIZE, vec1cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_icamax", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 8:
        start_tsc = _rdtsc();
        mnblas_scnrm2(VECSIZE, vec1cf, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_scnrm2", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 9:
        start_tsc = _rdtsc();
        mncblas_cgemv(101, 111, M, N, alphacf, cfA, 0, cfx, 1, betacf, cfy, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_cgemv", VECSIZE, end_tsc - start_tsc);
        break;
       case 10:
        start_tsc = _rdtsc();
        mncblas_cgemm(101, 111, 111, M, N, K, alphacf, cfA, 0, cfx, 0, betacf, cfy, 0);        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_cgemm", VECSIZE, end_tsc - start_tsc);
        break;
      default:
        printf("Error\n");
        break;
      }
      break;
    case 4:
      switch (fonction)
      {
      case 1:
        start_tsc = _rdtsc();
        mncblas_zswap(VECSIZE, vec1cd, 1, vec2cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zswap", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 2:
        start_tsc = _rdtsc();
        mncblas_zcopy(VECSIZE, vec1cd, 1, vec2cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zcopy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 3:
        start_tsc = _rdtsc();
        mncblas_zdotc_sub(VECSIZE, vec1cd, 1, vec2cd, 1, &res_comp_double);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zdotc", 2 * VECSIZE, end_tsc - start_tsc);
        printf("puis mncblas_zdotu_sub");
        start_tsc = _rdtsc();
        mncblas_zdotu_sub(VECSIZE, vec1cd, 1, vec2cd, 1, &res_comp_double);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zdotu", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 4:
        start_tsc = _rdtsc();
        mnblas_zaxpy(VECSIZE, &tmpz, vec1cd, 1, vec2cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_zaxpy", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 5:
        start_tsc = _rdtsc();
        mnblas_dzasum(VECSIZE, vec1cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_dzasum", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 6:
        start_tsc = _rdtsc();
        mnblas_izamin(VECSIZE, vec1cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_izamin", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 7:
        start_tsc = _rdtsc();
        mnblas_izamax(VECSIZE, vec1cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_izamax", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 8:
        start_tsc = _rdtsc();
        mnblas_dznrm2(VECSIZE, vec1cd, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mnblas_dznrm2", 2 * VECSIZE, end_tsc - start_tsc);
        break;
      case 9:
        start_tsc = _rdtsc();
        mncblas_zgemv(101, 111, M, N, alphacd, cdA, 0, cdx, 1, betacd, cdy, 1);
        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zgemv", VECSIZE, end_tsc - start_tsc);
        break;
      case 10:
        start_tsc = _rdtsc();
        mncblas_zgemm(101, 111, 111, M, N, K, alphacd, cdA, 0, cdx, 0, betacd, cdy, 0);        end_tsc = _rdtsc();
        calcul_flop_tsc("mncblas_zgemv", VECSIZE, end_tsc - start_tsc);
        break;
      default:
        printf("Error\n");
        break;
      }
      break;
    }
  }
  printf("==========================================================\n");
}

void print_usage()
{
  printf("Usage : ./test_blas <test/perf> <type> <fonction>\n");
  printf("type : 1 -> float\n");
  printf("       2 -> double\n");
  printf("       3 -> comp_float\n");
  printf("       4 -> comp_double\n");
  printf("fonction : 1 -> swap\n");
  printf("           2 -> copy\n");
  printf("           3 -> dot\n");
  printf("           4 -> axpy\n");
  printf("           5 -> asum\n");
  printf("           6 -> iamin\n");
  printf("           7 -> iamax\n");
  printf("           8 -> nrm2\n");
  printf("           9 -> gemv\n");
  printf("           10 -> gemm\n");


  exit(1);
}

void launch_things(int *type, int *fonction, int argc, char *argv[])
{
  if (argc != 4)
  {
    print_usage();
  }
  else
  {

    if (strcmp(argv[2], "float") == 0)
    {
      *type = 1;
    }
    else if (strcmp(argv[2], "double") == 0)
    {
      *type = 2;
    }
    else if (strcmp(argv[2], "comp_float") == 0)
    {
      *type = 3;
    }
    else if (strcmp(argv[2], "comp_double") == 0)
    {
      *type = 4;
    }
    else
    {
      print_usage();
    }

    if (strcmp(argv[3], "swap") == 0)
    {
      *fonction = 1;
    }
    else if (strcmp(argv[3], "copy") == 0)
    {
      *fonction = 2;
    }
    else if (strcmp(argv[3], "dot") == 0)
    {
      *fonction = 3;
    }
    else if (strcmp(argv[3], "axpy") == 0)
    {
      *fonction = 4;
    }
    else if (strcmp(argv[3], "asum") == 0)
    {
      *fonction = 5;
    }
    else if (strcmp(argv[3], "iamin") == 0)
    {
      *fonction = 6;
    }
    else if (strcmp(argv[3], "iamax") == 0)
    {
      *fonction = 7;
    }
    else if (strcmp(argv[3], "nrm2") == 0)
    {
      *fonction = 8;
    }
    else if (strcmp(argv[3], "gemv") == 0)
    {
      *fonction = 9;
    }
    else if (strcmp(argv[3], "gemm") == 0)
    {
      *fonction = 10;
    }
    else
    {
      print_usage();
    }

    if (*type != 0 && *fonction != 0)
    {
      if (strcmp(argv[1], "test") == 0)
        test(*type, *fonction);
      else if (strcmp(argv[1], "perf") == 0)
        perf(*type, *fonction);
      else
        print_usage();
    }
  }
}

int main(int argc, char *argv[])
{
  int type = 0;     // 1: float, 2: double, 3: complex float, 4: complex double
  int fonction = 0; // 1: swap, 2: copy, 3: dot 4:axpy 5:asum 6:iamin 7:iamax 8:nrm2 9:gemv

  launch_things(&type, &fonction, argc, argv);
}