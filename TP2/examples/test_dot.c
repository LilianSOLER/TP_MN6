#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE 10
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
    V[i] = rand() / (double)RAND_MAX;

  return;
}
void vector_init_comp_float_random(vcomp_float V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
  {
    V[i].real = rand() / (float)RAND_MAX;
    V[i].imaginary = rand() / (float)RAND_MAX;
  }

  return;
}
void vector_init_comp_double_random(vcomp_double V)
{
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
  {
    V[i].real = rand() / (double)RAND_MAX;
    V[i].imaginary = rand() / (double)RAND_MAX;
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
      }
      vector_print_double(vec1d);
      vector_print_double(vec2d);
      break;
    case 3:
      vector_init_comp_float_random(vec1cf);
      vector_init_comp_float_random(vec2cf);
      switch (fonction)
      {
      case 1:
        mncblas_cswap(VECSIZE, vec1cf, 1, vec2cf, 1);
        break;
      case 2:
        // mncblas_ccopy(VECSIZE, vec1cf, 1, vec2cf, 1);
        break;
      }
      vector_print_comp_float(vec1cf);
      vector_print_comp_float(vec2cf);
      break;
    case 4:
      vector_init_comp_double_random(vec1cd);
      vector_init_comp_double_random(vec2cd);
      switch (fonction)
      {
      case 1:
        mncblas_zswap(VECSIZE, vec1cd, 1, vec2cd, 1);
        break;
      case 2:
        // mncblas_zcopy(VECSIZE, vec1cd, 1, vec2cd, 1);
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
  unsigned long long int start_tsc, end_tsc;

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
        // mncblas_ccopy(VECSIZE, vec1cf, 1, vec2cf, 1);
        end_tsc = _rdtsc();
        // calcul_flop_tsc("mncblas_ccopy", 2 * VECSIZE,  end_tsc - start_tsc);
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
        // mncblas_zcopy(VECSIZE, vec1cd, 1, vec2cd, 1);
        end_tsc = _rdtsc();
        // calcul_flop_tsc("mncblas_zcopy", 2 * VECSIZE,  end_tsc - start_tsc);
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

int main(int argc, char **argv)
{
  perf(2, 2);
}