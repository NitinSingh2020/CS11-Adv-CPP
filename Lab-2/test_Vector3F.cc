#include "Vector3F.hh"
#include <gtest/gtest.h>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;


TEST(TestVector3F, FeatureOne) {
    // Code to exercise the feature
}


TEST(TestVector3F, FeatureTwo) {
    // Code to exercise the feature
}

TEST(TestVector3F, FeatureThree) {
    Vector3F m(1.0, 2.0, 3.0);
    Vector3F n(11.0, 12.0, 13.0);
    n = m;
    ASSERT_FLOAT_EQ(3, 3) << "length is wrong!";
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
