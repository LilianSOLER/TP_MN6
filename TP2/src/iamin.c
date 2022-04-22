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
    int imin;
    float min, temp;
    if (N < 1){
        return 0;
    }
    else{
        imin = 0;
        min = (((complexe_float_t*)X)->real < 0 ? -((complexe_float_t*)X)->real : ((complexe_float_t*)X)->real)
        + (((complexe_float_t*)X)->imaginary < 0 ? -((complexe_float_t*)X)->imaginary : ((complexe_float_t*)X)->imaginary);
    }
    for (int i = 1; i < N; i += incX){
        temp = (((complexe_float_t*)X+i)->real < 0 ? -((complexe_float_t*)X+i)->real : ((complexe_float_t*)X+i)->real)
        + (((complexe_float_t*)X+i)->imaginary < 0 ? -((complexe_float_t*)X+i)->imaginary : ((complexe_float_t*)X+i)->imaginary);
        if(fabs(temp) < fabs(min)){
            min = temp;
            imin = i;
            }
    }
    return imin;
}

int mnblas_izamin(const int N, const void *X, const int incX){
    int imin;
    double min, temp;
    if (N < 1){
        return 0;
    }
    else{
        imin = 0;
        min = (((complexe_double_t*)X)->real < 0 ? -((complexe_double_t*)X)->real : ((complexe_double_t*)X)->real)
        + (((complexe_double_t*)X)->imaginary < 0 ? -((complexe_double_t*)X)->imaginary : ((complexe_double_t*)X)->imaginary);
    }
    for (int i = 1; i < N; i += incX){
        temp = (((complexe_double_t*)X+i)->real < 0 ? -((complexe_double_t*)X+i)->real : ((complexe_double_t*)X+i)->real)
        + (((complexe_double_t*)X+i)->imaginary < 0 ? -((complexe_double_t*)X+i)->imaginary : ((complexe_double_t*)X+i)->imaginary);
        if(fabs(temp) < fabs(min)){
            min = temp;
            imin = i;
            }
    }
    return imin;
}