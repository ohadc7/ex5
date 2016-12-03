#include "gtest/gtest.h"
#include "../Passenger.h"

class TestPassenger: public ::testing::Test {

protected:
    Point reuvenSourcePoint = Point(2,2);
    Point reuvenDestinationPoint = Point(1,0);
    Passenger reuven = Passenger(reuvenSourcePoint, reuvenDestinationPoint, false);

    virtual void SetUp(){
        reuven.setSatisfaction(5);
    }

};

TEST_F(TestPassenger,sanityCheck){
    ASSERT_EQ(reuven.getIsLuxury(), false) << "check the cab type";
    ASSERT_EQ(reuven.getSatisfaction(),5) << "check the satisfaction getter";
}