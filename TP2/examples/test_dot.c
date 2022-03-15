#include <stdio.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;

vfloat vec1, vec2 ;

void vector_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vector_print (vfloat V)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    printf ("%f ", V[i]) ;
  printf ("\n") ;
  
  return ;
}

int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 
 float res ;
 int i ;

 init_flop_tsc () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     start_tsc = _rdtsc () ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     TOP_MICRO(start) ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("sdot micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;

 init_flop_tsc () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     vector_init (vec1, 1.0) ;
     vector_init (vec2, 2.0) ;
     res = 0.0 ;
     
     start_tsc = _rdtsc () ;
        res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_nano ("sdot nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }

 printf ("res = %f\n", res) ;
 printf ("==========================================================\n") ;

}
