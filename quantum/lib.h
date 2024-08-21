#include "cudaq.h"

void kernel_to_sample(const std::function<void(cudaq::qvector<>&)> &prep);