from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

sourceFiles = ["modules/GLNetEISimLib.py"]

extensions = cythonize(Extension(
             name="modules.GLNetEISimLib",
             sources = sourceFiles
      ))

kwargs = {
       "name": "GLNetEISimLib",
       "packages": find_packages(),
       "ext_modules": extensions
      }

setup(**kwargs)