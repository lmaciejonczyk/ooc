#include <gtest/gtest.h>

#include "../src/String.h"
#include "../src/cnew.h"

TEST(StringTest, create) {
  const char* text = "a";
  struct String* a = (struct String*)cnew(String, text);

  EXPECT_EQ(a->cclass, String);
  EXPECT_EQ(strcmp(a->text, text), 0);

  cdelete(a);
}

TEST(StringTest, clone) {
  void* a = cnew(String, "string");
  void* b = cnew(String, "other string");
  void* c;
  void* d = clone(a);

  EXPECT_TRUE(differ(a, b));
  EXPECT_TRUE(differ(a, c));
  EXPECT_FALSE(differ(a, d));

  cdelete(a);
  cdelete(b);
  cdelete(d);
}

TEST(StringTest, atom) {
  void* a = cnew(String, "string");
  void* b = cnew(String, "string");

  EXPECT_EQ(a, b);
  EXPECT_FALSE(differ(a, b));

  void* c = cnew(String, "other string");
  EXPECT_NE(a, c);
  EXPECT_TRUE(differ(a, c));

  void* d = clone(a);
  EXPECT_EQ(a, d);
  EXPECT_FALSE(differ(a, d));

  cdelete(a);
  cdelete(b);
  cdelete(c);
  cdelete(d);
}
