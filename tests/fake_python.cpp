#include "dl_python.hpp"

#include <Python.h>
#include <frameobject.h>

extern "C" {

int Py_IsInitialized() {
    return dl_python::get_instance().get<int(void)>("Py_IsInitialized")();
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
    return dl_python::get_instance().get<PyObject *(PyObject *, PyObject *)>("PyWeakref_NewRef")(ob,callback);
}

void PyBuffer_Release(Py_buffer *view) {
    return dl_python::get_instance().get<void(Py_buffer*)>("PyBuffer_Release")(view);
}

char* PyBytes_AsString(PyObject *o) {
    return dl_python::get_instance().get<char *(PyObject*)>("PyBytes_AsString")(o);
}

int PyBytes_AsStringAndSize(PyObject *obj, char **buffer, Py_ssize_t *length) {
    return dl_python::get_instance().get<int(PyObject *, char **, Py_ssize_t *)>("PyBytes_AsString")(obj,buffer,length);
}

Py_ssize_t PyBytes_Size(PyObject *o) {
    return dl_python::get_instance().get<Py_ssize_t(PyObject*)>("PyBytes_AsString")(o);
}

PyObject *PyCFunction_NewEx(PyMethodDef *ml, PyObject *self, PyObject *module) {

}

void *PyCapsule_GetContext(PyObject *o) {

}

const char *PyCapsule_GetName(PyObject *o) {

}

void *PyCapsule_GetPointer(PyObject *o, const char *name) {

}

PyObject *PyCapsule_New(void *pointer, const char *name, PyCapsule_Destructor destructor) {

}

int PyCapsule_SetContext(PyObject *o, void *context) {

}

int PyDict_Contains(PyObject *op, PyObject *key) {

}

PyObject *PyDict_Copy(PyObject *o) {

}

int PyDict_DelItemString(PyObject *v, const char *key) {

}

PyObject *PyDict_GetItemString(PyObject *v, const char *key) {}

PyObject *PyDict_New(void) {}

int PyDict_Next(PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value) {

}

Py_ssize_t PyDict_Size(PyObject *mp) {}

void PyErr_Clear(void) {

}

void PyErr_Fetch(PyObject **, PyObject **, PyObject **) {

}

void PyErr_NormalizeException(PyObject **, PyObject **, PyObject **) {

}

PyObject *PyErr_Occurred(void) {

}

void PyErr_Restore(PyObject *, PyObject *, PyObject *) {

}

void PyErr_SetString(
        PyObject *exception,
        const char *string   /* decoded from utf-8 */
) {

}

int PyErr_WarnEx(PyObject *category, const char *text, Py_ssize_t stack_level) {

}

void PyEval_AcquireThread(PyThreadState *tstate) {

}

PyObject *PyEval_GetBuiltins(void) {

}

void PyEval_InitThreads(void) {

}

PyThreadState *PyEval_SaveThread(void) {

}

PyThreadState *PyGILState_GetThisThreadState(void) {

}

PyObject *PyImport_ImportModule(const char *name /* UTF-8 encoded string */) {

}

PyObject *PyInstanceMethod_New(PyObject *) {

}

int PyList_Append(PyObject *, PyObject *) {

}

void *PyMem_Calloc(size_t nelem, size_t elsize) {

}

void PyMem_Free(void *ptr) {

}

PyObject *PyObject_CallObject(PyObject *callable, PyObject *args) {

}

void PyObject_ClearWeakRefs(PyObject *object) {}

PyObject *PyObject_GetAttrString(PyObject *, const char *) {}

PyObject *PyObject_GetItem(PyObject *o, PyObject *key) {}

int PyObject_HasAttrString(PyObject *, const char *) {}

int PyObject_IsInstance(PyObject *object, PyObject *typeorclass) {}

PyObject *PyObject_Repr(PyObject *v) {}

int PyObject_SetAttrString(PyObject *, const char *, PyObject *) {}

Py_tss_t *PyThread_tss_alloc(void) {}
void PyThread_tss_free(Py_tss_t *key) {}
int PyThread_tss_is_created(Py_tss_t *key) {}
int PyThread_tss_create(Py_tss_t *key) {}
void PyThread_tss_delete(Py_tss_t *key) {}
int PyThread_tss_set(Py_tss_t *key, void *value) {}
void *PyThread_tss_get(Py_tss_t *key) {}
void PyThreadState_Clear(PyThreadState *) {}
void PyThreadState_DeleteCurrent(void) {}
PyThreadState *PyThreadState_Get(void) {}
PyThreadState *PyThreadState_New(PyInterpreterState *) {}

int PyException_SetTraceback(PyObject *, PyObject *){}
int PyObject_SetItem(PyObject *o, PyObject *key, PyObject *value){}
PyObject * PyObject_Str(PyObject *v){}
PyObject * PySequence_List(PyObject *v){}
PyObject * PyTuple_GetItem(PyObject *, Py_ssize_t){}
PyObject * PyTuple_New(Py_ssize_t size){}
int PyTuple_SetItem(PyObject *, Py_ssize_t, PyObject *){}
Py_ssize_t PyTuple_Size(PyObject *){}
int PyType_Ready(PyTypeObject *type){}
PyObject* PyUnicode_AsEncodedString(
        PyObject *unicode,          /* Unicode object */
const char *encoding,       /* encoding */
const char *errors          /* error handling */
){}

PyObject* PyUnicode_AsUTF8String(
        PyObject *unicode           /* Unicode object */
){}

PyObject* PyUnicode_DecodeUTF8(
        const char *string,         /* UTF-8 encoded string */
        Py_ssize_t length,          /* size of string */
        const char *errors          /* error handling */
){}

PyObject* PyUnicode_FromString(const char *u              /* UTF-8 encoded string */){

}

int PyFrame_GetLineNumber(PyFrameObject *){}

PyObject ** _PyObject_GetDictPtr(PyObject *obj){}

PyThreadState * _PyThreadState_UncheckedGet(void){}

PyObject * _PyType_Lookup(PyTypeObject *, PyObject *){}


PyTypeObject PyBaseObject_Type;

PyTypeObject PyCFunction_Type;

PyTypeObject PyCapsule_Type;

PyObject * PyExc_FutureWarning;

PyObject * PyExc_IndexError;

PyObject * PyExc_MemoryError;

PyObject * PyExc_RuntimeError;

PyObject * PyExc_SystemError;

PyObject * PyExc_TypeError;

PyObject * PyExc_ValueError;

PyTypeObject PyInstanceMethod_Type;

PyTypeObject PyProperty_Type;

PyTypeObject PyType_Type;

_longobject _Py_FalseStruct;

_longobject _Py_TrueStruct;

PyObject _Py_NoneStruct;

PyObject _Py_NotImplementedStruct;

PyObject* PyDict_GetItem(PyObject *p, PyObject *key){

}

PyObject* PyErr_Format(PyObject *exception, const char *format, ...){

}

PyObject* PyEval_GetGlobals(void){

}

void PyEval_RestoreThread(PyThreadState *){

}

PyTypeObject PyFloat_Type;

void PyFrame_FastToLocals(PyFrameObject *){

}

int PyImport_AppendInittab(const char *name, PyObject* (*initfunc)(void)) {

}

PyObject* PyImport_ReloadModule(PyObject *m) {

}

PyObject* PyList_GetItem(PyObject *, Py_ssize_t){

}

PyObject* PyList_New(Py_ssize_t len){

}

Py_ssize_t PyList_Size(PyObject *list){

}

long PyLong_AsLong(PyObject *obj){

}

unsigned long PyLong_AsUnsignedLong(PyObject *pylong) {

}

PyObject* PyLong_FromSsize_t(Py_ssize_t v){

}

PyTypeObject PyMethod_Type;

int PyModule_AddObject(PyObject *module, const char *name, PyObject *value){

}

PyObject* PyModule_Create2(PyModuleDef *def, int module_api_version){

}

PyTypeObject PyModule_Type;

void* PyObject_Malloc(size_t n){

}

int PyObject_SetAttr(PyObject *o, PyObject *attr_name, PyObject *v){

}

PyObject * PyRun_StringFlags(const char *, int, PyObject *,
                              PyObject *, PyCompilerFlags *){

}

PyObject* PySequence_Tuple(PyObject *o){

}

PyThreadState* PyThreadState_Swap(PyThreadState *tstate){

}

int PyType_IsSubtype(PyTypeObject *a, PyTypeObject *b) {

}

PyObject* PyUnicode_FromFormat(const char *format, ...){

}

void Py_EndInterpreter(PyThreadState *tstate){

}

PyObject* PyNumber_Long(PyObject *o){

}

int PyNumber_Check(PyObject *o){

}

PyObject * PyExc_ImportError;

int PyErr_ExceptionMatches(PyObject *exc){

}

PyObject * PyExc_BufferError;

}