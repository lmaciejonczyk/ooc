#ifndef SET_H
#define SET_H

extern const void *Set;
extern const void *Object;

void *add(void *_set, const void *_element);
void *find(const void *_set, const void *_element);
void *drop(void *_set, const void *_element);
int contains(const void *_set, const void *_element);
unsigned int count(const void *_set);

void *cnew(const void *type, ...);
void cdelete(void *item);

#endif
