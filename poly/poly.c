#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "poly.h"

#include <x86intrin.h>

p_polyf_t creer_polynome (int degre)
{
  p_polyf_t p ;
  
  p = (p_polyf_t) malloc (sizeof (polyf_t)) ;
  p->degre = degre ;

  p->coeff = (float *) malloc ((degre+1) * sizeof (float))  ;

  return p ;
}

void detruire_polynome (p_polyf_t p)
{
  free (p->coeff) ;
  free (p) ;

  return ;
}

void init_polynome (p_polyf_t p, float x)
{
  register unsigned int i ;

  for (i = 0 ; i <= p->degre; ++i)
    p->coeff [i] = x ;

  return ;
}



p_polyf_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_t p ;
  int degre ;
  int i  ;
  int cr ;
  
  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
    {
      fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
      exit (-1) ;
    }
  
  cr = fscanf (f, "%d", &degre) ;
  if (cr != 1)
    {
      fprintf (stderr, "erreur lecture du degre\n") ;
      exit (-1) ;
    }
  p = creer_polynome (degre) ;
  
  for (i = 0 ; i <= degre; i++)
    { 
      cr = fscanf (f, "%f", &p->coeff[i]) ;
      if (cr != 1)
    {
      fprintf (stderr, "erreur lecture coefficient %d\n", i) ;
      exit (-1) ;
    }
    
    }

  fclose (f) ;

  return p ;
}

void ecrire_polynome_float (p_polyf_t p)
{
  int i ;

  printf ("%f + %f x ", p->coeff [0], p->coeff [1]) ;
  
  for (i = 2 ; i <= p->degre; i++)
    {  
      printf ("+ %f X^%d ", p->coeff [i], i) ;
    }
  
  printf ("\n\n") ;

  return ;
}

int egalite_polynome (p_polyf_t p1, p_polyf_t p2)
{
  /*
    tester les deux polynomes p1 et p2
  */
  if(p1->degre != p2->degre)
    return 0;
  else
    {
      for(int i = 0; i <= p1->degre; i++){
        if(p1->coeff[i] != p2->coeff[i])
          return 0;
      }
  }
  return 1;
}

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t p3 ;
  register unsigned int i ;
  
  p3 = creer_polynome (max (p1->degre, p2->degre));

  for (i = 0 ; i <= min (p1->degre, p2->degre); ++i)
    {
      p3->coeff [i] = p1->coeff [i] + p2->coeff [i] ;
    }

  if (p1->degre > p2->degre)
    {
      for (i = (p2->degre + 1) ; i <= p1->degre; ++i)
	p3->coeff [i] = p1->coeff [i] ;
    }
  else if (p2->degre > p1->degre)
    {
      for (i = (p1->degre + 1) ; i <= p2->degre; ++i)
	p3->coeff [i] = p2->coeff [i] ;
    }
    
  return p3 ;
}

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha)
{
  /* alpha * p1 */
  p_polyf_t res = creer_polynome (p->degre);
  init_polynome(res, 0);
  for(int i = 0; i <= p->degre; i++){
    res->coeff[i] = alpha * p->coeff[i];
  }
  return res ;
}

float eval_polynome (p_polyf_t p, float x)
{
  /* 
    valeur du polynome pour la valeur de x
  */
  float res = 0.0 ;
  for(int i = 0; i <= p->degre; i++){
    res += p->coeff[i] * pow(x, i);
  }
  return res ;
}

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2)
{
  /* p1 * p2 */
  
  p_polyf_t res = creer_polynome (p1->degre + p2->degre);
  init_polynome(res, 0);
  for(int i = 0; i <= p1->degre; i++){
    for(int j = 0; j <= p2->degre; j++){
      res->coeff[i+j] += p1->coeff[i] * p2->coeff[j];
    }
  }
  return res ;
}

p_polyf_t puissance_polynome (p_polyf_t p, int n)
{
  //p^n
  p_polyf_t res = p;  
  for(int i = 0; i < n; i++){
    res = multiplication_polynomes(p, res);
  }
  return res;
}

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q)
{
  /*
    p O q
  */
  p_polyf_t res = creer_polynome (p->degre * q->degre);
  init_polynome(res, 0);
  for (int i = 0; i < p->degre; i++) {
    res = addition_polynome(res, multiplication_polynome_scalaire(puissance_polynome(q, i), p->coeff[i]));
  }
  return res;
}