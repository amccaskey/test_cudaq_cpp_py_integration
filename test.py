import cudaq_cpp_py_int_ex 
import cudaq 

@cudaq.kernel 
def prep(q : cudaq.qvector):
    for qq in q:
        x(qq)

prep.compile()

cudaq_cpp_py_int_ex.quantum_sampling_algo(prep)