#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "IShape.hpp"
#include "Vector.hpp"

/*
 * Triangle shape class; subclass of IShape.
 *
 * Should not be possible to copy or assign.
 *
 * For Triangle:
 *  o->display(os): should display "Triangle(x0 y0; x1 y1; x2 y2)" (with actual member values)
 */
class Triangle /* TODO */ {
public:
  // TODO

private:
  // TODO

  Vector * m_points; // pointer to dynamic length-three array containing points
};

#endif
