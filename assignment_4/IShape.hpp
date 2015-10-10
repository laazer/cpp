#ifndef _ISHAPE_HPP_
#define _ISHAPE_HPP_

#include "Vector.hpp"
#include <iostream>

/*
 * Interface for a polymorphic shape.
 *
 * Should not be possible to instatiate, copy, or assign.  All member functions
 * must be overridden by subclasses.
 *
 * Given IShape * o, Vector v, std::ostream os, the following should be defined:
 *  o->display(os): streams shape description to given stream
 *  o->getArea(): returns area of the shape as a double
 *  o->translate(v): translates shape by v
 */
class IShape {
public:
  // TODO

private:
  // TODO

};

#endif
