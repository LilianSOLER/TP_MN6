/*
  polyf_t   : structure polynome
  p_polyf_t : pointeur sur un polynome
*/

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct {
  int degre ;
  float *coeff;
} polyf_t, *p_polyf_t;

p_polyf_t creer_polynome (int degre) ;

void init_polynome (p_polyf_t p, float x) ;

void detruire_polynome (p_polyf_t p) ;

p_polyf_t lire_polynome_float (char *nom_fichier) ;

void ecrire_polynome_float (p_polyf_t p) ;

int egalite_polynome (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha) ;

float eval_polynome (p_polyf_t p, float x) ;

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2) ;

p_polyf_t puissance_polynome (p_polyf_t p, int n) ;

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q) ;

//POLYNOME CREUX
typedef struct monome{
  int degre;
  float coeff;
  struct monome *next;
} monome_t, *p_monome_t;

typedef struct poly_creux_t {
  monome_t *monomes;
} polyf_creux_t, *p_polyf_creux_t;

p_polyf_creux_t creer_polynome_creux () ;
void detruire_polynome_creux (p_polyf_creux_t p);
void init_polynome_creux (p_polyf_creux_t p, float x);

p_polyf_creux_t lire_polynome_creux_float (char *nom_fichier);
void ecrire_polynome_creux_float (p_polyf_creux_t p);

int egalite_polynome_creux (p_polyf_creux_t p1, p_polyf_creux_t p2);

p_polyf_creux_t addition_polynome_creux (p_polyf_creux_t p1, p_polyf_creux_t p2);
p_polyf_creux_t multiplication_polynome_creux_scalaire (p_polyf_creux_t p, float alpha);

float eval_polynome_creux (p_polyf_creux_t p, float x);

p_polyf_creux_t multiplication_polynomes_creux (p_polyf_creux_t p1, p_polyf_creux_t p2);
p_polyf_creux_t puissance_polynome_creux (p_polyf_creux_t p, int n);
p_polyf_creux_t composition_polynome_creux (p_polyf_creux_t p, p_polyf_creux_t q);