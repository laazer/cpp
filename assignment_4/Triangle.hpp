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
class Triangle: public IShape {
    public:
        Triangle(const Vector& v1, const Vector& v2, const Vector& v3);
        ~Triangle();
        double getArea() const;
        void translate(const Vector& v) const;
        ostream& display(ostream& os) const;

    private:
  // TODO

    Vector * m_points; // pointer to dynamic length-three array containing points
};

#endif
