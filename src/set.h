#ifndef SET_H
#define SET_H

extern const void *Set;

void *add(void *set, const void *element);
void *find(void *set, const void *element);
void *drop(void *set, const void *element);
int contain(void *set, const void *element);

void *new_set(...);

#endif
