import pycuda.autoinit
import pycuda.driver as drv
import pycuda.gpuarray as gpuarray
from pycuda.elementwise import ElementwiseKernel

def dot(lst):
    if isinstance(lst, gpuarray.GPUArray):
        kern = ElementwiseKernel(
            "float *x, float *y, "

        )