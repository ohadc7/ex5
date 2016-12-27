//#define DEBUG_MAIN
#include <string>
#include "ProgramFlow.h"

using namespace std;

int main(int argc, char *argv[]) {
    Socket* socket = nullptr;
    if (argc == 2) {
        int port = stoi(argv[1]);
        // 1: isServer = true,
        // port: port id that the server has to wait to massages of clients.
        socket = new Udp(1, port);
        socket->initialize();

#ifdef DEBUG_MAIN
        char buffer[1024];
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
        socket->sendData("main(): massage from server to client");
#endif

        ProgramFlow programFlow;
        programFlow.run(socket);
    }
    else if (argc == 3) {
        int port = atoi(argv[2]);
        // 0: isServer = false,
        // port: port id that the server waits to our massages. we will send massages to there.
        socket = new Udp(0, port);
        socket->initialize();

#ifdef DEBUG_MAIN
        char buffer[1024];
        socket->sendData("main(): massage from client to server");
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
#endif

        InputParsing inputParsing = InputParsing();
        string inputString;
        getline(cin, inputString);
        InputParsing::parsedDriverData driverData = inputParsing.parseDriverData(inputString);
        try {
            Driver driver = Driver(driverData.id, driverData.age, driverData.status, driverData.yearsOfExperience,
                                   driverData.vehicleId);
            driver.run(socket);
        } catch (const char *msg) {
            cerr << msg << endl;
        }
    } else {
        //ProgramFlow programFlow;
        //programFlow.run();
    }

    delete socket;
    return 0;
}
