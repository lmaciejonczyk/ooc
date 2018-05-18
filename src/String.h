#ifndef STRING_H
#define STRING_H

struct String {
  struct Class* cclass;
  char* text;
  struct String* next;
  unsigned int count;
};

extern const void* String;

#endif
