#include "gtest/gtest.h"
#include "../Trip.h"

class TestTrip: public ::testing::Test {

protected:
    Trip trip;
    list<Passenger> passengersList;

    virtual void SetUp() {
        Passenger Reuven = Passenger(Point(0,0),Point(1,0), false);
        Passenger Shimon = Passenger(Point(9,9),Point(1,0), false);
        //2 passengers with the same arguments;
        Passenger Ohad = Passenger(Point(5,5),Point(3,3), false);
        Passenger Ido = Passenger(Point(5,5),Point(3,3), false);

        passengersList.push_back(Reuven);
        passengersList.push_back(Shimon);
        passengersList.push_back(Ohad);
        passengersList.push_back(Ido);

        trip = Trip(1384, Point(0, 0), Point(3, 3), passengersList);
    }

};

TEST_F(TestTrip, GettersCheck) {
    ASSERT_EQ(trip.getRideId(),1384);
    ASSERT_EQ(trip.getStartingPoint(), Point(0,0));
    ASSERT_EQ(trip.getEndingPoint(), Point(3, 3));
    ASSERT_EQ(trip.getPassedMeters(), 0) << "ERROR: passed meters of constructed trip isn't 0";
    ASSERT_EQ(trip.getNumberOfPassengers(),4) << "ERROR: this trip has to contain 4 passengers";
}

