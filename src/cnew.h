#ifndef CNEW_h
#define CNEW_h

#include <stdarg.h>
#include <stddef.h>

struct Class {
  size_t size;
  void* (*ctor)(void* self, va_list* args);
  void* (*dtor)(void* self);
  void* (*clone)(const void* self);
  int (*differ)(const void* self, const void* other);
};

void* cnew(const void* _class, ...);
void* clone(const void* _class);
void cdelete(void* item);
int differ(const void* lth, const void* rth);

#endif
