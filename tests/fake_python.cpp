#include "dl_python.hpp"

#include <Python.h>
#include <frameobject.h>

extern "C" {

int Py_IsInitialized() {
    return dl_python::get_instance().get<int()>("Py_IsInitialized")();
}

void Py_InitializeEx(int initsigs) {
    return dl_python::get_instance().get<void(int)>("Py_InitializeEx")(initsigs);
}

PyThreadState *Py_NewInterpreter() {
    return dl_python::get_instance().get<PyThreadState *()>("Py_NewInterpreter")();
}

void Py_Finalize() {
    return dl_python::get_instance().get<void(void)>("Py_Finalize")();
}

PyObject *PyWeakref_NewRef(PyObject *ob, PyObject *callback) {
    return dl_python::get_instance().get<PyObject *(PyObject *, PyObject *)>("PyWeakref_NewRef")(ob, callback);
}

void PyBuffer_Release(Py_buffer *view) {
    return dl_python::get_instance().get<void(Py_buffer *)>("PyBuffer_Release")(view);
}

char *PyBytes_AsString(PyObject *o) {
    return dl_python::get_instance().get<char *(PyObject *)>("PyBytes_AsString")(o);
}

int PyBytes_AsStringAndSize(PyObject *obj, char **buffer, Py_ssize_t *length) {
    return dl_python::get_instance().get<int(PyObject *, char **, Py_ssize_t *)>("PyBytes_AsStringAndSize")(obj, buffer,
                                                                                                            length);
}

Py_ssize_t PyBytes_Size(PyObject *o) {
    return dl_python::get_instance().get<Py_ssize_t(PyObject *)>("PyBytes_Size")(o);
}

PyObject *PyCFunction_NewEx(PyMethodDef *ml, PyObject *self, PyObject *module) {
    return dl_python::get_instance().get<PyObject *(PyMethodDef *, PyObject *, PyObject *)>("PyCFunction_NewEx")(ml,
                                                                                                                 self,
                                                                                                                 module);
}

void *PyCapsule_GetContext(PyObject *o) {
    return dl_python::get_instance().get<void *(PyObject *)>("PyCapsule_GetContext")(o);
}

const char *PyCapsule_GetName(PyObject *o) {
    return dl_python::get_instance().get<const char *(PyObject *)>("PyCapsule_GetName")(o);
}

void *PyCapsule_GetPointer(PyObject *o, const char *name) {
    return dl_python::get_instance().get < void * (PyObject * ,
    const char *)>("PyCapsule_GetPointer")(o, name);
}

PyObject *PyCapsule_New(void *pointer, const char *name, PyCapsule_Destructor destructor) {
    return dl_python::get_instance().get < PyObject * (void * ,
    const char *, PyCapsule_Destructor )>("PyCapsule_New")(pointer, name, destructor);
}

int PyCapsule_SetContext(PyObject *o, void *context) {
    return dl_python::get_instance().get<int(PyObject *, void *)>("PyCapsule_SetContext")(o, context);
}

int PyDict_Contains(PyObject *op, PyObject *key) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *)>("PyDict_Contains")(op, key);
}

PyObject *PyDict_Copy(PyObject *o) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyDict_Copy")(o);
}

int PyDict_DelItemString(PyObject *v, const char *key) {
    return dl_python::get_instance().get < int(PyObject * ,
    const char *)>("PyDict_DelItemString")(v, key);
}

PyObject *PyDict_GetItemString(PyObject *v, const char *key) {
    return dl_python::get_instance().get < PyObject * (PyObject * ,
    const char *)>("PyDict_GetItemString")(v, key);
}

PyObject *PyDict_New(void) {
    return dl_python::get_instance().get<PyObject *(void)>("PyDict_New")();
}

int PyDict_Next(PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value) {
    return dl_python::get_instance().get<int(PyObject *, Py_ssize_t *, PyObject **, PyObject **)>("PyDict_Next")(mp,
                                                                                                                 pos,
                                                                                                                 key,
                                                                                                                 value);
}

Py_ssize_t PyDict_Size(PyObject *mp) {
    return dl_python::get_instance().get<Py_ssize_t(PyObject *)>("PyDict_Size")(mp);
}

void PyErr_Clear(void) {
    dl_python::get_instance().get<void(void)>("PyErr_Clear")();
}

void PyErr_Fetch(PyObject **e1, PyObject **e2, PyObject **e3) {
    dl_python::get_instance().get<void(PyObject **, PyObject **, PyObject **)>("PyErr_Fetch")(e1, e2, e3);
}

void PyErr_NormalizeException(PyObject **e1, PyObject **e2, PyObject **e3) {
    dl_python::get_instance().get<void(PyObject **, PyObject **, PyObject **)>("PyErr_NormalizeException")(e1, e2, e3);
}

PyObject *PyErr_Occurred(void) {
    return dl_python::get_instance().get<PyObject *(void)>("PyErr_Occurred")();
}

void PyErr_Restore(PyObject *e1, PyObject *e2, PyObject *e3) {
    dl_python::get_instance().get<void(PyObject *, PyObject *, PyObject *)>("PyErr_Restore")(e1, e2, e3);
}

void PyErr_SetString(
        PyObject *exception,
        const char *string   /* decoded from utf-8 */
) {
    dl_python::get_instance().get < void(PyObject * ,
    const char *)>("PyErr_Restore")(exception, string);
}

int PyErr_WarnEx(PyObject *category, const char *text, Py_ssize_t stack_level) {
    return dl_python::get_instance().get < int(PyObject * ,
    const char *,Py_ssize_t)>("PyErr_Restore")(category, text, stack_level);
}

void PyEval_AcquireThread(PyThreadState *tstate) {
    return dl_python::get_instance().get<void(PyThreadState *)>("PyEval_AcquireThread")(tstate);
}

PyObject *PyEval_GetBuiltins(void) {
    return dl_python::get_instance().get<PyObject *(void)>("PyEval_GetBuiltins")();
}

void PyEval_InitThreads(void) {
    dl_python::get_instance().get<void(void)>("PyEval_InitThreads")();
}

PyThreadState *PyEval_SaveThread(void) {
    return dl_python::get_instance().get<PyThreadState *(void)>("PyEval_SaveThread")();
}

PyThreadState *PyGILState_GetThisThreadState(void) {
    return dl_python::get_instance().get<PyThreadState *(void)>("PyGILState_GetThisThreadState")();
}

PyObject *PyImport_ImportModule(const char *name /* UTF-8 encoded string */) {
    return dl_python::get_instance().get < PyObject *(const char *)>("PyImport_ImportModule")(name);
}

PyObject *PyInstanceMethod_New(PyObject *o) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyInstanceMethod_New")(o);
}

int PyList_Append(PyObject *o1, PyObject *o2) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *)>("PyList_Append")(o1, o2);
}

void *PyMem_Calloc(size_t nelem, size_t elsize) {
    return dl_python::get_instance().get<void *(size_t, size_t)>("PyMem_Calloc")(nelem, elsize);
}

void PyMem_Free(void *ptr) {
    dl_python::get_instance().get<void(void *)>("PyMem_Free")(ptr);
}

PyObject *PyObject_CallObject(PyObject *callable, PyObject *args) {
    return dl_python::get_instance().get<PyObject *(PyObject *, PyObject *)>("PyObject_CallObject")(callable, args);
}

void PyObject_ClearWeakRefs(PyObject *object) {
    dl_python::get_instance().get<void(PyObject *)>("PyObject_ClearWeakRefs")(object);
}

PyObject *PyObject_GetAttrString(PyObject *e1, const char *e2) {
    return dl_python::get_instance().get < PyObject * (PyObject * ,
    const char *)>("PyObject_GetAttrString")(e1, e2);
}

PyObject *PyObject_GetItem(PyObject *o, PyObject *key) {
    return dl_python::get_instance().get<PyObject *(PyObject *, PyObject *)>("PyObject_GetItem")(o, key);
}

int PyObject_HasAttrString(PyObject *o, const char *e1) {
    return dl_python::get_instance().get < int(PyObject * ,
    const char *)>("PyObject_HasAttrString")(o, e1);
}

int PyObject_IsInstance(PyObject *object, PyObject *typeorclass) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *)>("PyObject_IsInstance")(object, typeorclass);
}

PyObject *PyObject_Repr(PyObject *v) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyObject_Repr")(v);
}

int PyObject_SetAttrString(PyObject *o, const char *text, PyObject *o1) {
    return dl_python::get_instance().get < int(PyObject * ,
    const char *, PyObject *)>("PyObject_SetAttrString")(o, text, o1);
}

Py_tss_t *PyThread_tss_alloc(void) {
    return dl_python::get_instance().get<Py_tss_t *(void)>("PyThread_tss_alloc")();
}
void PyThread_tss_free(Py_tss_t *key) {
    dl_python::get_instance().get<void(Py_tss_t *)>("PyThread_tss_free")(key);
}
int PyThread_tss_is_created(Py_tss_t *key) {
    return dl_python::get_instance().get<int(Py_tss_t *)>("PyThread_tss_is_created")(key);
}

int PyThread_tss_create(Py_tss_t *key) {
    return dl_python::get_instance().get<int(Py_tss_t *)>("PyThread_tss_create")(key);
}

void PyThread_tss_delete(Py_tss_t *key) {
    dl_python::get_instance().get<void(Py_tss_t *)>("PyThread_tss_delete")(key);
}

int PyThread_tss_set(Py_tss_t *key, void *value) {
    return dl_python::get_instance().get<int(Py_tss_t *, void *)>("PyThread_tss_set")(key, value);
}

void *PyThread_tss_get(Py_tss_t *key) {
    return dl_python::get_instance().get<void *(Py_tss_t *)>("PyThread_tss_get")(key);
}

void PyThreadState_Clear(PyThreadState *ts) {
    dl_python::get_instance().get<void(PyThreadState *)>("PyThreadState_Clear")(ts);
}

void PyThreadState_DeleteCurrent(void) {
    dl_python::get_instance().get<void(void)>("PyThreadState_DeleteCurrent")();
}

PyThreadState *PyThreadState_Get(void) {
    return dl_python::get_instance().get<PyThreadState *(void)>("PyThreadState_Get")();
}

PyThreadState *PyThreadState_New(PyInterpreterState *is) {
    return dl_python::get_instance().get<PyThreadState *(PyInterpreterState *)>("PyThreadState_New")(is);
}

int PyException_SetTraceback(PyObject *o1, PyObject *o2) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *)>("PyException_SetTraceback")(o1, o2);
}

int PyObject_SetItem(PyObject *o, PyObject *key, PyObject *value) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *, PyObject *)>("PyObject_SetItem")(o, key, value);
}

PyObject *PyObject_Str(PyObject *v) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyObject_Str")(v);
}

PyObject *PySequence_List(PyObject *v) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PySequence_List")(v);
}

PyObject *PyTuple_GetItem(PyObject *o, Py_ssize_t size) {
    return dl_python::get_instance().get<PyObject *(PyObject *, Py_ssize_t)>("PyTuple_GetItem")(o, size);
}
PyObject *PyTuple_New(Py_ssize_t size) {
    return dl_python::get_instance().get<PyObject *(Py_ssize_t)>("PyTuple_New")(size);
}
int PyTuple_SetItem(PyObject *o1, Py_ssize_t size, PyObject *o2) {
    return dl_python::get_instance().get<int(PyObject *, Py_ssize_t, PyObject *)>("PyTuple_SetItem")(o1, size, o2);
}
Py_ssize_t PyTuple_Size(PyObject *o) {
    return dl_python::get_instance().get<Py_ssize_t(PyObject *)>("PyTuple_Size")(o);
}
int PyType_Ready(PyTypeObject *type) {
    return dl_python::get_instance().get<int(PyTypeObject *)>("PyType_Ready")(type);
}
PyObject *PyUnicode_AsEncodedString(
        PyObject *unicode,          /* Unicode object */
        const char *encoding,       /* encoding */
        const char *errors          /* error handling */
) {
    return dl_python::get_instance().get < PyObject * (PyObject * ,
    const char *,const char *)>("PyUnicode_AsEncodedString")(unicode, encoding, errors);
}

PyObject *PyUnicode_AsUTF8String(PyObject *unicode /* Unicode object */) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyUnicode_AsUTF8String")(unicode);
}

PyObject *PyUnicode_DecodeUTF8(
        const char *string,         /* UTF-8 encoded string */
        Py_ssize_t length,          /* size of string */
        const char *errors          /* error handling */
) {
    return dl_python::get_instance().get < PyObject *( const char *,Py_ssize_t,
    const char *)>("PyUnicode_DecodeUTF8")(string, length, errors);
}

PyObject *PyUnicode_FromString(const char *u /* UTF-8 encoded string */) {
    return dl_python::get_instance().get < PyObject *( const char *)>("PyUnicode_FromString")(u);
}

int PyFrame_GetLineNumber(PyFrameObject *fo) {
    return dl_python::get_instance().get<int(PyFrameObject *)>("PyFrame_GetLineNumber")(fo);
}

PyObject **_PyObject_GetDictPtr(PyObject *obj) {
    return dl_python::get_instance().get<PyObject **(PyObject *)>("_PyObject_GetDictPtr")(obj);
}

PyThreadState *_PyThreadState_UncheckedGet(void) {
    return dl_python::get_instance().get<PyThreadState *(void)>("_PyThreadState_UncheckedGet")();
}

PyObject *_PyType_Lookup(PyTypeObject *to, PyObject *o) {
    return dl_python::get_instance().get<PyObject *(PyTypeObject *, PyObject *)>("_PyType_Lookup")(to, o);
}

PyTypeObject PyBaseObject_Type;

PyTypeObject PyCFunction_Type;

PyTypeObject PyCapsule_Type;

PyObject *PyExc_FutureWarning;

PyObject *PyExc_IndexError;

PyObject *PyExc_MemoryError;

PyObject *PyExc_RuntimeError;

PyObject *PyExc_SystemError;

PyObject *PyExc_TypeError;

PyObject *PyExc_ValueError;

PyTypeObject PyInstanceMethod_Type;

PyTypeObject PyProperty_Type;

PyTypeObject PyType_Type;

_longobject _Py_FalseStruct;

_longobject _Py_TrueStruct;

PyObject _Py_NoneStruct;

PyObject _Py_NotImplementedStruct;

PyObject *PyDict_GetItem(PyObject *p, PyObject *key) {
    return dl_python::get_instance().get<PyObject *(PyObject *, PyObject *)>("_PyType_Lookup")(p, key);
}

PyObject *PyErr_Format(PyObject *exception, const char *format, ...) {

}

PyObject *PyEval_GetGlobals(void) {
    return dl_python::get_instance().get<PyObject *(void)>("PyEval_GetGlobals")();
}

void PyEval_RestoreThread(PyThreadState *ts) {
    dl_python::get_instance().get<void(PyThreadState *)>("PyEval_RestoreThread")(ts);
}

PyTypeObject PyFloat_Type;

void PyFrame_FastToLocals(PyFrameObject *fo) {
    dl_python::get_instance().get<void(PyFrameObject *)>("PyFrame_FastToLocals")(fo);
}

int PyImport_AppendInittab(const char *name, PyObject *(*initfunc)(void)) {
    return dl_python::get_instance().get < int(
    const char *,PyObject *(*initfunc)(void))>("PyImport_AppendInittab")(name, initfunc);
}

PyObject *PyImport_ReloadModule(PyObject *m) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyImport_ReloadModule")(m);
}

PyObject *PyList_GetItem(PyObject *o, Py_ssize_t size) {
    return dl_python::get_instance().get<PyObject *(PyObject *, Py_ssize_t)>("PyList_GetItem")(o, size);
}

PyObject *PyList_New(Py_ssize_t len) {
    return dl_python::get_instance().get<PyObject *(Py_ssize_t)>("PyList_New")(len);
}

Py_ssize_t PyList_Size(PyObject *list) {
    return dl_python::get_instance().get<Py_ssize_t(PyObject *)>("PyList_Size")(list);
}

long PyLong_AsLong(PyObject *obj) {
    return dl_python::get_instance().get<long(PyObject *)>("PyLong_AsLong")(obj);
}

unsigned long PyLong_AsUnsignedLong(PyObject *pylong) {
    return dl_python::get_instance().get<unsigned long(PyObject *)>("PyLong_AsUnsignedLong")(pylong);
}

PyObject *PyLong_FromSsize_t(Py_ssize_t v) {
    return dl_python::get_instance().get<PyObject *(Py_ssize_t)>("PyLong_FromSsize_t")(v);
}

PyTypeObject PyMethod_Type;

int PyModule_AddObject(PyObject *module, const char *name, PyObject *value) {
    return dl_python::get_instance().get < int(PyObject * ,
    const char *,PyObject *)>("PyModule_AddObject")(module, name, value);
}

PyObject *PyModule_Create2(PyModuleDef *def, int module_api_version) {
    return dl_python::get_instance().get<PyObject *(PyModuleDef *, int)>("PyModule_Create2")(def, module_api_version);
}

PyTypeObject PyModule_Type;

void *PyObject_Malloc(size_t n) {
    return dl_python::get_instance().get<void *(size_t)>("PyObject_Malloc")(n);
}

int PyObject_SetAttr(PyObject *o, PyObject *attr_name, PyObject *v) {
    return dl_python::get_instance().get<int(PyObject *, PyObject *, PyObject *)>("PyObject_SetAttr")(o, attr_name, v);
}

PyObject *PyRun_StringFlags(const char *string, int i, PyObject *o1, PyObject *o2, PyCompilerFlags *cf) {
    return dl_python::get_instance().get < PyObject *(const char *, int, PyObject *, PyObject *,
            PyCompilerFlags *)>("PyRun_StringFlags")(string, i, o1, o2, cf);
}

PyObject *PySequence_Tuple(PyObject *o) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PySequence_Tuple")(o);
}

PyThreadState *PyThreadState_Swap(PyThreadState *tstate) {
    return dl_python::get_instance().get<PyThreadState *(PyThreadState *)>("PyThreadState_Swap")(tstate);
}

int PyType_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    return dl_python::get_instance().get<int(PyTypeObject *, PyTypeObject *)>("PyType_IsSubtype")(a, b);
}

PyObject *PyUnicode_FromFormat(const char *format, ...) {

}

void Py_EndInterpreter(PyThreadState *tstate) {
    dl_python::get_instance().get<void(PyThreadState *)>("Py_EndInterpreter")(tstate);
}

PyObject *PyNumber_Long(PyObject *o) {
    return dl_python::get_instance().get<PyObject *(PyObject *)>("PyNumber_Long")(o);
}

int PyNumber_Check(PyObject *o) {
    return dl_python::get_instance().get<int(PyObject *)>("PyNumber_Check")(o);
}

PyObject *PyExc_ImportError;

int PyErr_ExceptionMatches(PyObject *exc) {
    return dl_python::get_instance().get<int(PyObject *)>("PyErr_ExceptionMatches")(exc);
}

PyObject *PyExc_BufferError;

void init() {
    auto &python = dl_python::get_instance();

    PyBaseObject_Type = python.get<PyTypeObject>("PyBaseObject_Type");

    PyCFunction_Type = python.get<PyTypeObject>("PyCFunction_Type");

    PyCapsule_Type = python.get<PyTypeObject>("PyCapsule_Type");

    PyExc_FutureWarning = python.get<PyObject *>("PyExc_FutureWarning");

    PyExc_IndexError = python.get<PyObject *>("PyExc_IndexError");

    PyExc_MemoryError = python.get<PyObject *>("PyExc_MemoryError");

    PyExc_RuntimeError = python.get<PyObject *>("PyExc_RuntimeError");

    PyExc_SystemError = python.get<PyObject *>("PyExc_SystemError");

    PyExc_TypeError = python.get<PyObject *>("PyExc_TypeError");

    PyExc_ValueError = python.get<PyObject *>("PyExc_ValueError");

    PyInstanceMethod_Type = python.get<PyTypeObject>("PyInstanceMethod_Type");

    PyProperty_Type = python.get<PyTypeObject>("PyProperty_Type");

    PyType_Type = python.get<PyTypeObject>("PyType_Type");

    _Py_FalseStruct = python.get<_longobject>("_Py_FalseStruct");

    _Py_TrueStruct = python.get<_longobject>("_Py_TrueStruct");

    _Py_NoneStruct = python.get<PyObject>("_Py_NoneStruct");

    _Py_NotImplementedStruct = python.get<PyObject>("_Py_NotImplementedStruct");
    PyFloat_Type = python.get<PyTypeObject>("PyFloat_Type");
    PyMethod_Type = python.get<PyTypeObject>("PyMethod_Type");
    PyModule_Type= python.get<PyTypeObject>("PyModule_Type");
    PyExc_ImportError= python.get<PyObject *>("PyExc_ImportError");
    PyExc_BufferError = python.get<PyObject *>("PyExc_BufferError");
}

}