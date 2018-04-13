%module mean
%{
#define SWIG_FILE_WITH_INIT
#include "mean.h"
%}

%include "numpy.i"

%init %{
import_array();
%}

%apply (double* IN_ARRAY1, int DIM1) {(double* x, int len)};
%include "mean.h"