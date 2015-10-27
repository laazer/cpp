#include "Vector.hpp"
#include <cassert>

Vector::Vector() 
{
    m_x = 0.0;
    m_y = 0.0;
}

Vector::Vector(double d1, double d2)
{
    m_x = d1;
    m_y = d2;
}

Vector::Vector(const Vector& v)
{
    m_x = v.m_x;
    m_y = v.m_y;
}

void Vector::setX(double d)
{
    m_x = d;   
}

void Vector::setY(double d)
{
    m_y = d;   
}

double& Vector::operator[](int i)
{
    assert(i >= 0 && i < 2);
    if(i == 0)
    {
        return m_x;
    }
    else
    {
        return m_y;
    }
}

Vector& Vector::operator-() {
    this->m_x = -this->m_x;
    this->m_y = -this->m_y;
    return *this;
}

bool operator==(const Vector & v1, const Vector & v2) {
    return v1.m_x == v2.m_x && v1.m_y == v2.m_y;
}

bool operator!=(const Vector & v1, const Vector & v2) {
    return !(v1 == v2);
}

 Vector& Vector::operator=(const Vector& v) {
    if (this != &v) {
        this->m_x = v.m_x;
        this->m_y = v.m_y;
    }
    return *this;
 }


Vector& Vector::operator+=(const Vector& v)
{
    this->m_x += v.getX();
    this->m_y += v.getY();
    return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
    this->m_x -= v.getX();
    this->m_y -= v.getY();
    return *this;
}

Vector& Vector::operator*=(double d)
{
    this->m_x *= d;
    this->m_y *= d;
    return *this;
}

Vector& Vector::operator/=(double d)
{
    assert(d != 0.0);
    this->m_x /= d;
    this->m_y /= d;
    return *this;
}


Vector operator +(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

Vector operator -(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() - v2.getX(), v1.getY() - v2.getY());
}
                  
Vector operator *(const Vector& v, double d) {
    return Vector(v.getX() * d, v.getY() * d);
} 

Vector operator *(double d, const Vector& v) {
    return v * d;
}

Vector operator /(const Vector& v1, double d) {
    assert(d != 0.0);
    return Vector(v1.getX() / d, v1.getY() / d);
}

ostream& operator <<(ostream& output, const Vector& v) {
    output << v.getX() << " " << v.getY();
    return output;  
}
