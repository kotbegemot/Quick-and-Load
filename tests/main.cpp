#ifdef _MSC_VER
// Silence MSVC C++17 deprecation warning from Catch regarding std::uncaught_exceptions (up to catch
// 2.0.1; this should be fixed in the next catch release after 2.0.1).
#  pragma warning(disable: 4996)
#endif

#define CATCH_CONFIG_RUNNER
#include <pybind11/embed.h>
#include "dl_python.hpp"
#include <catch.hpp>

namespace py = pybind11;

std::unique_ptr<dl_python::storage> dl_python::instance_;
std::once_flag dl_python::once_;

int main(int argc, char *argv[]) {
    dl_python::constructor("/usr/local/opt/python@3.8/Frameworks/Python.framework/Versions/3.8/lib/libpython3.8.dylib");
    init();
    py::scoped_interpreter guard{};
    auto result = Catch::Session().run(argc, argv);
    return result < 0xff ? result : 0xff;
}