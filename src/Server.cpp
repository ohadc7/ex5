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

        ProgramFlow programFlow;
        programFlow.run(socket);
    }
    delete socket;
    return 0;
}

