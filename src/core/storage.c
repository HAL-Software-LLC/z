#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct {
	PyObject_HEAD

} Storage;

static PyTypeObject StorageType = {
	.ob_base = PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "core.Storage",
	.tp_doc = PyDoc_STR(
		"This type is used to represent main storage (RAM) on the IBM Z family of "
		"computers"),
	.tp_basicsize = sizeof(Storage),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_new = PyType_GenericNew,
};

static PyModuleDef CoreModule = {
  .m_base = PyModuleDef_HEAD_INIT,
  .m_name = "core",
  .m_doc = PyDoc_STR("Did this work?"),
  .m_size = -1,
};

PyMODINIT_FUNC PyInit_core(void) {
  /*
  Initialize the `core` module.
  */
  PyObject *m;
  
  if (PyType_Ready(&StorageType) < 0)
    return NULL;

  if ((m = PyModule_Create(&CoreModule)) == NULL)
    return NULL;

  Py_INCREF(&StorageType);
  if (PyModule_AddObject(m, "Storage", (PyObject *) &StorageType) < 0) {
    Py_DECREF(&StorageType);
    Py_DECREF(m);
    return NULL;
  }

  return m;  
}
