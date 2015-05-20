#include "Vector3F.hh"
#include <iostream>
#include <cassert>

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