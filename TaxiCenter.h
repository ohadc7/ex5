#ifndef EX1_VERSION_1_1_TAXICENTER_H
#define EX1_VERSION_1_1_TAXICENTER_H

#include "Driver.h"
#include "Trip.h"
#include "Passenger.h"
#include "BfsAlgorithm.h"

class TaxiCenter {
private:
    list<Driver> listOfDrivers;
    list<Trip> listOfTrips;
    BfsAlgorithm<Node<Point>> bfsInstance;

    Driver chooseBestDriver(Passenger passenger);
    Trip createTrip(Driver driver, Passenger passenger);
    void sendTaxi(Trip trip, bool isLuxury);

public:
    void addDriver(Driver driver);
    void orderATrip(Passenger passenger);
};


#endif //EX1_VERSION_1_1_TAXICENTER_H
