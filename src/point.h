#ifndef POINT_H
#define POINT_H

struct Class;

struct Point {
  struct Class* cclass;
  int x;
  int y;
};

extern const void* Point;

#endif
