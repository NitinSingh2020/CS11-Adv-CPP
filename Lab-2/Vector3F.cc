#include <iostream>
#include <cassert>
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