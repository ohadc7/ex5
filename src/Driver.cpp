#define DEBUG_DRIVER //define it if and only if you defined DEBUG_PROGRAM_FLOW on server

#include "Driver.h"
#include "InputParsing.h"

Driver::Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, int vehicleId) :
        id(id), age(age), status(status), yearsOfExperience(yearsOfExperience),
        vehicleId(vehicleId) {
    numOfTrips = 1;
    averageSatisfactions = 0;
}

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

double Driver::getSatisfactions() const {
    return averageSatisfactions;
}

Cab* Driver::getInfoCab() const{
    return cabOfDriver;
}

Point Driver::currentPlace() {
    return currentLocation;
}

void Driver::clientSatisfactions(int clientSatisfactions){
    if((numOfTrips==0) || (numOfTrips ==1)){
        averageSatisfactions = clientSatisfactions;
    }else{
        averageSatisfactions = (averageSatisfactions+clientSatisfactions)/numOfTrips;
    }
    if(averageSatisfactions>5){
        averageSatisfactions=5;
    }else if(averageSatisfactions<1){
        averageSatisfactions =1;
    }
    numOfTrips++;
}

bool Driver::isAvailable() {
    return currentTrip != NULL;
}

void Driver::attachCabToDriver(Cab *infoCab) {
    cabOfDriver = infoCab;
}

vector<Passenger> Driver::getListOfPassengers() const{
    return listOfPassengers;
}

void Driver::addPassenger(Passenger passenger) {
    listOfPassengers.push_back(passenger);
}

void Driver::setCurrentLocation(Point point) {
    currentLocation = point;
}

void Driver::assignTrip(Trip *trip) {
    //if (this->isAvailable()) {
        currentTrip = trip;
    //}
}

void Driver::moveOneStep() {
    //if no current trip, return:
    if (this->currentTrip == NULL) {
        return;
    }
    //if the driver has LuxuryCab, he has to skip one point of the path:
   /* if (this->cabOfDriver->getTaxiType() == LUXURY_CAB &&
            this->currentTrip->getPath().size() > 1) {
        this->currentTrip->removeNextPointOfPath();
    }
    //move to the next point (one block):
    Node<Point> nextNodeOfPath = this->currentTrip->getPath().top();
    this->currentTrip->removeNextPointOfPath();
    Point locationAfterStep = nextNodeOfPath.getValue();
    this->setCurrentLocation(locationAfterStep);
    //if the path was terminated, set "currentTrip" member to NULL:
    if (this->currentTrip->getPath().size() == 0) {
        this->currentTrip = NULL;
    }*/
    return;
}

void Driver::run(Socket *socket) {
    char buffer[1024];
#ifdef DEBUG_DRIVER
    socket->sendData("Driver.run(): massage from client to server");
    socket->reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
#endif

    stringstream ss;
    ss << this->id;
    socket->sendData(ss.str());
}
