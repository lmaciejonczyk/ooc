#include <assert.h>
#include <stdlib.h>

#define MANY 10

int _Set;
int _Object;
void* Set = &_Set;
void* Object = &_Object;

static int heap[MANY];

void* cnew(const void* type, ...) {
  int* p;
  for (p = heap + 1; p < heap + MANY; p++) {
    if (*p == 0) {
      break;
    }
  }

  assert(p < heap + MANY);
  *p = MANY;

  return p;
}

void cdelete(void* _item) {
  int* item = (int*)_item;

  if (item > heap && item < heap + MANY) {
    *item = 0;
  }
}

void* add(void* _set, const void* _element) {
  int* set = (int*)_set;
  int* element = (int*)_element;

  assert(set > heap && set < heap + MANY);
  assert(*set == MANY);
  assert(element > heap && element < heap + MANY);

  if (*element == MANY) {
    *element = set - heap;
  } else {
    assert(*element == set - heap);
  }

  return (void*)element;
}

void* find(const void* _set, const void* _element) {
  const int* set = (const int*)_set;
  const int* element = (const int*)_element;

  assert(set > heap && set < heap + MANY);
  assert(element > heap && element < heap + MANY);

  return *element > 0 && *element < MANY ? (void*)element : NULL;
}

int contains(const void* _set, const void* _element) {
  return find(_set, _element) != NULL;
}

void* drop(void* _set, const void* _element) {
  int* element = (int*)find(_set, _element);
  if (element != NULL) {
    *element = MANY;
  }
}
