#ifndef EX1_VERSION_1_1_DRIVER_H
#define EX1_VERSION_1_1_DRIVER_H

#include "Cab.h"
#include "Trip.h"

enum Status_Of_Marriage {SINGLE, MARRIED, DIVORCED, WIDOWED};

class Driver {
private:
    int id;
    int age;
    Status_Of_Marriage status;
    int yearsOfExperience;
    int satisfactions;
    Cab infoCab;
    Trip currentTrip;
public:
    Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, const Cab &infoCab);

    int getId() const;

    int getAge() const;

    Status_Of_Marriage getStatus() const;

    int getYearsOfExperience() const;

    int getSatisfactions() const;

    const Cab &getInfoCab() const;

    bool isAvailable();

    Point currentPlace();
};


#endif //EX1_VERSION_1_1_DRIVER_H
