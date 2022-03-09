#include <stdio.h>
#include <x86intrin.h>

#include "flop.h"

static const double duree_cycle = (double) 1 / (double) 2.6 ;

// 2.6 Ghz sur la machine corte
// duree du cycle processeur en nano seconde (10e9)

static double residu_nano ;
static float residu_micro ;
static unsigned long long residu_tsc ;

float tdiff_micro (struct timeval *start,
	     struct timeval *end)
 {
   return (end->tv_sec - start->tv_sec) +
     1e-6*(end->tv_usec - start->tv_usec) ;
 }

double tdiff_nano (struct timespec *start,
	     struct timespec *end)
 {
   return (end->tv_sec - start->tv_sec) +
     1e-9*(end->tv_nsec - start->tv_nsec) ;
 }

void init_flop_micro ()
{
  struct timeval start, end ;

  TOP_MICRO(start) ;

  TOP_MICRO(end) ;

  residu_micro = tdiff_micro (&start, &end) ;
  printf ("residu_micro = %e\n", residu_micro) ; 
} 

void init_flop_nano ()
{
  struct timespec start, end ;

  TOP_NANO(start) ;

  TOP_NANO(end) ;

  residu_nano = tdiff_nano (&start, &end) ; ;
  printf ("residu_nano = %e \n", residu_nano) ;
}

void init_flop_tsc ()
{
  unsigned long long start, end ;

  start = _rdtsc () ;

  end = _rdtsc () ;

  residu_tsc = end - start ;
  printf ("residu_tsc = %Ld cycles \n", residu_tsc) ;
}



void calcul_flop_micro (char *message, unsigned int nb_operations_flottantes, float duree)
{
  printf ("%s %d operations duree %.7f seconde  Performance %5.3f GFLOP/s\n", message, nb_operations_flottantes, duree, ((float) nb_operations_flottantes / duree)/1000000000) ;
  return ;
}

void calcul_flop_nano (char *message, int nb_operations_flottantes, double duree)
{
  printf ("%s %d operations %.7f cycles Performance %5.3f GFLOP/s\n", message, nb_operations_flottantes, duree, ((double) nb_operations_flottantes) / duree) ;
  return ;
}

void calcul_flop_tsc (char *message, int nb_operations_flottantes, unsigned long long int nb_cycles)
{

  printf ("%s %d operations %Ld cycles Performance %5.3f GFLOP/s\n", message, nb_operations_flottantes, nb_cycles, ((double) nb_operations_flottantes) /  ((double) nb_cycles * duree_cycle)) ;
    
  return ;
}

