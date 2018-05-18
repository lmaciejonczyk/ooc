#ifndef STRING_H
#define STRING_H

struct String {
  struct Class* cclass;
  char* text;
};

extern const void* String;

#endif
