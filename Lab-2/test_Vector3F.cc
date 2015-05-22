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
    ASSERT_FLOAT_EQ((m += n) == Vector3F(12.0, 25.0, 35.0), true) << "Compound_Sum failed";
    ASSERT_FLOAT_EQ((m += o) == Vector3F(11.0, 25.0, 35.0), false) << "Compound_Sum failed";
}

TEST(TestVector3F, Compound_Diff_true) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ((m -= n) == Vector3F(-10.0, -21.0, -29.0), true) << "Compound_Diff failed";
    ASSERT_FLOAT_EQ((m -= o) == Vector3F(-10.0, -21.0, 35.0), false) << "Compound_Diff failed";
}

TEST(TestVector3F, Sum_true) {
    Vector3F o = Vector3F(1.0, 2.0, 3.0) + Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F(12.0, 25.0, 35.0), true) << "Sum failed";
}

TEST(TestVector3F, Sum_false) {
    Vector3F o = Vector3F(1.0, 2.0, 3.0) + Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F(1.0, 25.0, 35.0), false) << "Sum failed";
}

TEST(TestVector3F, Diff_true) {
    Vector3F o = Vector3F(1.0, 2.0, 3.0) - Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F(-10.0, -21.0, -29.0), true) << "Diff failed";
}

TEST(TestVector3F, Diff_false) {
    Vector3F o = Vector3F(1.0, 2.0, 3.0) - Vector3F(11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F(-1.0, -21.0, -29.0), false) << "Diff failed";
}

TEST(TestVector3F, Compound_Multiply_true) {
    Vector3F m(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ((m*=3.5) == Vector3F(3.5, 7.0, 10.5), true) << "Compound Multiply failed";
}

TEST(TestVector3F, Compound_Multiply_false) {
    Vector3F m(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ((m*=3.5) == Vector3F(3.0, 7.0, 10.5), false) << "Compound Multiply failed";
}

TEST(TestVector3F, Compound_Div_true) {
    Vector3F m(3.5, 7.0, 10.5);
    ASSERT_FLOAT_EQ((m/=3.5) == Vector3F(1.0, 2.0, 3.0), true) << "Compound Division failed";
}

TEST(TestVector3F, Compound_Div_false) {
    Vector3F m(3.5, 7.0, 10.5);
    ASSERT_FLOAT_EQ((m/=3.5) == Vector3F(1.5, 2.0, 3.0), false) << "Compound Division failed";
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

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

