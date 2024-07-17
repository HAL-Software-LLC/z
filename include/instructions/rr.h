#ifndef Z_INSTRUCTION_H
#define Z_INSTRUCTION_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "instruction.h"

typedef struct {

  // RRFormat is a subclass of Instruction
  Instruction instruction;

} RRFormat;

#endif
