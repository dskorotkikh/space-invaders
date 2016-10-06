#pragma once

#include "box2d.hpp"
#include <vector>

class Ray2D
{
public:
  Ray2D(Point2D const & origin, Point2D const & direction)
          : m_origin(origin), m_direction(direction)
  {}

  bool operator == (Ray2D const & obj) const {
    return m_direction == obj.m_direction && m_origin == obj.m_origin;
  }

  Ray2D & operator = (Ray2D const & obj)
  {
    if (this == &obj) return *this;
    m_origin = obj.m_origin;
    m_direction = obj.m_direction;
    return *this;
  }

  bool operator != (Ray2D const & obj) const
  {
    return !operator==(obj);
  }

  Point2D& origin() { return m_origin; }

  Point2D& direction() { return m_direction; }

  bool Intersects(const Box2D& box)
  {
    bool cross;
    double res;
    double min_x = box.p1().x();
    double max_x = box.p2().x();

    double min_y = box.p1().y();
    double max_y = box.p2().y();

    res = crossXLevel(max_x, cross);
    if ( cross && ((res - min_y) * (res - max_y) <= 0))
      return true;

    res = crossXLevel(min_x, cross);
    if ( cross && ((res - min_y) * (res - max_y) <= 0))
      return true;

    res = crossYLevel(max_y, cross);
    if ( cross && ((res - min_x) * (res - max_x) <= 0))
      return true;

    res = crossYLevel(min_y, cross);
    if ( cross && ((res - min_x) * (res - max_x) <= 0))
      return true;


    return false;
  }

protected:
  double crossXLevel(double x, bool& cross)
  {
    if (m_direction.x() != 0)
    {
      if ((x - m_origin.x()) * m_direction.x() >= 0)
      {
        cross = true;
        return m_origin.y() + (x - m_origin.x()) * m_direction.y() / m_direction.x();
      }
    }
    else
    {
      cross = m_origin.x() == x;
      return m_origin.y();
    }
    cross = false;
    return 0;
  }

  double  crossYLevel(double y, bool& cross)
  {
    if (m_direction.y() != 0)
    {
      if ((y - m_origin.y()) * m_direction.y() >= 0)
      {
        cross = true;
        return m_origin.x() + (y - m_origin.y()) * m_direction.x() / m_direction.y();
      }
    }
    else
    {
      cross = m_origin.y() == y;
      return m_origin.x();
    }
    cross = false;
    return 0;
  }
private:

  Point2D m_origin;
  Point2D m_direction;
};