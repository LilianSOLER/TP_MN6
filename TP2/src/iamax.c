#include <math.h> // import necessaire pour utiliser fabs (valeur absolue d'un flottant)
#include "mnblas.h"
#include "complexe.h"

int mnblas_isamax(const int N, const float *X, const int incX){
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

int mnblas_idamax(const int N, const double *X, const int incX){
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

int mnblas_icamax(const int N, const void *X, const int incX){
    int imax;
    float max, temp;
    if (N < 1){
        return 0;
    }
    else{
        imax = 0;
        max = (((complexe_float_t*)X)->real < 0 ? -((complexe_float_t*)X)->real : ((complexe_float_t*)X)->real)
        + (((complexe_float_t*)X)->imaginary < 0 ? -((complexe_float_t*)X)->imaginary : ((complexe_float_t*)X)->imaginary);
    }
    for (int i = 1; i < N; i += incX){
        temp = (((complexe_float_t*)X+i)->real < 0 ? -((complexe_float_t*)X+i)->real : ((complexe_float_t*)X+i)->real)
        + (((complexe_float_t*)X+i)->imaginary < 0 ? -((complexe_float_t*)X+i)->imaginary : ((complexe_float_t*)X+i)->imaginary);
        if(fabs(temp) > fabs(max)){
            max = temp;
            imax = i;
            }
    }
    return imax;
}

int mnblas_izamax(const int N, const void *X, const int incX){
    int imax;
    double max, temp;
    if (N < 1){
        return 0;
    }
    else{
        imax = 0;
        max = (((complexe_double_t*)X)->real < 0 ? -((complexe_double_t*)X)->real : ((complexe_double_t*)X)->real)
        + (((complexe_double_t*)X)->imaginary < 0 ? -((complexe_double_t*)X)->imaginary : ((complexe_double_t*)X)->imaginary);
    }
    for (int i = 1; i < N; i += incX){
        temp = (((complexe_double_t*)X+i)->real < 0 ? -((complexe_double_t*)X+i)->real : ((complexe_double_t*)X+i)->real)
        + (((complexe_double_t*)X+i)->imaginary < 0 ? -((complexe_double_t*)X+i)->imaginary : ((complexe_double_t*)X+i)->imaginary);
        if(fabs(temp) > fabs(max)){
            max = temp;
            imax = i;
            }
    }
    return imax;
}