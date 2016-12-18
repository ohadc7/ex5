#ifndef EX2_TRIP_H
#define EX2_TRIP_H


#include <list>
#include "Point.h"
#include "Passenger.h"

class Trip {

private:
    int rideId;
    int passedMeters; //total meters passed at the current point
    Point startingPoint;
    Point endingPoint;
    list <Passenger> customers; //passengers
    int numOfPassengers;
    double rateOfTrip; //tariff
public:
    Trip(int rideId, Point startingPoint, Point endingPoint, int numOfPassengers, double taarif);

    int getRideId() const;

    int getPassedMeters() const;

    int getNumberOfPassengers() const;

    const Point &getStartingPoint() const;

    const Point &getEndingPoint() const;

    const list <Passenger> &getCustomers() const;

    double getRateOfTrip() const;

    ~Trip();
};


#endif
