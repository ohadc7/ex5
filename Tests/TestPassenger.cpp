#include "gtest/gtest.h"
#include "../Passenger.h"

class TestPassenger: public ::testing::Test {

protected:
    Point reuvenSourcePoint,reuvenDestinationPoint;
    Passenger reuven;
    TestPassenger() : reuvenSourcePoint(2,2), reuvenDestinationPoint(1,0),
                      reuven(reuvenSourcePoint, reuvenDestinationPoint, false){};
};

TEST_F(TestPassenger,sanityCheck){
    ASSERT_EQ(reuven.getIsLuxury(), false) << "check the cab type";
    ASSERT_EQ(reuven.getSatisfaction(),0) << "check the satisfaction getter";
}