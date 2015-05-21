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

TEST(TestVector3F, FeatureOne) {
    // Code to exercise the feature
}

TEST(TestVector3F, FeatureTwo) {
    // Code to exercise the feature
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
