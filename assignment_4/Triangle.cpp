#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(const Vector& v1, const Vector& v2, const Vector& v3) {
    m_points = new Vector[3];
    m_points[0] = v1;
    m_points[1] = v2;
    m_points[2] = v3;
}

Triangle::~Triangle() {
    delete [] m_points;
}

ostream& Triangle::display(ostream& os) const{
    return os << "Triangle(" << this->m_points[0] << "; " << this->m_points[1] << "; " << this->m_points[2] << ")";
}

double Triangle::getArea() const{
    Vector a = this->m_points[0];
    Vector b = this->m_points[1];
    Vector c = this->m_points[2];
    double res = a.getX() * (b.getY() - b.getY());
    res += b.getX() * (c.getY() - a.getY());
    res += c.getX() * (a.getY() - b.getY());
    return res/2;
}

void Triangle::translate(const Vector& v) const{
    Vector pv;
    for(int i =0; i < 3; i++ ) {
        pv = m_points[i];
        pv.setX(pv.getX() * v.getX());
        pv.setY(pv.getY() * v.getY());
    }
}
