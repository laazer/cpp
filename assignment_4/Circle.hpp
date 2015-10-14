#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "IShape.hpp"
#include "Vector.hpp"

/*
 * Circle shape class; subclass of IShape.
 *
 * Should not be possible to copy or assign.
 *
 * For Circle:
 *  o->display(os): should display "Circle(cx cy; radius)" (with actual member values)
 */
class Circle /* TODO */ {
public:
  // TODO

private:
  // TODO

  Vector m_center; // center point of circle
  double m_radius; // radius of circle
};

#endif