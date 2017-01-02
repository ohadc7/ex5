//#define DEBUG_CLIENT //define it if and only if you defined DEBUG_SERVER on server

#include <string>
#include "ProgramFlow.h"

BOOST_CLASS_EXPORT_GUID(StandardCab, "StandardCab")
BOOST_CLASS_EXPORT_GUID(LuxuryCab, "LuxuryCab")

using namespace std;

int main(int argc, char *argv[]) {
    Socket* socket = nullptr;
    if (argc == 3) {
        int port = atoi(argv[2]);
        // 0: isServer = false,
        // port: port of the client
        socket = new Udp(0, port);
        socket->initialize();

#ifdef DEBUG_CLIENT //we have to delete this part in the final version
        char buffer[1024];
        socket->sendData("main(): massage1 from client to server");
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
#endif

#if 0
        socket->reciveData(buffer, sizeof(buffer));
        Point pointThatTheClientWantToReceiveFromServer;
        string str(buffer, sizeof(buffer));
        SerializationClass<Point> serializeClass;
        pointThatTheClientWantToReceiveFromServer =
                serializeClass.deSerializationObject(str, pointThatTheClientWantToReceiveFromServer);
        socket->reciveData(buffer, sizeof(buffer));
        string strTrip(buffer, sizeof(buffer));
        SerializationClass<Trip *> serializeClass1;
        Trip *trip;
        trip = serializeClass1.deSerializationObject(strTrip,trip);
       

        //for checking that trip deSerilaized works
        cout<< "num of Points (or maybe num of Passengers): " << trip->getNumberOfPassengers() << "," "ride Id:" << trip->getRideId() << "\n";
        //for checking that point deSerilaized works
        cout << pointThatTheClientWantToReceiveFromServer << "\n";
#endif
        InputParsing inputParsing = InputParsing();
        string inputString;
        getline(cin, inputString);
        InputParsing::parsedDriverData driverData = inputParsing.parseDriverData(inputString);
        try {
            Driver driver = Driver(driverData.id, driverData.age, driverData.status, driverData.yearsOfExperience,
                                   driverData.vehicleId);
#ifdef DEBUG_CLIENT
            cout << "starting to run driver.run: " << endl;
#endif
            driver.run(socket);
        } catch (const char *msg) {
            cerr << msg << endl;
        }
    }
    delete socket;
    return 0;
}
