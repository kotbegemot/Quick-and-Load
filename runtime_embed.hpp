#pragma once

#include <boost/dll/import.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include "pybind11/pybind11.h"
#include "pybind11/eval.h"

namespace dll = boost::dll;

namespace pybind11 {

    class scoped_interpreter final {
    public:
        scoped_interpreter(boost::filesystem::path so_vm, bool init_signal_handlers = true)
                : lib(so_vm, dll::load_mode::append_decorations) {
            initialize_interpreter(init_signal_handlers);
        }

        scoped_interpreter(const scoped_interpreter &) = delete;

        scoped_interpreter(scoped_interpreter &&other) noexcept { other.is_valid = false; }

        scoped_interpreter &operator=(const scoped_interpreter &) = delete;

        scoped_interpreter &operator=(scoped_interpreter &&) = delete;

        ~scoped_interpreter() {
            if (is_valid)
                finalize_interpreter();
        }

    private:
        void initialize_interpreter(bool init_signal_handlers = true) {
            if (Py_IsInitialized())
                pybind11_fail("The interpreter is already running");

            Py_InitializeEx(init_signal_handlers ? 1 : 0);

            // Make .py files in the working directory available by default
            pybind11::module::import("sys").attr("path").cast<pybind11::list>().append(".");
        }


        void finalize_interpreter() {
            pybind11::handle builtins(PyEval_GetBuiltins());
            const char *id = PYBIND11_INTERNALS_ID;

            pybind11::detail::internals **internals_ptr_ptr = pybind11::detail::get_internals_pp();

            if (builtins.contains(id) && isinstance<pybind11::capsule>(builtins[id]))
                internals_ptr_ptr = capsule(builtins[id]);

            Py_Finalize();

            if (internals_ptr_ptr) {
                delete *internals_ptr_ptr;
                *internals_ptr_ptr = nullptr;
            }
        }

        dll::shared_library lib;
        bool is_valid = true;
    };
}



