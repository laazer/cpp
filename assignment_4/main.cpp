#include "Matrix.hpp"
#include "Vector.hpp"
#include "IShape.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include <iostream>

int
main()
{
  // *** use vector and matrix classes ***

  Vector v1; // initialized to zero
  Vector v2(1.0, 2.0); // element-wize initialized
  Vector v3(v2); // copy constructor

  v3.setX(5.0); // set element
  v3.setY(7.0); // set element

  std::cout << v2.getX() << " " << v2.getY() << std::endl; // get element

  v1 = v3; // assignment

  v1[0] = 11.0; // element access to m_x
  v1[1] = 12.0; // element access to m_y
  // v1[2] = 0.0; // out-of-bounds index: assertion failure
  // v1[-1] = 0.0; // out-of-bounds index: assertion failure

  std::cout << v1 << std::endl; // should display "m_x m_y" (with actual member values)
  
  std::cout << (v1 == v2) << " " << (v1 == v1) << std::endl; // equality
  std::cout << (v1 != v2) << " " << (v1 != v1) << std::endl; // inequality

  v2 = -v1; // element-wise negation

  v1 += v2;     // element-wise addition
  v1 = v2 + v3; // element-wise addition
  v1 -= v3;     // element-wise subtraction
  v1 = v2 - v3; // element-wise subtraction
  
  v1 *= 4.0; // element-wise multiplication
  v1 /= 3.0; // element-wise multiplication
  // v1 /= 0.0; // division by zero: assertion failure
  v1 = v2 * 2.0; // element-wise multiplication
  v1 = 2.0 * v2; // element-wise multiplication
  v1 = v2 / 2.0; // element-wise multiplication
  // v1 = v2 / 0.0; // division by zero: assertion failure

  Matrix m1(1.0, 0.0, 0.0, 1.0);
  Matrix m2(1.0, 2.0, 0.0, 1.0);
  Matrix m3(m2);

  m3 = m1;

  v1 = m1 * v2; // matrix-vector multiplication

  // *** use shape classes ***

  IShape * shp1 = new Triangle(Vector(0.0, 0.0), Vector(0.0, 1.0), Vector(1.0, 0.0));
  IShape * shp2 = new Circle(Vector(0.0, 0.0), 1.0);
  const IShape * cshp1 = shp1;
  const IShape * cshp2 = shp2;

  // *shp2 = *shp1; // should not compile

  std::cout << cshp1->getArea() << " " << cshp2->getArea() << std::endl; // gets area of shape
  cshp1->display(std::cout); // should display "Triangle(x0 y0; x1 y1; x2 y2)" (with actual member values)
  std::cout << std::endl;
  cshp2->display(std::cout); // should display "Circle(cx cy; radius)" (with actual member values)
  std::cout << std::endl;

  shp1->translate(Vector(1.0, 2.0)); // translate all points by given vector
  shp2->translate(Vector(-2.0, -1.0));

  std::cout << cshp1->getArea() << " " << cshp2->getArea() << std::endl;
  cshp1->display(std::cout);
  std::cout << std::endl;
  cshp2->display(std::cout);
  std::cout << std::endl;

  delete shp2;
  shp2 = NULL;
  delete shp1;
  shp1 = NULL;
}
