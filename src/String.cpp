#include "String.h"
#include "cnew.h"

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void* String_ctor(void* _self, va_list* args) {
  struct String* self = (struct String*)_self;

  assert(self != NULL);

  const char* text = va_arg(*args, const char*);
  self->text = (char*)malloc(strlen(text) + 1);

  assert(self->text);

  strcpy(self->text, text);

  return self;
}

void* String_dtor(void* _self) {
  struct String* self = (struct String*)_self;

  free(self->text);
  self->text = 0;

  return self;
}

void* String_clone(const void* _self) {
  const struct String* self = (const struct String*)_self;
  return cnew(String, self->text);
}

int String_differ(const void* _self, const void* _other) {
  const struct String* self = (const struct String*)_self;
  const struct String* other = (const struct String*)_other;

  if (self == other) {
    return 0;
  }

  if (other == NULL || other->cclass != String) {
    return 1;
  }

  return strcmp(self->text, other->text);
}

static const struct Class _String = {sizeof(struct String), String_ctor,
                                     String_dtor, String_clone, String_differ};

const void* String = (const void*)&_String;
