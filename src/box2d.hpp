#pragma once

#include "point2d.hpp"

class Box2D
{
public:
  Box2D(Point2D const & p1, Point2D const & p2)
  {
    m_boxMin = {
      std::min(p1.x(), p2.x()),
      std::min(p1.y(), p2.y())
    };
    m_boxMax = {
      std::max(p1.x(), p2.x()),
      std::max(p1.y(), p2.y())
    };
  }

  Box2D(Box2D const & other)
  {
    m_boxMax = other.m_boxMax;
    m_boxMin = other.m_boxMin;
  }

  Box2D(Box2D && other)
  {
    std::swap(other.m_boxMax, m_boxMax);
    std::swap(other.m_boxMin, m_boxMin);
  }

  Box2D & operator = (Box2D const & obj)
  {
    if (this == &obj) return *this;
    m_boxMin = obj.m_boxMin;
    m_boxMax = obj.m_boxMax;
    return *this;
  }

  Box2D & operator = (Box2D && obj)
  {
    std::swap(m_boxMin, obj.m_boxMin);
    std::swap(m_boxMax, obj.m_boxMax);
    return *this;
  }

  bool operator==(Box2D const & other) const
  {
    return other.m_boxMax == m_boxMax && other.m_boxMin == m_boxMin;
  }

  bool Intersects(Box2D const & box) const
  {
    if (m_boxMax.x() < box.m_boxMin.x()) return false;
    if (m_boxMin.x() > box.m_boxMax.x()) return false;
    if (m_boxMax.y() < box.m_boxMin.y()) return false;
    if (m_boxMin.y() > box.m_boxMax.y()) return false;
    return true;
  }

  Point2D const & boxMin() const { return m_boxMin; }
  Point2D const & boxMax() const { return m_boxMax; }

private:
  Point2D m_boxMin, m_boxMax;
};
