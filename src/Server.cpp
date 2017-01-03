//#define DEBUG_SERVER //define it if and only if you defined DEBUG_CLIENT on client

#include <string>
#include "ProgramFlow.h"

using namespace std;

int main(int argc, char *argv[]) {
    Socket* socket = NULL;
    if (argc == 2) {
        int port = stoi(argv[1]);
        // 1: isServer = true,
        // port: port id that the server has to wait to massages of clients.
        socket = new Udp(1, port);
        socket->initialize();

#ifdef DEBUG_SERVER //we have to delete this part in the final version
        char buffer[1024];
        socket->reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
        socket->sendData("main(): massage1 from server to client");
#endif

#if 0
        //serialization:
        Point pointThatTheServerIsCreating = Point(1,5);

        //string to maintain the serializied object:

        SerializationClass<Point> serializeClass;

        std::string serial_str;
        serial_str = serializeClass.serializationObject(pointThatTheServerIsCreating);

        cout << "the string before deserialization is " << serial_str << endl;

        //pass point to client
        socket->sendData(serial_str);


        //serialize trip and pass trip to client
        SerializationClass<Trip*> serializeTrip;
        Graph<Point> *g = new Grid(9,9);
        BfsAlgorithm<Point> bfs(g);
        Node<Point> startNode(Point(0,0));
        Node<Point> endNode(Point(3,3));
        stack<Node<Point>> pathOfNodes = bfs.navigate(startNode, endNode);
        Trip trip = Trip(12, Point(0,1), Point(5,5), 2, 200, pathOfNodes);
        Trip* pointerToTrip = &trip;
        std::string serial_str_for_trip;
        serial_str_for_trip = serializeTrip.serializationObject(pointerToTrip);

        socket->sendData(serial_str_for_trip);
#endif

#ifdef DEBUG_SERVER
        cout << "starting to run programFlow.run: " << endl;
#endif
        ProgramFlow programFlow;
        programFlow.run(socket);
    }
    delete socket;
    return 0;
}

