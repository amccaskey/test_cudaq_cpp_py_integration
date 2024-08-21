# cmake .. -G Ninja -DCUDAQ_DIR=/path/to/cudaq/lib/cmake/cudaq 
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

find_package(CUDAQ CONFIG REQUIRED) 

project(cudaq_cpp_python_integration_example)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11
  GIT_TAG        v2.13
)

FetchContent_GetProperties(pybind11)
if(NOT pybind11_POPULATED)
  FetchContent_Populate(pybind11)
  add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()

add_subdirectory(quantum)

pybind11_add_module(cudaq_cpp_py_int_ex bindings.cpp)
target_link_libraries(cudaq_cpp_py_int_ex PRIVATE cudaq::cudaq device_lib)
