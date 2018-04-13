#include <Python.h>
#include <numpy/arrayobject.h>
#include "chi2.h"

static PyObject *_chi2_chi2(PyObject *self, PyObject *args)
{
    double m, b;
    PyObject* x, *y, *yerr;

    if (!PyArg_ParseTuple(args, "ddOOO", &m, &b, x, y, yerr))
        return NULL;
    
    PyObject *x_arr = PyArray_FROM_OTF(x, NPY_DOUBLE, NPY_IN_ARRAY);
    PyObject *y_arr = PyArray_FROM_OTF(y, NPY_DOUBLE, NPY_IN_ARRAY);
    PyObject *yerr_arr = PyArray_FROM_OTF(yerr, NPY_DOUBLE, NPY_IN_ARRAY);

    if (x_arr == NULL || y_arr == NULL || yerr_arr == NULL) {
        Py_XDECREF(x_arr);
        Py_XDECREF(y_arr);
        Py_XDECREF(yerr_arr);
        return NULL;
    }

    int N = (int)PyArray_DIM(x_arr, 0);

    double *x_data = (double *)PyArray_DATA(x_arr);
    double *y_data = (double *)PyArray_DATA(y_arr);
    double *yerr_data = (double *)PyArray_DATA(yerr_arr);

    double result = chi2(m, b, x_data, y_data, yerr_data, N);

    Py_DECREF(x_arr);
    Py_DECREF(y_arr);
    Py_DECREF(yerr_arr);

    PyObject* ret =  Py_BuildValue("d", result);
    return ret;
}

static PyMethodDef module_methods[]={
    {"chi2", _chi2_chi2, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC init_chi2(void)
{
    PyObject* m =  Py_InitModule3("chi2", _chi2_chi2, "Ohh.");
    if (m==NULL)
        return NULL;
    import_array();
}


