
from distutils.core import *
from distutils import sysconfig

import numpy

# Obtain the numpy include directory.
numpy_include = numpy.get_include()

setup(
      name="mean",
      version="1.0",
      ext_modules=[Extension('_mean', ['mean.cpp', 'mean.i'],
      include_dirs=[numpy_include,'.']
      )]
)