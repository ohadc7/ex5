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
    vector<Driver> listOfAvialbeDrivers;
    vector<Trip *> listOfTrips;
    vector<Cab*> listOfCabs;
    BfsAlgorithm<Point> bfsInstance;
public:
    TaxiCenter(BfsAlgorithm<Point> &bfsInstance);

    void addDriver(Driver driver);
    void addCab(Cab* cab);
    void startDriving();

    const vector<Driver> &getListOfDrivers() const;

    const vector<Trip *> &getListOfTrips() const;

    //void addAvialbleDriver(Driver driver);

    // const vector<Driver> &getListOfAvilableDrivers() const;

    Point getDriverLocation(int driverId);

    void addTrip(Trip *trip);

    void createTrip(InputParsing::parsedTripData);

    Cab* getCab(int id);

    ~TaxiCenter();
};


#endif //EX1_VERSION_1_1_TAXICENTER_H
