#pragma once

#include "box2d.hpp"
#include <vector>

class Ray2D
{
public:
  Ray2D(Point2D const & origin, Point2D const & direction)
    : m_origin(origin), m_direction(direction)
  {
    NormalizeDirection();
  }

  bool operator == (Ray2D const & obj) const
  {
    return m_direction == obj.m_direction && m_origin == obj.m_origin;
  }

  bool operator != (Ray2D const & obj) const
  {
    return !operator==(obj);
  }

  Ray2D & operator = (Ray2D const & obj)
  {
    if (this == &obj) return *this;
    m_origin = obj.m_origin;
    m_direction = obj.m_direction;
    return *this;
  }

  Point2D const & origin() const
  {
    return m_origin;
  }

  Point2D const & direction() const
  {
    return m_direction;
  }

  bool Intersects(Box2D const & box) const
  {
    bool cross;
    double res;
    double min_x = box.boxMin().x();
    double max_x = box.boxMax().x();
    double min_y = box.boxMin().y();
    double max_y = box.boxMax().y();

    res = CrossXLevel(max_x, cross);
    if ( cross && ((res - min_y) * (res - max_y) <= 0))
      return true;

    res = CrossXLevel(min_x, cross);
    if ( cross && ((res - min_y) * (res - max_y) <= 0))
      return true;

    res = CrossYLevel(max_y, cross);
    if ( cross && ((res - min_x) * (res - max_x) <= 0))
      return true;

    res = CrossYLevel(min_y, cross);
    if ( cross && ((res - min_x) * (res - max_x) <= 0))
      return true;

    return false;
  }

  bool SetDirection(const Point2D & direction)
  {
    if (direction * direction > 0)
    {
      m_direction = direction;
      NormalizeDirection();
      return true;
    }
    return false;
  }

  void SetOrigin(const Point2D & origin)
  {
    m_origin = origin;
  }

protected:
  double CrossXLevel(double x, bool & cross) const
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

  double CrossYLevel(double y, bool & cross) const
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

  void NormalizeDirection()
  {
    m_direction /= sqrt(m_direction * m_direction);
  }

  Point2D m_origin;
  Point2D m_direction;
};