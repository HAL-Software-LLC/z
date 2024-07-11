#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "storage.h"

static PyTypeObject StorageType = {
	.ob_base = PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "z.storage.Storage",
	.tp_doc = PyDoc_STR(
    "This type is used to represent and manipulate data on the IBM Z family of computers."),
	.tp_basicsize = sizeof(Storage),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = PyType_GenericNew,
};

static PyModuleDef StorageModule = {
  .m_base = PyModuleDef_HEAD_INIT,
  .m_name = "z.storage",
  .m_doc = PyDoc_STR(
    "This module defines types and functions for representing and manipulating data "
    "on the IBM Z family of computers."),
  .m_size = -1,
};

PyMODINIT_FUNC PyInit_storage(void) {
  /*
  Initialize the `z.storage` module.
  */
  PyObject *m;
  
  if (PyType_Ready(&StorageType) < 0)
    return NULL;

  if ((m = PyModule_Create(&StorageModule)) == NULL)
    return NULL;

  Py_INCREF(&StorageType);
  if (PyModule_AddObject(m, "Storage", (PyObject *) &StorageType) < 0) {
    Py_DECREF(&StorageType);
    Py_DECREF(m);
    return NULL;
  }

  return m;  
}
