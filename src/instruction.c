#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "storage.h"
#include "instruction.h"

// instantiation / destruction
int Instruction_init(Instruction *self, PyObject *args, PyObject *kwargs) {
  /*
  Initialize an instance of Instruction.
  */
  self->storage.addr = (uint64_t) &self->instruction_buffer;
  self->storage.dim = 0;
  self->storage.size = 2;
  self->storage.length = 2;
  self->storage.datatype = 'I';

  return 0;
}

static PyTypeObject InstructionType = {
	.ob_base = PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "z.instruction.Instruction",
	.tp_doc = PyDoc_STR(
    "This type is used to represent and manipulate machine instructions "
    "on the IBM Z family of computers."),
	.tp_basicsize = sizeof(Instruction),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = PyType_GenericNew,
  .tp_init = (initproc) *Instruction_init,
};

static PyModuleDef InstructionModule = {
  .m_base = PyModuleDef_HEAD_INIT,
  .m_name = "z.instruction",
  .m_doc = PyDoc_STR(
    "This module defines types and functions for representing and manipulating machine instructions "
    "on the IBM Z family of computers."),
  .m_size = -1,
};

PyMODINIT_FUNC PyInit_instruction(void) {
  /*
  Initialize the `z.instruction` module.
  */
  PyObject *m;
  
  if (PyType_Ready(&InstructionType) < 0)
    return NULL;

  if ((m = PyModule_Create(&InstructionModule)) == NULL)
    return NULL;

  Py_INCREF(&InstructionType);
  if (PyModule_AddObject(m, "Instruction", (PyObject *) &InstructionType) < 0) {
    Py_DECREF(&InstructionType);
    Py_DECREF(m);
    return NULL;
  }

  return m;  
}
