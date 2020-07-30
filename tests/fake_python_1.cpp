#include "dl_python.hpp"
class PyObject;

extern "C" {

void _Py_Dealloc(PyObject* o){
    return dl_python::get_instance().get<void(PyObject*)>("_Py_Dealloc")(o);
}

}