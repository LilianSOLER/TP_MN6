#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  ecrire_polynome_float (p2) ;

  /*
    ajouter du code pour tester les fonctions
    sur les polynomes
  */
  printf("\nTest :\n");
  printf("P1 = P2 vaut : %d\n",egalite_polynome(p1,p2));
  printf("P2 = P2 vaut : %d\n",egalite_polynome(p2,p2));

  int scalaire = 2;
  printf("%d * P1 = ", scalaire);
  ecrire_polynome_float(multiplication_polynome_scalaire(p1,scalaire));

  printf("P1(%d) = %lf\n", scalaire,eval_polynome(p1,scalaire));

  printf("P1 * P2 = ");
  ecrire_polynome_float(multiplication_polynomes(p1,p2));

  printf("P1^n = ");
  ecrire_polynome_float(puissance_polynome(p1, scalaire));

  
}
