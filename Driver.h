#ifndef EX1_VERSION_1_1_DRIVER_H
#define EX1_VERSION_1_1_DRIVER_H

#include <vector>
#include "Cab.h"
#include "Trip.h"

typedef enum {SINGLE, MARRIED, DIVORCED, WIDOWED} Status_Of_Marriage;

class Driver {
private:
    int id;
    int age;
    double averageSatisfactions;
    Status_Of_Marriage status;
    int yearsOfExperience;
    Cab *cabOfDriver;
    int numOfTrips;
    Point currentLocation;
    vector<Passenger> listOfPassengers;
public:
    Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, Cab *cab);

    int getId() const;

    int getAge() const;

    Status_Of_Marriage getStatus() const;

    int getYearsOfExperience() const;

    void attachCabToDriver(Cab *infoCab);

    double getSatisfactions() const;

    Cab *getInfoCab() const;

    bool isAvailable();

    Point currentPlace();

    void setCurrentLocation(Point pointNewLocation);

    void clientSatisfactions(int clientSatisfactions);

    vector<Passenger> getListOfPassengers() const;

    void addPassenger(Passenger passenger);

};
#endif //EX1_VERSION_1_1_DRIVER_H
