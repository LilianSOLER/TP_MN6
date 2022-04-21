#include <math.h> // import necessaire pour utiliser fabs (valeur absolue d'un flottant)
#include "mnblas.h"
#include "complexe.h"

int mnblas_isamin(const int N, const float *X, const int incX){
    int imin;
    float min;
    if (N < 1){
        return 0;
    }
    else{
        imin = 0;
        min = X[0];
    }
    for (int i = 1; i < N; i += incX){
            if(fabs(X[i]) < fabs(min)){
                min = X[i];
                imin = i;
            }
        }
    return imin;
}

int mnblas_idamin(const int N, const double *X, const int incX){
    int imin;
    double min;
    if (N < 1){
        return 0;
    }
    else{
        imin = 0;
        min = X[0];
    }
    for (int i = 1; i < N; i += incX){
            if(fabs(X[i]) < fabs(min)){
                min = X[i];
                imin = i;
            }
        }
    return imin;
}

int mnblas_icamin(const int N, const void *X, const int incX){
    if (N < 1){
        return 0;
    }
    else{
        for (int i; i < N; i += incX){
            //A faire
        }
    }
}

int mnblas_izamin(const int N, const void *X, const int incX){
    if (N < 1){
        return 0;
    }
    else{
        for (int i; i < N; i += incX){
            //A faire
        }
    }
}