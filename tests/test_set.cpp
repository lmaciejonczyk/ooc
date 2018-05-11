#include "../src/set.h"

#include <gtest/gtest.h>

class SetTest : public ::testing::Test {
 protected:
  void SetUp() override {
    _set = cnew(Set);
    _elementA = cnew(Object);
    _elementB = cnew(Object);
  }

  void TearDown() override {
    cdelete(_elementB);
    cdelete(_elementA);
    cdelete(_set);
  }

  void *_set;
  void *_elementA;
  void *_elementB;
};

TEST_F(SetTest, cnew) { ASSERT_NE(nullptr, _set); }

TEST_F(SetTest, add) {
  void *element = add(_set, _elementA);
  EXPECT_TRUE(contains(_set, element));
  EXPECT_FALSE(contains(_set, _elementB));
}

TEST_F(SetTest, find) {
  void *element = add(_set, _elementA);
  EXPECT_EQ(find(_set, element), element);
}

TEST_F(SetTest, drop) {
  void *elementA = add(_set, _elementA);
  void *elementB = add(_set, _elementB);
  add(_set, _elementB);

  void *dropElement = drop(_set, elementA);
  EXPECT_EQ(dropElement, elementA);
  EXPECT_FALSE(contains(_set, elementA));
  EXPECT_TRUE(contains(_set, elementB));

  drop(_set, _elementB);
  EXPECT_TRUE(contains(_set, _elementB));
  drop(_set, _elementB);
  EXPECT_FALSE(contains(_set, _elementB));
}

TEST_F(SetTest, count) {
  EXPECT_EQ(count(_set), 0);
  add(_set, _elementA);
  add(_set, _elementB);
  EXPECT_EQ(count(_set), 2);
}
