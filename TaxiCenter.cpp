#include "TaxiCenter.h"
#include "InputParsing.h"

void TaxiCenter::createTrip(InputParsing::parsedTripData parsedTripDatarip) {
    Trip trip(parsedTripDatarip.id, parsedTripDatarip.start, parsedTripDatarip.end,
              parsedTripDatarip.numberOfPassengers, parsedTripDatarip.tariff);
    listOfTrips.push_back(trip);
}

Driver TaxiCenter::chooseBestDriver(Passenger passenger) {
    return Driver(0, 0, MARRIED, 0, nullptr);
}

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
