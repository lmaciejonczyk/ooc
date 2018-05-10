#include "../src/cnew.h"
#include "../src/set.h"

#include <gtest/gtest.h>

TEST(Set, cnew) {
  void *s = cnew(Set);
  ASSERT_NE(nullptr, s);

  cdelete(s);
}

TEST(Set, add) {
  void *my_set = cnew(Set);

  int element;
  void *p = add(my_set, &element);
  ASSERT_EQ(p, &element);
}
