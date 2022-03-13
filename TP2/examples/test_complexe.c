#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define    NB_FOIS        512

int main (int argc, char **argv)
{
 complexe_float_t c1 = {1.0, 2.0} ;
 complexe_float_t c2 = {3.0, 6.0} ;

 complexe_double_t cd1 ;
 complexe_double_t cd2 ;

 struct timeval start, end ;
 
 int i ;

 init_flop_micro () ;
 
 c1 = add_complexe_float (c1, c2) ;

 printf ("c1.r %f c&.i %f\n", c1.real, c1.imaginary) ;

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;


 TOP_MICRO(start) ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd1 = add_complexe_double (cd1, cd2) ;
   }

 TOP_MICRO(end) ;

 printf ("apres boucle cd1.real %f cd1.imaginary %f duree %f \n", cd1.real, cd1.imaginary, tdiff_micro (&start, &end)) ;

 calcul_flop_micro ("calcul complexe ", NB_FOIS*2, tdiff_micro(&start, &end)) ;
 exit (0) ;
}
