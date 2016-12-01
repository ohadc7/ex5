#include "Trip.h"

Trip::Trip(int rideId, Point startingPoint, Point endingPoint, list <Passenger> customers)
        : rideId(rideId), startingPoint(startingPoint), endingPoint(endingPoint), customers(customers) {}

Trip::Trip() {

}

int Trip::getRideId() const {
    return rideId;
}

const Point &Trip::getStartingPoint() const {
    return startingPoint;
}

const Point &Trip::getEndingPoint() const {
    return endingPoint;
}

const list <Passenger> &Trip::getCustomers() const {
    return customers;
}

int Trip::getNumberOfPassengers() const {
    return 0;
}

double Trip::getRateOfTrip() const {
    return rateOfTrip;
}

int Trip::getPassedMeters() const {
    return passedMeters;
}

