#define PY_SSIZE_T_CLEAN
#include <Python.h>

#ifndef Z_STORAGE_H
#define Z_STORAGE_H

typedef struct {
  PyObject_HEAD

  // 24-bit, 31-bit, or 64-bit storage address
  uint64_t addr;

  // dimension, size, and total length of storage area in bytes
  uint64_t dim;
  uint64_t size;
  uint64_t length;

  // alignment (generally 1=byte, 2=halfword, 4=word, 8=doubleword, or 16=quadword)
  unsigned char boundary;

  // type information
  unsigned char asmtype;
  unsigned char datatype;

} Storage;

#endif
