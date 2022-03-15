#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define N 2048

double A[N][N];
double B[N][N];
double C[N][N];

float tdiff(struct timeval *a, struct timeval *b)
{
  return (float)(b->tv_sec - a->tv_sec) + (float)(b->tv_usec - a->tv_usec) / 1000000.0;
}

int main(int argc, char **argv)
{
  int i, j, k;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      A[i][j] = (double) (rand() / RAND_MAX);
      B[i][j] = (double) (rand() / RAND_MAX);
      C[i][j] = 0.0;
    }
  }

  struct timeval start, end;

  gettimeofday(&start, NULL);

  #pragma omp parallel for private(i, j, k)
  for(i = 0; i < N; i++){
    for(k = 0; k < N; k++){
      for(j = 0; j < N; j++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  gettimeofday(&end, NULL);
  printf("%0.6f\n", tdiff(&start, &end));
  return 0;
}