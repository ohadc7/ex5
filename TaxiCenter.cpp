#include "TaxiCenter.h"

void TaxiCenter::createTrip(InputParsing::parsedTripData parsedTripDataTrip) {
    Trip *trip = new Trip(parsedTripDataTrip.id, parsedTripDataTrip.start, parsedTripDataTrip.end,
                          parsedTripDataTrip.numberOfPassengers, parsedTripDataTrip.tariff);
    listOfTrips.push_back(trip);
}

void TaxiCenter::addDriver(Driver driver) {
    listOfDrivers.push_back(driver);
}

const vector<Driver> &TaxiCenter::getListOfDrivers() const {
    return listOfDrivers;
}

const vector<Trip *> &TaxiCenter::getListOfTrips() const {
    return listOfTrips;
}

Point TaxiCenter::getDriverLocation(int driverId) {

    for (unsigned int i = 0; i < listOfDrivers.size(); i++) {
        if (listOfDrivers.at(i).getId() == driverId) {
            return listOfDrivers.at(i).currentPlace();
        }
    }
    throw "No Driver found";
}

TaxiCenter::TaxiCenter(BfsAlgorithm<Point> &bfsInstance) : bfsInstance(bfsInstance) {}

void TaxiCenter::addTrip(Trip *trip) {
    listOfTrips.push_back(trip);
}

void TaxiCenter::addCab(Cab *cab) {
    listOfCabs.push_back(cab);
}

void TaxiCenter::startDriving() {
    for (unsigned int i = 0; i < listOfDrivers.size(); i++) {
        if (listOfTrips.size() > 0) {
            if ((listOfDrivers.at(i).currentPlace() == listOfTrips.front()->getStartingPoint())) {
                listOfDrivers.at(i).assignTrip(listOfTrips.front());
                listOfDrivers.at(i).setCurrentLocation();
                delete listOfTrips[i];
                listOfTrips.pop_back();
            }

        }
    }
}

Cab* TaxiCenter::getCab(int id) {
    for (unsigned int i = 0; i < listOfCabs.size(); i++) {
        if (listOfCabs.at(i)->getId() == id) {
            return listOfCabs.at(i);
        }
    }
   throw "no cab found";
}

TaxiCenter::~TaxiCenter() {
    for (unsigned int i = 0; i < listOfCabs.size(); i++) {
        delete listOfCabs[i];
    }
}

