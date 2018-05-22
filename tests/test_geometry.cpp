#include <gtest/gtest.h>

#include "../src/circle.h"
#include "../src/cnew.h"
#include "../src/point.h"

TEST(GeometryTest, draw) {
  void* point = cnew(Point, 1, 2);
  void* circle = cnew(Circle, 4, 5, 10);

  EXPECT_STREQ("'.' at 1,2", draw(point));
  EXPECT_STREQ("circle at 4,5 rad 10", draw(circle));

  cdelete(point);
  cdelete(circle);
}

TEST(GeometryTest, move) {
  void* point = cnew(Point, 1, 2);
  void* circle = cnew(Circle, 3, 5, 9);

  EXPECT_STREQ("'.' at 1,2", draw(point));
  EXPECT_STREQ("circle at 3,5 rad 9", draw(circle));

  move(point, 10, 15);
  EXPECT_STREQ("'.' at 11,17", draw(point));

  move(circle, 12, 10);
  EXPECT_STREQ("circle at 15,15 rad 9", draw(circle));

  cdelete(point);
  cdelete(circle);
}
