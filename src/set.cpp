#include <assert.h>
#include <stdlib.h>

#define MANY 10

struct Set {
  unsigned int count;
};

struct Object {
  unsigned int count;
  struct Set* in;
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void* Set = &_Set;
const void* Object = &_Object;

static int heap[MANY];

void* cnew(const void* type, ...) {
  const size_t size = *(const size_t*)type;
  void* p = calloc(1, size);
  assert(p != NULL);

  return p;
}

void cdelete(void* _item) { free(_item); }

void* add(void* _set, const void* _element) {
  struct Set* set = (struct Set*)_set;
  struct Object* element = (struct Object*)_element;

  assert(set != NULL);
  assert(element != NULL);

  if (element->in == NULL) {
    element->in = set;
  } else {
    assert(element->in == set);
  }

  element->count++;
  set->count++;

  return (void*)element;
}

void* find(const void* _set, const void* _element) {
  const struct Set* set = (const struct Set*)_set;
  const struct Object* element = (const struct Object*)_element;

  assert(set != NULL);
  assert(element != NULL);

  return element->in == set ? (void*)element : NULL;
}

int contains(const void* _set, const void* _element) {
  return find(_set, _element) != NULL;
}

void* drop(void* _set, const void* _element) {
  struct Set* set = (struct Set*)_set;
  struct Object* element = (struct Object*)find(_set, _element);

  if (element != NULL) {
    if (--element->count == 0) {
      element->in = NULL;
    }
    set->count--;
  }

  return element;
}

unsigned int count(const void* _set) {
  struct Set* set = (struct Set*)_set;
  assert(set != NULL);

  return set->count;
}
