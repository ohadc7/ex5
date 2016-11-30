#include <gtest/gtest.h>
#include "../Point.h"

class PointTest: public ::testing::Test {
protected:
    Point p1 = Point(1,2);
    Point p2 = Point(1,2);
    Point p3 = Point(0,2);
    Point p4 = Point(1,0);
};

//our tests:
TEST_F(PointTest, SanityChecks) {
    ASSERT_NE(p1,p3);
    ASSERT_NE(p1,p4);
    ASSERT_EQ(p1,p2);
}

TEST_F(PointTest, OrderingRelationsChecks) {
    // =
    ASSERT_EQ(p1,p1);
    ASSERT_EQ(p1,p2);
    // < asymmetry
    ASSERT_NE((p1<p3),(p3<p1));
    ASSERT_NE((p1<p4),(p4<p1));
    // < not reflexive
    bool falseResult = false;
    ASSERT_EQ(falseResult,(p2<p1)) << "These points are suuposed to be: p2 == p1 == Point(1,2)";
}

TEST_F(PointTest, printing) {
    /*
    according to   http://stackoverflow.com/questions/31815230/
     how-to-test-input-and-output-overloaded-operator-in-c-gtest
     */
    ostringstream output;
    output << p1;
    ASSERT_EQ(output.str(),"(1,2)");
}