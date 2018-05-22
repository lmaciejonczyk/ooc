#include "cnew.h"

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>

void* cnew(const void* _class, ...) {
  const struct Class* cp = (const struct Class*)_class;
  void* p = calloc(1, cp->size);
  assert(p != NULL);

  *(const struct Class**)p = cp;

  if (cp->ctor != NULL) {
    va_list vl;
    va_start(vl, _class);
    p = cp->ctor(p, &vl);
    va_end(vl);
  }

  return p;
}

void* clone(const void* _class) {
  const struct Class* const* cp = (const struct Class* const*)_class;

  assert(*cp != NULL && (*cp)->clone != NULL);

  return (*cp)->clone(_class);
}

void cdelete(void* self) {
  const struct Class** cp = (const struct Class**)self;

  if (self != NULL && cp != NULL && (*cp)->dtor != NULL) {
    self = (*cp)->dtor(self);
  }

  free(self);
}

int differ(const void* lth, const void* rth) {
  const struct Class* const* cp = (const struct Class* const*)lth;

  assert(lth != NULL && *cp != NULL && (*cp)->differ != NULL);

  return (*cp)->differ(lth, rth);
}

char* draw(const void* _class) {
  const struct Class* const* cp = (const struct Class* const*)_class;

  assert(cp != NULL && (*cp)->draw != NULL);

  return (*cp)->draw(cp);
}
