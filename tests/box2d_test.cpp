#include "gtest/gtest.h"
#include "box2d.hpp"

TEST(box2d_test, test_construction)
{
  Point2D p1;
  Point2D p2 = {-1.0f, -1.0f};
  Box2D b1(p1, p2);

  EXPECT_EQ(b1.p1(), p1);
  EXPECT_EQ(b1.p2(), p2);
  EXPECT_NE(b1.p1(), p2);
  EXPECT_NE(b1.p2(), p1);
}

TEST(box2d_test, test_intersection)
{
  Point2D p1;
  Point2D p2 = {-1.0f, -1.0f};
  Point2D p3 = { 1.0f,  1.0f};
  Point2D p4 = { 1.0f, -1.0f};
  Point2D p5 = p2*2;
  Point2D p6 = p3*2;

  Point2D p7 = { 10.0f, 10.0f};
  Point2D p8 = { 12.0f, 12.0f};


  Box2D b1(p1, p3);
  Box2D b2(p2, p3);
  Box2D b3(p2, p1);
  Box2D b4(p5, p6);
  Box2D b5(p7, p8);

  EXPECT_TRUE(b1.Intersects(b2));
  EXPECT_TRUE(b2.Intersects(b1));
  EXPECT_TRUE(b3.Intersects(b2));
  EXPECT_TRUE(b2.Intersects(b3));
  EXPECT_TRUE(b4.Intersects(b1));
  EXPECT_TRUE(b4.Intersects(b2));
  EXPECT_TRUE(b4.Intersects(b3));
  EXPECT_TRUE(b1.Intersects(b4));
  EXPECT_TRUE(b2.Intersects(b4));
  EXPECT_TRUE(b3.Intersects(b4));

  EXPECT_FALSE(b1.Intersects(b5));
  EXPECT_FALSE(b2.Intersects(b5));
  EXPECT_FALSE(b3.Intersects(b5));
  EXPECT_FALSE(b4.Intersects(b5));
  EXPECT_FALSE(b5.Intersects(b1));
  EXPECT_FALSE(b5.Intersects(b2));
  EXPECT_FALSE(b5.Intersects(b3));
  EXPECT_FALSE(b5.Intersects(b4));

}