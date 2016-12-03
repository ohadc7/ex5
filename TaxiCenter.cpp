#include "TaxiCenter.h"

Trip TaxiCenter::createTrip(Driver driver, Passenger passenger) {
    return Trip();
}

Driver TaxiCenter::chooseBestDriver(Passenger passenger) {
    return Driver(0, 0, MARRIED, 0);
}

void TaxiCenter::sendTaxi(Trip trip) {

}

void TaxiCenter::addDriver(Driver driver) {

}

void TaxiCenter::orderATrip(Passenger passenger) {

}

const list <Driver> &TaxiCenter::getListOfDrivers() const {
    return listOfDrivers;
}

const list <Trip> &TaxiCenter::getListOfTrips() const {
    return listOfTrips;
}

Point TaxiCenter::getDriverLocation(Driver driver) {
    return Point(0,0);
}

TaxiCenter::TaxiCenter(BfsAlgorithm<Point> &bfsInstance) : bfsInstance(bfsInstance) {}
