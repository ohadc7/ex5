//
// Created by ido on 29/11/16.
//

#include "Driver.h"

Driver::Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience,
               const Cab &infoCab) : id(id), age(age), status(status),
                                     yearsOfExperience(yearsOfExperience), infoCab(infoCab){}

int Driver::getId() const {
    return id;
}

int Driver::getAge() const {
    return age;
}

Status_Of_Marriage Driver::getStatus() const {
    return status;
}

int Driver::getYearsOfExperience() const {
    return yearsOfExperience;
}

int Driver::getSatisfactions() const {
    return satisfactions;
}

const Cab &Driver::getInfoCab() const {
    return infoCab;
}
