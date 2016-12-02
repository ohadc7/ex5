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
    BfsAlgorithm<Point> bfsInstance;

    Driver chooseBestDriver(Passenger passenger);
    Trip createTrip(Driver driver, Passenger passenger);
    void sendTaxi(Trip trip);

public:
    TaxiCenter(BfsAlgorithm<Point> &bfsInstance);

    void addDriver(Driver driver);

    //choose best driver, create a trip and send taxi
    void orderATrip(Passenger passenger);

    const list <Driver> &getListOfDrivers() const;

    const list <Trip> &getListOfTrips() const;

    Point getDriverLocation(Driver driver);
};


#endif //EX1_VERSION_1_1_TAXICENTER_H
