#include <stdarg.h>
#include <stdio.h>
#include "cnew.h"
#include "point.h"

struct Circle {
  struct Point _point;
  unsigned int rad;
};

void* Circle_ctor(void* _self, va_list* args) {
  struct Circle* self =
      (struct Circle*)((struct Class*)Point)->ctor(_self, args);

  self->rad = va_arg(*args, unsigned int);

  return (void*)self;
}

char* Circle_draw(const void* _self) {
  static char draw_str[30];
  const struct Circle* self = (const struct Circle*)_self;

  sprintf(draw_str, "circle at %d,%d rad %d", self->_point.x, self->_point.y,
          self->rad);

  return draw_str;
}

static const struct Class _Circle = {
    sizeof(struct Circle), Circle_ctor, NULL, NULL, NULL, Circle_draw};

const void* Circle = &_Circle;
