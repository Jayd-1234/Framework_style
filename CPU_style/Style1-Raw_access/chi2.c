#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "chi2.h"

double chi2(double m, double b, double* x, double* y, double* yerr,int N)
{
    double result=0.0, diff;

    for (int i=0; i<N; i++)
    {
        diff = (y[i]-(m*x[i]+b))/yerr[i];
        result += diff*diff;
    }

    return result;
}