#include "Circle.hpp"
#include "IShape.hpp"

Circle::Circle(double x, double y, double radius) {
    m_center = Vector(x, y);
    m_radius = radius;
}

ostream& display(ostream& os) {
    return ostream << "Circle(" << this->m_center << "; " << this->m_radius << ")";
}