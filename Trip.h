#ifndef EX2_TRIP_H
#define EX2_TRIP_H


#include <list>
#include "Point.h"
#include "Passenger.h"

class Trip {
public:
    Trip();
    Trip(int rideId, Point startingPoint, Point endingPoint, list <Passenger> customers);

private:
    int rideId;
    int passedMeters;
    Point startingPoint;
    Point endingPoint;
    list<Passenger> customers;
    double rateOfTrip;
public:
    int getRideId() const;
    int getPassedMeters() const;
    const Point &getStartingPoint() const;
    const Point &getEndingPoint() const;
    const list <Passenger> &getCustomers() const;
    double getRateOfTrip() const;
};


#endif //EX2_TRIP_H
