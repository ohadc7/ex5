//#define DEBUG_DRIVER //define it if and only if you defined DEBUG_PROGRAM_FLOW on server

#include "Driver.h"
#include "SerializationClass.h"
#include "CabFactory.h"

Driver::Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, int vehicleId) :
        id(id), age(age), status(status), yearsOfExperience(yearsOfExperience),
        vehicleId(vehicleId),currentLocation(0,0) {
    numOfTrips = 1;
    averageSatisfactions = 0;
    currentTrip = nullptr;
    
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
#ifdef DEBUG_DRIVER
    /*
    cout << "Driver.moveOneStep(): method is starting" << endl;
    std::list<Point> mylist();
    //list<Point>::iterator it = mylist().begin();
    list<Point> l = currentTrip->getPath();
    list<Point>::iterator it = l.begin();
    for (list<Point>::iterator it = l.begin() ; it != l.end(); ++it) {
        cout << "Point from path is " << *it << "." << endl;
    }
     */
#endif
    //if no current trip, return:
    if (this->currentTrip == nullptr) {
        return;
    }
    //if the driver has LuxuryCab, he has to skip one point of the path:
    if (this->cabOfDriver->getTaxiType() == LUXURY_CAB &&
            this->currentTrip->getPath().size() > 1) {
        this->currentTrip->removeNextPointOfPath();
    }
    //move to the next point (one block):

    Point locationAfterStep = this->currentTrip->getPath().front();
    this->currentTrip->removeNextPointOfPath();
    //Point locationAfterStep = nextPointOfPath.getValue();
    this->setCurrentLocation(locationAfterStep);
    //if the path was terminated, set "currentTrip" member to NULL:
    if (this->currentTrip->getPath().size() == 0) {
        this->currentTrip = nullptr;
    }
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
    socket->reciveData(buffer, sizeof(buffer));
    string cabDataString = string(buffer);
    cabOfDriver = CabFactory::createCab(cabDataString);


#if 0
#ifdef DEBUG_DRIVER
    cout << "Driver.run(): Now the driver is expecting to receive number of taxi type" << endl;
#endif
    //receive cab
    socket->reciveData(buffer, sizeof(buffer));
    string numberOfTaxiType(buffer, sizeof(buffer));

    socket->reciveData(buffer, sizeof(buffer));
    string cabId(buffer, sizeof(buffer));
    socket->reciveData(buffer, sizeof(buffer));
    string cabModel(buffer, sizeof(buffer));
    socket->reciveData(buffer, sizeof(buffer));
    string cabColor(buffer, sizeof(buffer));


#ifdef DEBUG_DRIVER
    cout << "Driver.run(): Number of taxi type is " << numberOfTaxiType << endl;
    //cout << "Driver.run(): Now the driver is expecting to receive serialized cab" << endl;
#endif
    //receive cab
    /*
    socket->reciveData(buffer, sizeof(buffer));
    string serializedCab(buffer, sizeof(buffer));
     */
    if (stoi(numberOfTaxiType) == 1) {
        //SerializationClass<StandardCab> serializeClass;
        //StandardCab receivedStandardCab = serializeClass.deSerializationObject(serializedCab, receivedStandardCab);
        cabOfDriver = new StandardCab(stoi(cabId), stoi(cabModel), stoi(cabColor));;
    } else {
        //SerializationClass<LuxuryCab> serializeClass;
        //LuxuryCab receivedLuxuryCab = serializeClass.deSerializationObject(serializedCab, receivedLuxuryCab);
        cabOfDriver = new LuxuryCab(cabId, cabModel, cabColor);
    }
    /*
    socket->reciveData(buffer, sizeof(buffer));
    string serializedCab(buffer, sizeof(buffer));
    SerializationClass<Cab*> serializeClass;
    cabOfDriver =
            serializeClass.deSerializationObject(serializedCab, cabOfDriver);
    */
#endif
#ifdef DEBUG_DRIVER
    cout << "Driver.run(): driver received string with data of cab and pasrsed it.\n the cab has the following data:"
         << "\n taxi type is: " <<
         this->cabOfDriver->getTaxiType()
         << "\n id of cab is: " <<
         this->cabOfDriver->getId()
         << "\n car model is " <<
         this->cabOfDriver->getCarModel() <<
         endl;
#endif

#ifdef DEBUG_DRIVER
    cout << "Driver.run(): Now the driver is starting a loop and expecting to receive numbers of options in order to know its next steps" << endl;
#endif
    while (true) {
        socket->reciveData(buffer, sizeof(buffer));
        string numberOfOption = string(buffer);
        switch (stoi(numberOfOption)) {
            case 4: {
#ifdef DEBUG_DRIVER
                cout << "Driver.run(): option 4 has been selected." << endl;
                cout << "my location is " << this->currentLocation << ". I am sending my current place to the server." << endl;
#endif
                //serialization:
                SerializationClass<Point> serializeClass;
                string serializedPointStr = serializeClass.serializationObject(this->currentPlace());
                //pass point to server
                socket->sendData(serializedPointStr);
                break;
            }
            case 7: {
                //terminate the program
                return;
            }
            case 9: {
#ifdef DEBUG_DRIVER
                cout << "Driver.run(): option 9 has been selected." << endl;
                cout << "calling to method moveOneStep()" << endl;
#endif
                moveOneStep();
                break;
            }
            //option 10: assign a trip.
            case 10: {
#ifdef DEBUG_DRIVER
                cout << "Driver.run(): option 10 has been selected." << endl;
                cout << "expecting to receive serialized Trip*." << endl;
#endif
                socket->reciveData(buffer, sizeof(buffer));
                string strTrip(buffer, sizeof(buffer));
                SerializationClass<Trip *> serializeTripClass;
                Trip *trip;
                trip = serializeTripClass.deSerializationObject(strTrip, trip);
#ifdef DEBUG_DRIVER
                cout<< "the Trip has been received. ride Id is:" << trip->getRideId() << endl;
#endif
                assignTrip(trip);
                break;
            }
            default: {
#ifdef DEBUG_DRIVER
                cout << "Driver.run(): the driver received invalid number of option. do nothing and break." << endl;
#endif
                break;
            }
        }
    }
}