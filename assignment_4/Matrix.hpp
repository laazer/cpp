#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include "Vector.hpp"
#include <iostream>

/*
 * Class representing a 2D matrix with elements xx, xy, yx and yy.
 *
 * Given Matrix m, Vector v, size_t i, double d, the following should be defined:
 *  Matrix(d1, d2, d3, d4): initializes xx to d1, xy to d2, yx to d3 and yy to d4
 *  Matrix(m): copy constructor
 *  m1 = m2: element-wise assignment
 *  m * v: matrix-vector multiplication; result is (m_xx * v_x + m_xy * v_y, m_yx * v_x + m_yy * v_y)
 */
class Matrix {
public:
  // TODO

private:
  double m_xx;
  double m_xy;
  double m_yx;
  double m_yy;
};

#endif
