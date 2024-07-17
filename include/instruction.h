#ifndef Z_INSTRUCTION_H
#define Z_INSTRUCTION_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "storage.h"

typedef struct {

  // Instruction is a subclass of Storage
  Storage storage;

  // space for building instruction
  char instruction_buffer[6];

  // 2, 3, or 4 nibble opcode
  uint16_t opcode;

} Instruction;

#endif
