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
void vector_print_comp_float(vcomp_float V){
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%lf + %lf i ", V[i].real, V[i].imaginary);

  printf("\n");

  return;
}
void vector_print_comp_double(vcomp_double V){
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%lf + %lf i ", V[i].real, V[i].imaginary);

  printf("\n");

  return;
}

void basic_main()
{
  struct timeval start, end;
  unsigned long long int start_tsc, end_tsc;

  float res;
  int i;

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++)
  {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    start_tsc = _rdtsc();
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    end_tsc = _rdtsc();

    calcul_flop_tsc("sdot nano ", 2 * VECSIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++)
  {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    TOP_MICRO(start);
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    TOP_MICRO(end);

    calcul_flop_micro("sdot micro", 2 * VECSIZE, tdiff_micro(&start, &end));
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++)
  {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    start_tsc = _rdtsc();
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    end_tsc = _rdtsc();

    calcul_flop_nano("sdot nano ", 2 * VECSIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");
}

void perf_float(){
  unsigned long long int start_tsc, end_tsc;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);

    start_tsc = _rdtsc();
    mncblas_sswap(VECSIZE, vec1, 1, vec2, 1);
    end_tsc = _rdtsc();

    calcul_flop_tsc("swaps nano", 2 * VECSIZE, end_tsc - start_tsc);
  }
  printf("==========================================================\n");
}

void test_double()
{
  printf("Test swap  double\n");
  //  printf("Test swap  double\n");

  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_double_random(vec1d);
    vector_init_double_random(vec2d);
    vector_print_double(vec1d);
    vector_print_double(vec2d);
    printf("\n");
    mncblas_dswap(VECSIZE, vec1d, 2, vec2d, 2);
    //mncblas_dcopy(VECSIZE, vec1d, 2, vec2d, 2)
    vector_print_double(vec1d);
    vector_print_double(vec2d);
    printf("\n");
  }
  printf("==========================================================\n");
}

void perf_double()
{
  unsigned long long int start_tsc, end_tsc;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_double_random(vec1d);
    vector_init_double_random(vec2d);

    start_tsc = _rdtsc();
    mncblas_dswap(VECSIZE, vec1d, 1, vec2d, 1);
    //mncblas_dcopy(VECSIZE, vec1d, 2, vec2d, 2)
    end_tsc = _rdtsc();

    calcul_flop_tsc("swapd nano", 2 * VECSIZE, end_tsc - start_tsc);
  }
  printf("==========================================================\n");
}
void test_comp_float()
{
  printf("Test swap comp float\n");
    //  printf("Test swap comp float\n");

  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_comp_float_random(vec1cf);
    vector_init_comp_float_random(vec2cf);
    vector_print_comp_float(vec1cf);
    vector_print_comp_float(vec2cf);
    printf("\n");
    mncblas_cswap(VECSIZE, vec1cf, 2, vec2cf, 2);
    //mncblas_ccopy(VECSIZE, vec1d, 2, vec2d, 2)
    vector_print_comp_float(vec1cf);
    vector_print_comp_float(vec2cf);
    printf("\n");
  }
  printf("==========================================================\n");
}
void perf_omp_float()
{
  unsigned long long int start_tsc, end_tsc;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_comp_float_random(vec1cf);
    vector_init_comp_float_random(vec2cf);

    start_tsc = _rdtsc();
    mncblas_cswap(VECSIZE, vec1cf, 1, vec2cf, 1);
    //mncblas_ccopy(VECSIZE, vec1d, 2, vec2d, 2)

    end_tsc = _rdtsc();

    calcul_flop_tsc("swapcf nano", 2 * VECSIZE, end_tsc - start_tsc);
  }
  printf("==========================================================\n");
}
void test_comp_double()
{
  printf("Test swap comp double\n");
  //  printf("Test swap comp double\n");

  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_comp_double_random(vec1cd);
    vector_init_comp_double_random(vec2cd);
    vector_print_comp_double(vec1cd);
    vector_print_comp_double(vec2cd);
    printf("\n");
    mncblas_zswap(VECSIZE, vec1cd, 2, vec2cd, 2);
    //mncblas_zcopy(VECSIZE, vec1d, 2, vec2d, 2)

    vector_print_comp_double(vec1cd);
    vector_print_comp_double(vec2cd);
    printf("\n");
  }
  printf("==========================================================\n");
}
void perf_comp_double()
{
  unsigned long long int start_tsc, end_tsc;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_comp_double_random(vec1cd);
    vector_init_comp_double_random(vec2cd);

    start_tsc = _rdtsc();
    mncblas_zswap(VECSIZE, vec1cd, 1, vec2cd, 1);
    //mncblas_zcopy(VECSIZE, vec1d, 2, vec2d, 2)

    end_tsc = _rdtsc();

    calcul_flop_tsc("swapcd nano", 2 * VECSIZE, end_tsc - start_tsc);
  }
  printf("==========================================================\n");
}

int main(int argc, char **argv)
{
  perf_float();
}
