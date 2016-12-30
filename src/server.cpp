#include <string>
#include "ProgramFlow.h"
#include "SerializationClass.h"

using namespace std;

int main(int argc, char *argv[]) {
    Socket* socket = nullptr;
    if (argc == 2) {
        int port = stoi(argv[1]);
        // 1: isServer = true,
        // port: port id that the server has to wait to massages of clients.
        socket = new Udp(1, port);
        socket->initialize();
        char buffer[1024];
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
        socket->sendData("main(): massage1 from server to client");


        //serialization:
        Point pointThatTheServerIsCreating = Point(1,5);

        //string to maintain the serializied object:

        SerializationClass<Point> serializeClass;

        std::string serial_str;
        serial_str = serializeClass.serializationObject(pointThatTheServerIsCreating);

        cout << "the string before deserialization is " << serial_str << endl;

        //pass to client
        socket->sendData(serial_str);
        ProgramFlow programFlow;
        programFlow.run(socket);
    }
    delete socket;
    return 0;
}
