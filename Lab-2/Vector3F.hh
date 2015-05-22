#ifndef __VECTOR3F_HH__
#define __VECTOR3F_HH__

class Vector3F {
    float elems[3];
public:
    /* Constructors */
    Vector3F();                           // Default Constructor
    Vector3F(float x, float y, float z);  // Three Argument Constructor

    /* No Destructor Needed since no dynamic memory allocation */
    /* No Accessor methods */
    /* No Mutator method */
    

    const float L2_norm() const;                        // Magnitude of vector
    const float magnitude_square() const;               // Square of Magnitude
    void normalize();                                   // Normalization

    /* Overloaded Operators */
    Vector3F & operator=(const Vector3F &v);            // Assignment
    Vector3F & operator+=(const Vector3F &v);           // Compound sum
    Vector3F & operator-=(const Vector3F &v);           // Compound subtraction
    const Vector3F operator+(const Vector3F &v) const;  // Sum
    const Vector3F operator-(const Vector3F &v) const;  // Subtraction
    Vector3F & operator*=(float s);           // Compound Multiplication
    Vector3F & operator/=(float s);           // Compound Division

    const Vector3F operator-() const;  // Unary Minus
    float operator[](int i) const;     // First Version; Accessor
    float & operator[](int i);         // Second Version; Mutator

    const float operator*(const Vector3F &v) const;          // Dot Product
    const Vector3F operator%(const Vector3F &v) const;       // Cross Product

    /* These are not asked to be done in Lab Instructions */
    bool operator==(const Vector3F &v) const;             // Equality
    bool operator!=(const Vector3F &v) const;             // Non-equality
};

/* Non Member Functions */
/* Overloaded Operators */
const Vector3F operator*(const Vector3F &v, float s);  // Multiplication
const Vector3F operator*(float s, const Vector3F &v);  // Multiplication
const Vector3F operator/(const Vector3F &v, float s);  // Division
//std::ostream & operator<<(std::ostream &os, const Vector3F &v);  // Stream-output operator

#endif /* __VECTOR3F_HH__ */
