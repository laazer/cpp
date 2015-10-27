#include "Circle.hpp"
#include "IShape.hpp"
#include <cmath>

Circle::Circle(const Vector& v, double radius) {
    m_center = v;
    m_radius = radius;
}

ostream& Circle::display(ostream& os) const {
    return os << "Circle(" << this->m_center << "; " << this->m_radius << ")";
}

double Circle::getArea() const {
    return M_PI * pow(this->m_radius, 2);
}

void Circle::translate(const Vector& v) const {
    Vector p_v = this->m_center;
    p_v.setX(p_v.getX() * v.getX());
    p_v.setY(p_v.getY() * v.getY());
}