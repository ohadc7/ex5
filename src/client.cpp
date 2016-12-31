#define DEBUG_CLIENT

#include <string>
#include "ProgramFlow.h"
#include "SerializationClass.h"

using namespace std;

int main(int argc, char *argv[]) {
    Socket* socket = nullptr;
    if (argc == 3) {
        int port = atoi(argv[2]);
        // 0: isServer = false,
        // port: port id that the server waits to our massages. we will send massages to there.
        socket = new Udp(0, port);
        socket->initialize();
        char buffer[1024];
        socket->sendData("main(): massage1 from client to server");
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;


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

        InputParsing inputParsing = InputParsing();
        string inputString;
        getline(cin, inputString);
        InputParsing::parsedDriverData driverData = inputParsing.parseDriverData(inputString);
        try {
            Driver driver = Driver(driverData.id, driverData.age, driverData.status, driverData.yearsOfExperience,
                                   driverData.vehicleId);
#ifdef DEBUG_CLIENT
            cout << "starting to run programFlow.run: " << endl;
#endif
            driver.run(socket);
        } catch (const char *msg) {
            cerr << msg << endl;
        }
    }
    delete socket;
    return 0;
}
