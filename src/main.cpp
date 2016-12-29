#define DEBUG_MAIN
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
        socket->sendData("main(): massage1 from server to client");


        //serialization:
        Point *pointThatTheServerIsCreating = new Point(1,5);
        //string to maintain the serializied object:
        std::string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << pointThatTheServerIsCreating;
        s.flush();
        cout << "the string before deserialization is " << serial_str << endl;

        //pass to client
        socket->sendData(serial_str);
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
        socket->sendData("main(): massage1 from client to server");
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;


        socket->reciveData(buffer, sizeof(buffer));
        char* serial_str_that_the_server_sended_to_us;
        Point pointThatTheClientWantToReceiveFromServer;
        string str(buffer, sizeof(buffer));
        boost::iostreams::basic_array_source<char> device(str.c_str(), str.size());
        //boost::iostreams::basic_array_source<char> device(serial_str_that_the_server_sended_to_us.c_str(), serial_str_that_the_server_sended_to_us.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> pointThatTheClientWantToReceiveFromServer;

        cout << pointThatTheClientWantToReceiveFromServer;
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
