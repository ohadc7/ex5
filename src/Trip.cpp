#include "Trip.h"

/*
Trip::Trip(int rideId, Point startingPoint, Point endingPoint, int numOfPassengers, double taarif)
        : rideId(rideId), startingPoint(startingPoint), endingPoint(endingPoint),
          numOfPassengers(numOfPassengers) {
    rateOfTrip = taarif;
    passedMeters = 0;
}
*/

Trip::Trip(int rideId, Point startingPoint, Point endingPoint, int numOfPassengers, double taarif,
           stack<Node<Point>> pathWithoutStartingPoint) : rideId(rideId), startingPoint(startingPoint),
                                      endingPoint(endingPoint), numOfPassengers(numOfPassengers),
                                      nextPointsOfPath(pathWithoutStartingPoint) {
    rateOfTrip = taarif;
    passedMeters = 0;
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
    return (int) customers.size();
}

double Trip::getRateOfTrip() const {
    return rateOfTrip;
}

int Trip::getPassedMeters() const {
    return passedMeters;
}

const stack<Node<Point>> &Trip::getPath() const {
    return nextPointsOfPath;
}

void Trip::removeNextPointOfPath() {
    if (!this->nextPointsOfPath.empty()) {
        this->nextPointsOfPath.pop();
        passedMeters++;
    }
}

Trip::~Trip() {
}


