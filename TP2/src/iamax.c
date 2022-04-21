#include <math.h> // import necessaire pour utiliser fabs (valeur absolue d'un flottant)
#include "mnblas.h"
#include "complexe.h"

void mnblas_isamax(const int N, const float *X, const int incX){
    int imax;
    float max;
    if (N < 1){
        return 0;
    }
    else{
        imax = 0;
        max = X[0];
    }
    for (int i = 1; i < N; i += incX){
            if(fabs(X[i]) > fabs(max)){
                max = X[i];
                imax = i;
            }
        }
    return imax;
}

void mnblas_idamax(const int N, const double *X, const int incX){
    int imax;
    double max;
    if (N < 1){
        return 0;
    }
    else{
        imax = 0;
        max = X[0];
    }
    for (int i = 1; i < N; i += incX){
            if(fabs(X[i]) > fabs(max)){
                max = X[i];
                imax = i;
            }
        }
    return imax;
}

void mnblas_icamax(const int N, const void *X, const int incX){
    if (N < 1){
        return 0;
    }
    else{
        for (int i; i < N; i += incX){
            //A faire
        }
    }
}

void mnblas_izamax(const int N, const void *X, const int incX){
    if (N < 1){
        return 0;
    }
    else{
        for (int i; i < N; i += incX){
            //A faire
        }
    }
}