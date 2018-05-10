#include <assert.h>
#include <stdlib.h>

#define SET_SIZE 10

int _Set;
void* Set = &_Set;

void* new_set(...) {
  void* p = calloc(SET_SIZE, sizeof(int));
  assert(p != NULL);

  return p;
}

void* add(void* set, void* element) {
  void* p = set;
  for (p = set; p < set + SET_SIZE; p++) {
    if (*p == NULL) {
      break;
    }
  }

  assert(p < set + SET_SIZE);
  p = element;

  return p;
}
