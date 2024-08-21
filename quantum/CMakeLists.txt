
# FIXME: We cannot yet compile directly with nvq++ due to 
# transitive linking with cudaq-builder and cudaq-mlir-runtime. This 
# ends up getting linked with our Python module and causing the 
# static initialization problems. 
set(CMAKE_CXX_COMPILER "${CUDAQ_INSTALL_DIR}/bin/nvq++")
set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> --enable-mlir -g -fPIC <DEFINES> <INCLUDES> -o <OBJECT> -c <SOURCE>")
add_library(device_lib SHARED lib.cpp)

