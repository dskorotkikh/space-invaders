#pragma once

#include "point2d.hpp"

class Box2D
{
public:
  Box2D(const Point2D & p1, const Point2D & p2)
  {
    m_BoxMin = {
      std::min(p1.x(), p2.x()),
      std::min(p1.y(), p2.y())
    };
    m_BoxMax = {
      std::max(p1.x(), p2.x()),
      std::max(p1.y(), p2.y())
    };
  }

  bool Intersects(const Box2D & box) const
  {
    if (m_BoxMax.x() < box.m_BoxMin.x()) return false;
    if (m_BoxMin.x() > box.m_BoxMax.x()) return false;
    if (m_BoxMax.y() < box.m_BoxMin.y()) return false;
    if (m_BoxMin.y() > box.m_BoxMax.y()) return false;
    return true;
  }

  Point2D const & boxMin() const { return m_BoxMin; }
  Point2D const & boxMax() const { return m_BoxMax; }

private:
  Point2D m_BoxMin, m_BoxMax;
};
