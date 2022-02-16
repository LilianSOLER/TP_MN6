#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2 ;
  
  if (argc != 5)
    {
      fprintf (stderr, "quatre paramètres (polynomes,fichiers) sont à passer \n") ;
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

  printf("P1 ° P2 = ");
  ecrire_polynome_float(composition_polynome(p1,p2)); 

  //test poly_creux
  p_polyf_creux_t p1_creux, p2_creux;
  
  if (argc != 5)
    {
      fprintf (stderr, "quatre paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  // p1_creux = lire_polynome_creux_float (argv [3]) ;
  // p2_creux = lire_polynome_creux_float (argv [4]) ;
  p1_creux = creer_polynome_creux();
  p2_creux = creer_polynome_creux();
  init_polynome_creux(p1_creux, 0);
  init_polynome_creux(p2_creux, 0);
  // monome_t *monome1, *monome2;
  // monome1 = monome2 = malloc(sizeof(monome_t));
  // monome1->degre = 1;
  // monome1->coeff = 1;
  // monome2->degre = 2;
  // monome2->coeff = 2;
  // monome2->next = NULL;
  // monome1->next = monome2;
  // p1_creux->monomes = monome1;
  // //p2_creux->monomes = monome2;
  
  // ecrire_polynome_creux_float (p1_creux) ;
  // //ecrire_polynome_creux_float (p2_creux) ;

  printf("P1 = P2 vaut : %d\n",egalite_polynome(p1,p2));
  printf("P2 = P2 vaut : %d\n",egalite_polynome(p2,p2));
}
