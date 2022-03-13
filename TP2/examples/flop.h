#include <time.h>
#include <sys/time.h>
#include <x86intrin.h>

#define TOP_MICRO(x) gettimeofday (&x,NULL) ;

#define TOP_NANO(x)  clock_gettime (CLOCK_MONOTONIC, &x) ;

float tdiff_micro (struct timeval *start, struct timeval *end) ;

double tdiff_nano (struct timespec *start, struct timespec *end) ;

void init_flop_micro () ;

void init_flop_nano () ;

void init_flop_tsc () ;

void calcul_flop_micro (char *message, unsigned int nb_operations_flottantes, float duree) ;

void calcul_flop_nano (char *message, int nb_operations_flottantes, double duree) ;

void calcul_flop_tsc (char *message, int nb_operations_flottantes, unsigned long long int nb_cycles) ;
