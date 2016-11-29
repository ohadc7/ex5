#include <gtest/gtest.h>
#include "../Point.h"

//our tests:
TEST(PointTests, SanityChecks) {
    Point p1 = Point(1,2);
    Point p2 = Point(1,2);
    Point p3 = Point(0,2);
    Point p4 = Point(1,0);
    ASSERT_NE(p1,p3);
    ASSERT_NE(p1,p4);
    ASSERT_EQ(p1,p2);
}

TEST(PointTests, OrderingRelationsChecks) {
    Point p1 = Point(1,2);
    Point p2 = Point(1,2);
    Point p3 = Point(0,2);
    Point p4 = Point(1,0);
    ASSERT_NE(p1,p3);
    ASSERT_NE(p1,p4);
    ASSERT_EQ(p1,p2);
}