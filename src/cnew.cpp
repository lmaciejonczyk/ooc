#include "set.h"

#include <stdlib.h>

void* cnew(const void* type, ...) {
  void* p;
  if (type == Set) {
    p = new_set();
  }

  return p;
}

void cdelete(void* item) { free(item); }
