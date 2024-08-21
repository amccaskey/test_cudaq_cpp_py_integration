#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include "quantum/lib.h"

namespace py = pybind11;

PYBIND11_MODULE(cudaq_cpp_py_int_ex, mod) {
  mod.doc() = "Test that one can call a python cuda-q kernel from c++.";

  mod.def("quantum_sampling_algo", [](py::function kernel) {
    cudaq::sample(kernel_to_sample, kernel /*how to do this?*/).dump();
  });
}