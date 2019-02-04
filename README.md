# Speed up your Python 30x!
This repository is for a Python workshop titled *Speed up your Python 30x!* that was held on Feb 1st, 2019 at McGill University. This was part of the Workshop Series on Atmospheric Data Science. The presentation is uploaded as 'Python30x.pdf'. 

This workshop gives a brief tour of how to speed up Python code by using the C language.

### Three ways to improve Python performance with C:

1. Using packages that have efficient C bindings, such as:
   * numpy
   * netCDF4
   * scipy
2. Compile C code into a binary that can be called by your Python script.
   * [subprocess.call()](https://docs.python.org/3/library/subprocess.html)
   * [os.system()](https://docs.python.org/3/library/os.html)
3. Compile C code into a shared library, whose functions can be called from Python by use of the [ctypes](https://docs.python.org/3/library/ctypes.html) module.
