#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

Matrix::Matrix(double d1, double d2, double d3, double d4) {
    m_xx = d1;
    m_xy = d2;
    m_yx = d3;
    m_yy = d4;
}

Matrix::Matrix(const Matrix& m) {
    m_xx = m.m_xx;
    m_xy = m.m_xy;
    m_yx = m.m_yx;
    m_yy = m.m_yy;
}

 Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        this->m_xx = m.m_xx;
        this->m_xy = m.m_xy;
        this->m_yx = m.m_yx;
        this->m_yy = m.m_yy;
    }
    return *this;
 }

// m * v: matrix-vector multiplication; result is (m_xx * v_x + m_xy * v_y, m_yx * v_x + m_yy * v_y)
Vector operator *(const Matrix& m, const Vector& v) {
    return Vector(m.m_xx * v.getX() + m.m_xy * v.getY(), m.m_yx * v.getX() + m.m_yy * v.getY());
} 