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

const double Vector::getX() 
{
    return m_x;
}

const double Vector::getY() 
 {
    return m_y;
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
   
/*
ostream Vector::operator<<(ostream& output)
{
    return output << m_x << " " << m_y;
}
*/
bool Vector::operator==(const Vector& v1, const Vector& v2)
{
    return v1.m_x == v2.m_x && v1.m_y == v2.m_y;
}

bool Vector::operator!=(const Vector& v1, const Vector& v2)
{
    return !(v1 == v2);
}

int main() 
{
    Vector v1; // initialized to zero
    Vector v2(1.0, 2.0); // element-wize initialized
    Vector v3(v2); // copy constructor
    cout << v2.getX() << endl;
    cout << v2[1] << endl;
    //cout  << v2 << endl;
}
