#ifndef EX1_VERSION_1_1_DRIVER_H
#define EX1_VERSION_1_1_DRIVER_H

#include <vector>
#include "Cab.h"
#include "Trip.h"

enum Status_Of_Marriage {SINGLE, MARRIED, DIVORCED, WIDOWED};

class Driver {
private:
    int id;
    int age;
    double averageSatisfactions;
    Status_Of_Marriage status;
    int yearsOfExperience;
    Cab *infoCab;
    Trip currentTrip;
    int numOfTrips;
    vector<Passenger> listOfPassengers;
public:
    Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience);

    int getId() const;

    int getAge() const;

    Status_Of_Marriage getStatus() const;

    int getYearsOfExperience() const;

    void attachCabToDriver(Cab *infoCab);

    double getSatisfactions() const;

    const Cab *getInfoCab();

    bool isAvailable();

    Point currentPlace();

    void clientSatisfactions(int clientSatisfactions);

    vector<Passenger> getListOfPassengers() const;

    void addPassenger(Passenger passenger);

};
#endif //EX1_VERSION_1_1_DRIVER_H
