#include "Vector3F.hh"
#include <gtest/gtest.h>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;

TEST(TestVector3F, Equality_true) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ(m == n, true) << "Vector Equality Operator Failed!";
}

TEST(TestVector3F, Equality_false) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(0.0, 0.0, 0.0);
    ASSERT_FLOAT_EQ(m == n, false) << "Vector Equality Operator Failed!";
}

TEST(TestVector3F, Non_Equality_true) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 12.0, 13.0);
    ASSERT_FLOAT_EQ(m != n, true) << "Vector Non-Equality Oerator Failed!";
}

TEST(TestVector3F, Non_Equality_false) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(1.0, 2.0, 3.0);
    ASSERT_FLOAT_EQ(m != n, false) << "Vector Non-Equality Oerator Failed!";
}

TEST(TestVector3F, Compound_Sum_true) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(12.0, 25.0, 35.0);
    m += n;
    ASSERT_FLOAT_EQ(m == o, true) << "Compound_Sum failed";
}

TEST(TestVector3F, Compound_Sum_false) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(11.0, 25.0, 35.0);
    m += n;
    ASSERT_FLOAT_EQ(m == o, false) << "Compound_Sum failed";
}

TEST(TestVector3F, Compound_Diff_true) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(-10.0, -21.0, -29.0);
    m -= n;
    ASSERT_FLOAT_EQ(m == o, true) << "Compound_Diff failed";
}

TEST(TestVector3F, Compound_Diff_false) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 23.0, 32.0);
    Vector3F o(-10.0, -21.0, 35.0);
    m -= n;
    ASSERT_FLOAT_EQ(m == o, false) << "Compound_Diff failed";
}

TEST(TestVector3F, Sum_true) {
    Vector3F o = Vector3F (1.0, 2.0, 3.0) + Vector3F (11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F (12.0, 25.0, 35.0), true) << "Sum failed";
}

TEST(TestVector3F, Sum_false) {
    Vector3F o = Vector3F (1.0, 2.0, 3.0) + Vector3F (11.0, 23.0, 32.0);
    ASSERT_FLOAT_EQ(o == Vector3F (1.0, 25.0, 35.0), false) << "Sum failed";
}

TEST(TestVector3F, FeatureTwo) {
    // Code to exercise the feature
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
