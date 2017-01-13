//
// Created by ohad on 12/01/17.
//

#include "Socket.h"
#include "Connection.h"
#include "ProgramFlow.h"


struct socketAndTheards{
    Socket socket;

};

void Connection::makeConnect() {
    struct sockaddr_in client_sin;
    unsigned int addr_len;
    addr_len = sizeof(client_sin);
    cout << "accept" << endl;
    int descriptor = accept(this->socketDescriptor,
                            (struct sockaddr *) &client_sin, &addr_len);
    this->vectorOfClientsDescriptor.push_back(descriptor);
    cout << "send" << endl;

}




vector<int> Connection::getVectorOfClientsDescriptor() {
    return this->vectorOfClientsDescriptor;
}

Connection::Connection(int socketDescriptor) {
    this->socketDescriptor = socketDescriptor;

}

void Connection::runTheards() {
   // pthread_t bfsTheard;
   // pthread_create(&bfsTheard, NULL, ProgramFlow::run,(void*) socket);
  //  pthread_t clientTheard;
   // pthread_create(&clientTheard, NULL, ProgramFlow::run, (void*)socketAndTheards);

}


