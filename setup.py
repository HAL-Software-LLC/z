from distutils.core import setup, Extension

setup(name="z", version="1.0", ext_modules=[
  Extension("core", ["src/core.c"]),
])
