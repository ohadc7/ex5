#ifndef EX1_VERSION_1_1_TAXICENTER_H
#define EX1_VERSION_1_1_TAXICENTER_H

#include "Driver.h"
#include "Trip.h"
#include "Passenger.h"
#include "BfsAlgorithm.h"
#include "InputParsing.h"

class TaxiCenter {
private:
    vector<Driver> listOfDrivers;
    vector<Trip> listOfTrips;
    vector<Cab*> listOfCabs;
    BfsAlgorithm<Point> bfsInstance;
    Driver chooseBestDriver(Passenger passenger);
    void sendTaxi(Trip trip);

public:
    TaxiCenter(BfsAlgorithm<Point> &bfsInstance);

    void addDriver(Driver driver);
    void addCab(Cab* cab);
    void startDriving();


    //choose best driver, create a trip and send taxi
    void orderATrip(Passenger passenger);

    const vector<Driver> &getListOfDrivers() const;

    const vector<Trip> &getListOfTrips() const;

    Point getDriverLocation(int driverId);

    void addTrip(Trip trip);

    void createTrip(InputParsing::parsedTripData);
};


#endif //EX1_VERSION_1_1_TAXICENTER_H
