#include "gtest/gtest.h"
#include "ray2d.hpp"

TEST(ray2d_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Point2D p1;
  Ray2D r1(p1, p1);
  EXPECT_EQ(r1.origin(), p1);
  EXPECT_EQ(r1.direction(), p1);


  // Тест на создание объекта с параметрами.
  Point2D p2 = { 1.2f, 2.4f };
  Ray2D r2(p1, p2);
  EXPECT_EQ(r2.origin(), p1);
  EXPECT_EQ(r2.direction(), p2);

  // Тест на создание копии объекта.
  Ray2D r3 = r2;
  EXPECT_EQ(r3, r2);
}

TEST(ray2d_test, test_intersection)
{
  Point2D p1 = { 0.0f, 0.0f };
  Point2D p2 = { 1.0f, 2.0f };
  Point2D p3 = { 2.0f, 3.0f };
  Point2D p4 = { -2.0f, 3.0f };
  Point2D p5 = { 1.0f, 6.0f };
  Point2D p6 = { 0.0f, 1.0f };
  Point2D p7 = { 1.0f, 0.0f };
  Ray2D r1(p1, p2);
  Ray2D r2(p1, p6);
  Ray2D r3(p4, p7);

  Box2D b1(-p2, p2);
  Box2D b2(p1, p2);
  Box2D b3(p2, p3);

  Box2D b4(-p3, -p2);
  Box2D b5(-p3, p1);
  Box2D b6(p4, p5);


  EXPECT_TRUE(r1.Intersects(b1));
  EXPECT_TRUE(r1.Intersects(b2));
  EXPECT_TRUE(r1.Intersects(b3));
  EXPECT_TRUE(r1.Intersects(b5));
  EXPECT_FALSE(r1.Intersects(b4));
  EXPECT_FALSE(r1.Intersects(b6));


  EXPECT_TRUE(r2.Intersects(b1));
  EXPECT_TRUE(r2.Intersects(b2));
  EXPECT_FALSE(r2.Intersects(b3));
  EXPECT_FALSE(r2.Intersects(b4));
  EXPECT_TRUE(r2.Intersects(b5));
  EXPECT_TRUE(r2.Intersects(b6));


  EXPECT_FALSE(r3.Intersects(b1));
  EXPECT_FALSE(r3.Intersects(b2));
  EXPECT_TRUE(r3.Intersects(b3));
  EXPECT_FALSE(r3.Intersects(b4));
  EXPECT_FALSE(r3.Intersects(b5));
  EXPECT_TRUE(r3.Intersects(b6));

}