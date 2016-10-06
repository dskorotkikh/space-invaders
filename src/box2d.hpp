#pragma once

#include "point2d.hpp"

class Box2D
{
public:
  Box2D(const Point2D& p1, const Point2D& p2)
          : m_p1(p1), m_p2(p2)
  {}

  bool Intersects(const Box2D& box)
  {
    Point2D l1, r1, l2, r2;
    // Defining left and right points of the boxes
    l1 = (p1() > p2()) ? p2() : p1();
    r1 = (p1() > p2()) ? p1() : p2();
    l2 = (box.p1() > box.p2()) ? box.p2() : box.p1();
    r2 = (box.p1() > box.p2()) ? box.p1() : box.p2();
    return !((l1.x() > r2.x()) || (r1.x() < l2.x()) ||
             std::max(l2.y(),r2.y()) < std::min(l1.y(),r1.y()) ||
             std::max(l1.y(),r1.y()) < std::min(l2.y(),r2.y()));
  }

  Point2D & p1() { return m_p1; }
  Point2D & p2() { return m_p2; }

  Point2D const & p1() const { return m_p1; }
  Point2D const & p2() const { return m_p2; }

private:
  Point2D m_p1, m_p2;
};
