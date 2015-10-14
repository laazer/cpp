#include "Vector.hpp"
#include <cassert>

/*
    Vector();
    Vector(int d1, int d2);
    Vector(Vector v);
    double getX();
    double getY();
    void setY(double d);
    void setX(double d);
    double & operator[](int i);
    ostream & operator<<(ostream &output, const Vector &v);
    Vector & operator=(const Vector& v);
    bool & operator==(const Vector& v);
    bool & operator!=(const Vector& v);
    void & operator~();
    void & operator+=(const Vector& v);
    void & operator *=(const Vector& v);
    Vector operator -(Vector& v);
    Vector operator -=(Vector& v);
    Vector operator /=(Vector& v);
*/

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

double Vector::operator[](int i)
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

Vector& Vector::operator*=(const Vector& v)
{
    this->m_x *= v.getX();
    this->m_y *= v.getY();
    return *this;
}

Vector& Vector::operator/=(const Vector& v)
{
    this->m_x /= v.getX();
    this->m_y /= v.getY();
    return *this;
}


Vector operator +(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

Vector operator -(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() - v2.getX(), v1.getY() - v2.getY());
}
                  
Vector operator *(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() * v2.getX(), v1.getY() * v2.getY());
}                

Vector operator /(const Vector& v1, const Vector& v2) {
    return Vector(v1.getX() / v2.getX(), v1.getY() / v2.getY());
}

ostream& operator <<(ostream& output, const Vector& v) {
    output << v.getX() << " " << v.getY();
    return output;  
}
                  
int main() 
{
    Vector v1; // initialized to zero
    Vector v2(1.0, 2.0); // element-wize initialized
    Vector v3(v2); // copy constructor
    Vector v4(5.0, 4.0);
    cout << v2.getX() << endl;
    cout << v2[1] << endl;
    cout << (v2 == v3 == false) << endl;
    cout << (v2 == v4) << endl;
    v2 = v4;
    cout << (v2 == v4) << endl;
    Vector v5 = v2 + v3;
    cout << (v2) << endl;
}
