#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE 65536
// #define VECSIZE 10

#define NB_FOIS 10

typedef float vfloat[VECSIZE];
typedef double vdouble[VECSIZE];
typedef complexe_double_t vcomp_double[VECSIZE];

vfloat vec1, vec2;
vdouble vec1d, vec2d;
vcomp_double vec1cd, vec2cd;

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

void test_swap_double()
{
  printf("Test swap double\n");
  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_double_random(vec1d);
    vector_init_double_random(vec2d);
    vector_print_double(vec1d);
    vector_print_double(vec2d);
    printf("\n");
    mncblas_dswap(VECSIZE, vec1d, 2, vec2d, 2);
    vector_print_double(vec1d);
    vector_print_double(vec2d);
    printf("\n");
  }
  printf("==========================================================\n");
}

void perf_swap_double()
{
  unsigned long long int start_tsc, end_tsc;

  init_flop_tsc();

  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_double_random(vec1d);
    vector_init_double_random(vec2d);

    start_tsc = _rdtsc();
    mncblas_dswap(VECSIZE, vec1d, 1, vec2d, 1);
    end_tsc = _rdtsc();

    calcul_flop_tsc("swapd nano", 2 * VECSIZE, end_tsc - start_tsc);
  }
  printf("==========================================================\n");
}

void test_swap_comp_double()
{
  printf("Test swap comp double\n");
  srand(time(NULL));
  for (int i = 0; i < NB_FOIS; i++)
  {
    vector_init_comp_double_random(vec1cd);
    vector_init_comp_double_random(vec2cd);
    vector_print_comp_double(vec1cd);
    vector_print_comp_double(vec2cd);
    printf("\n");
    mncblas_cswap(VECSIZE, vec1cd, 2, vec2cd, 2);
    vector_print_comp_double(vec1cd);
    vector_print_comp_double(vec2cd);
    printf("\n");
  }
  printf("==========================================================\n");
}

int main(int argc, char **argv)
{
  // basic_main();
  // test_swap_double();
  // perf_swap_double();
  test_swap_comp_double();
}
