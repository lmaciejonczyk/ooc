#include "point.h"
#include "cnew.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

void* Point_ctor(void* _self, va_list* args) {
  struct Point* self = (struct Point*)_self;

  self->x = va_arg(*args, int);
  self->y = va_arg(*args, int);

  return (void*)self;
}

char* Point_draw(const void* _self) {
  static char draw_str[20];

  const struct Point* self = (const struct Point*)_self;

  sprintf(draw_str, "'.' at %d,%d", self->x, self->y);

  return draw_str;
}

static const struct Class _Point = {
    sizeof(struct Point), Point_ctor, NULL, NULL, NULL, Point_draw};

const void* Point = (const void*)&_Point;

void move(void* _class, int dx, int dy) {
  struct Point* self = (struct Point*)_class;

  assert(self != NULL);

  self->x += dx;
  self->y += dy;
}
