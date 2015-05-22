#include <iostream>
#include <cassert>
#include <cmath>
#include "Vector3F.hh"

/* Default (aka no-argument) constructor */
Vector3F::Vector3F() {
    elems[0] = 0.0;
    elems[1] = 0.0;
    elems[2] = 0.0;
}

/* Three-argument constructor */
Vector3F::Vector3F(float x, float y, float z) {
    elems[0] = x;
    elems[1] = y;
    elems[2] = z;
}

/* Assignment Operator */
Vector3F & Vector3F::operator=(const Vector3F &v) {
    // Avoid self-assignment
    if (this != &v)
        return *this;
}

/* Compound Sum Operator */
Vector3F & Vector3F::operator+=(const Vector3F &v) {
    // Avoid self-assignment
    if (this != &v) {
        this->elems[0] = this->elems[0] + v.elems[0];
        this->elems[1] = this->elems[1] + v.elems[1];
        this->elems[2] = this->elems[2] + v.elems[2];
    } else {
        // First, make a copy of myself
        Vector3F newCopy(*this);
        this->elems[0] = newCopy.elems[0] + v.elems[0];
        this->elems[1] = newCopy.elems[1] + v.elems[1];
        this->elems[2] = newCopy.elems[2] + v.elems[2];
    }
    return *this;
}

/* Compound Subtraction Operator */
Vector3F & Vector3F::operator-=(const Vector3F &v) {
    // Avoid self-assignment
    if (this != &v) {
        this->elems[0] = this->elems[0] - v.elems[0];
        this->elems[1] = this->elems[1] - v.elems[1];
        this->elems[2] = this->elems[2] - v.elems[2];
    } else {
        // First, make a copy of myself
        Vector3F newCopy(*this);
        this->elems[0] = newCopy.elems[0] - v.elems[0];
        this->elems[1] = newCopy.elems[1] - v.elems[1];
        this->elems[2] = newCopy.elems[2] - v.elems[2];
    }
    return *this;
}

/* Sum Operator */
const Vector3F Vector3F::operator+(const Vector3F &v) const {
    return Vector3F(*this) += v;
}

/* Subtraction Operator */
const Vector3F Vector3F::operator-(const Vector3F &v) const {
    return Vector3F(*this) -= v;
}

/* Compound Multiplication Operator */
Vector3F & Vector3F::operator*=(float s) {
    this->elems[0] = this->elems[0] * s;
    this->elems[1] = this->elems[1] * s;
    this->elems[2] = this->elems[2] * s;
    return *this;
}

/* Compound Division Operator */
Vector3F & Vector3F::operator/=(float s) {
    assert(s != 0);
    this->elems[0] = this->elems[0] / s;
    this->elems[1] = this->elems[1] / s;
    this->elems[2] = this->elems[2] / s;
    return *this;
}

/* Multiplication */
const Vector3F operator*(const Vector3F &v, float s) {
    return Vector3F(v) *= s;
}

/* Multiplication */
const Vector3F operator*(float s, const Vector3F &v) {
    return Vector3F(v) *= s;
}

/* Division */
const Vector3F operator/(const Vector3F &v, float s) {
    return Vector3F(v) /= s;
}

/* Unary Minus */
const Vector3F Vector3F::operator-() const {
    return Vector3F(*this) *= -1;
}

/* First Version; Accessor */
float Vector3F::operator[](int i) const {
    assert(i >= 0);
    assert(i <= 2);
    return elems[i];
}

/* Second Version; Mutator */
float & Vector3F::operator[](int i) {
    assert(i >= 0);
    assert(i <= 2);
    return elems[i];
}

/* Dot Product */
const float Vector3F::operator*(const Vector3F &v) const {
    return elems[0] * v[0] + elems[1] * v[1] + elems[2] * v[2];
}

/* Cross Product */
const Vector3F Vector3F::operator%(const Vector3F &v) const {
    float x = (elems[1] * v[2]) - (elems[2] * v[1]);
    float y = (elems[2] * v[0]) - (elems[0] * v[2]);
    float z = (elems[0] * v[1]) - (elems[1] * v[0]);
    return Vector3F(x, y, z);
}

/* Magnitude of vector */
const float Vector3F::L2_norm() const {
    return sqrtf(elems[0] * elems[0] + elems[1] * elems[1] + elems[2] * elems[2]);
}

/* Square of Magnitude */
const float Vector3F::magnitude_square() const {
    return (elems[0] * elems[0] + elems[1] * elems[1] + elems[2] * elems[2]);
}

/* Normalization */
void Vector3F::normalize() {
    if (this->magnitude_square() != 0.0) {
        float magnitude = this->L2_norm();
        elems[0] /= magnitude;
        elems[1] /= magnitude;
        elems[2] /= magnitude;
    }
}

/* Stream-output operator */
std::ostream & operator<<(std::ostream &os, const Vector3F &v) {
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

/* Equality Operator */
bool Vector3F::operator==(const Vector3F &other) const {
    if ( this->elems[0] == other.elems[0] &&
        this->elems[1] == other.elems[1] &&
        this->elems[2] == other.elems[2] )
        return true;
    else
        return false;
}

/* Non-equality Operator */
bool Vector3F::operator!=(const Vector3F &v) const {
    return !(*this == v);
}
