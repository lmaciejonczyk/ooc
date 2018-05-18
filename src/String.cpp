#include "String.h"
#include "cnew.h"

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct String* ring;

void* String_ctor(void* _self, va_list* args) {
  struct String* self = (struct String*)_self;

  assert(self != NULL);

  const char* text = va_arg(*args, const char*);

  if (ring != NULL) {
    struct String* p = ring;
    do {
      if (strcmp(p->text, text) == 0) {
        p->count++;
        free(self);
        return p;
      }
    } while ((p = p->next) != ring);
  } else {
    ring = self;
  }

  self->next = ring->next, ring->next = self;
  self->count = 1;

  self->text = (char*)malloc(strlen(text) + 1);

  assert(self->text);

  strcpy(self->text, text);

  return self;
}

void* String_dtor(void* _self) {
  struct String* self = (struct String*)_self;

  if (--self->count > 0) {
    return 0;
  }

  free(self->text);
  self->text = 0;

  assert(ring);
  if (ring == self) {
    ring = self->next;
  }
  if (ring == self) {
    ring = NULL;
  } else {
    struct String* p = ring;
    while (p->next != self) {
      p = p->next;
      assert(p != ring);
    }
    p->next = self->next;
  }

  return self;
}

void* String_clone(const void* _self) {
  struct String* self = (struct String*)_self;
  self->count++;

  return self;
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
