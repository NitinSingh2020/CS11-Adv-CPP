#include "Vector3F.hh"
#include <gtest/gtest.h>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;

TEST(TestVector3F, Equality) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ(m == n, true) << "Vector Equality Operator Failed!";
    Vector3F o(0.0, 0.0, 0.0);
    ASSERT_FLOAT_EQ(m == o, false) << "Vector Equality Operator Failed!";
}

TEST(TestVector3F, Non_Equality) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 12.0, 13.0);
    Vector3F o(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ(m != n, true) << "Vector Non-Equality Oerator Failed!";
    ASSERT_FLOAT_EQ(m != o, false) << "Vector Non-Equality Oerator Failed!";
}

TEST(TestVector3F, Compound_Sum) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ((m += n) == Vector3F(12.0, 25.0, 35.0), true)
        << "Compound_Sum failed";
    ASSERT_FLOAT_EQ((m += o) == Vector3F(11.0, 25.0, 35.0), false)
        << "Compound_Sum failed";
}

TEST(TestVector3F, Compound_Diff) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ((m -= n) == Vector3F(-10.0, -21.0, -29.0), true)
        << "Compound_Diff failed";
    ASSERT_FLOAT_EQ((m -= o) == Vector3F(-10.0, -21.0, 35.0), false)
        << "Compound_Diff failed";
}

TEST(TestVector3F, Sum) {
    Vector3F m = Vector3F(1.0, 2.0, 3.0) + Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(m == Vector3F(12.0, 25.0, 35.0), true) << "Sum failed";

    Vector3F n = Vector3F(1.0, 2.0, 3.0) + Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(n == Vector3F(1.0, 25.0, 35.0), false) << "Sum failed";
}

TEST(TestVector3F, Diff) {
    Vector3F m = Vector3F(1.0, 2.0, 3.0) - Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(m == Vector3F(-10.0, -21.0, -29.0), true) << "Diff failed";

    Vector3F n = Vector3F(1.0, 2.0, 3.0) - Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(n == Vector3F(-1.0, -21.0, -29.0), false) << "Diff failed";
}

TEST(TestVector3F, Compound_Multiply) {
    Vector3F m(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ((m*=3.5) == Vector3F(3.5, 7.0, 10.5), true)
        << "Compound Multiply failed";

    Vector3F n(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ((n*=3.5) == Vector3F(3.0, 7.0, 10.5), false)
        << "Compound Multiply failed";
}

TEST(TestVector3F, Compound_Div) {
    Vector3F m(3.5, 7.0, 10.5);
    ASSERT_FLOAT_EQ((m/=3.5) == Vector3F(1.0, 2.0, 3.0), true)
        << "Compound Division failed";

    Vector3F n(3.5, 7.0, 10.5);
    ASSERT_FLOAT_EQ((n/=3.5) == Vector3F(1.5, 2.0, 3.0), false)
        << "Compound Division failed";
}

TEST(TestVector3F, Multiply_scalarRight) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n = m * 3.5;
    ASSERT_FLOAT_EQ(n == Vector3F(3.5, 7.0, 10.5), true) << "Multiply failed";
}

TEST(TestVector3F, Multiply_scalarLeft) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n = 3.5 * m;
    ASSERT_FLOAT_EQ(n == Vector3F(3.5, 7.0, 10.5), true) << "Multiply failed";
}

TEST(TestVector3F, Div_scalar) {
    Vector3F m(3.5, 7.0, 10.5);
    Vector3F n = m / 3.5;
    ASSERT_FLOAT_EQ(n == Vector3F(1.0, 2.0, 3.0), true) << "Division failed";
}

TEST(TestVector3F, Unary_minus) {
    Vector3F m(3.5, 7.0, 10.5);
    Vector3F n = -m;
    ASSERT_FLOAT_EQ(n == Vector3F(-3.5, -7.0, -10.5), true) << "Unary Minus failed";
    ASSERT_FLOAT_EQ(m == -(-m), true) << "Unary Minus failed";
}

TEST(TestVector3F, Vector_Accessor) {
    Vector3F m(3.5, 7.0, 10.5); 
    ASSERT_FLOAT_EQ(m[0] == 3.5, true) << "Vector Accessor failed";
    ASSERT_FLOAT_EQ(m[1] == 7.0, true) << "Vector Accessor failed";
    ASSERT_FLOAT_EQ(m[2] == 10.5, true) << "Vector Accessor failed";
}

TEST(TestVector3F, Vector_Mutator) {
    Vector3F m(3.5, 7.0, 10.5);
    m[0] = 1.0;
    m[1] = 2.0;
    m[2] = 3.0;
    ASSERT_FLOAT_EQ(m == Vector3F(1.0, 2.0, 3.0), true) << "Vector Mutator failed";
}

TEST(TestVector3F, Dot_Product) {
    Vector3F m(1.0, 3.0, 5.0);
    Vector3F n(2.0, 4.0, 6.0);
    ASSERT_FLOAT_EQ(m * n == 44.0, true) << "Dot product failed";
}

TEST(TestVector3F, Cross_Product) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(4.0, 5.0, 6.0);
    ASSERT_FLOAT_EQ(m % n == Vector3F(-3.0, 6.0, -3.0), true)
        << "Cross product failed";
}

TEST(TestVector3F, L2_Norm) {
    Vector3F m(0.0, 3.0, 4.0);
    ASSERT_FLOAT_EQ(m.L2_norm() == 5.0, true)
        << "L2 norm (magnitude) failed";
}

TEST(TestVector3F, Magnitude_Square) {
    Vector3F m(0.0, 3.0, 4.0);
    ASSERT_FLOAT_EQ(m.magnitude_square() == 25.0, true)
        << "Magnitude (square) failed";
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
