#include "TaxiCenter.h"

void TaxiCenter::createTrip(InputParsing::parsedTripData parsedTripDataTrip) {
    Trip trip(parsedTripDataTrip.id, parsedTripDataTrip.start, parsedTripDataTrip.end,
              parsedTripDataTrip.numberOfPassengers, parsedTripDataTrip.tariff);
    listOfTrips.push_back(trip);
}

/*Driver TaxiCenter::chooseBestDriver(Passenger passenger) {
    return NULL;//Driver(0, 0, MARRIED, 0, nullptr);
}*/

void TaxiCenter::sendTaxi(Trip trip) {

}

void TaxiCenter::addDriver(Driver driver) {
    listOfDrivers.push_back(driver);
}

void TaxiCenter::orderATrip(Passenger passenger) {

}

const vector<Driver> &TaxiCenter::getListOfDrivers() const {
    return listOfDrivers;
}

const vector<Trip> &TaxiCenter::getListOfTrips() const {
    return listOfTrips;
}

Point TaxiCenter::getDriverLocation(int driverId) {
    unsigned long index = 0;
    for(Driver &driver : listOfDrivers) {
        if(driver.getId() == driverId){
            return listOfTrips.at(index).getEndingPoint();
        }
        index++;
    }
    throw "No Driver found";
}

TaxiCenter::TaxiCenter(BfsAlgorithm<Point> &bfsInstance) : bfsInstance(bfsInstance) {}

void TaxiCenter::addTrip(Trip trip) {
    listOfTrips.push_back(trip);
}

void TaxiCenter::addCab(Cab *cab) {
    listOfCabs.push_back(cab);
}

void TaxiCenter::startDriving() {
    unsigned long index = 0;
    for(Driver &driver : listOfDrivers) {
        if(driver.getId() == listOfTrips.at(index).getRideId()){
            driver.setCurrentLocation(listOfTrips.at(index).getEndingPoint());
        }
        index++;
    }
}

Cab* TaxiCenter::getCab(int id) {
    for (Cab * &cab : listOfCabs){
        if(cab->getId() == id){
            return cab;
        }
    }
   throw "no cab found";
}