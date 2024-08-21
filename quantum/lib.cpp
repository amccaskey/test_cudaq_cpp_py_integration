#include "lib.h"

__qpu__ void kernel_to_sample(const std::function<void(cudaq::qvector<>&)> &prep) {
  cudaq::qvector q(2);
  prep(q);
}