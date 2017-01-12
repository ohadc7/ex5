//
// Created by ohad on 12/01/17.
//

#include "Socket.h"
#include "Connection.h"
/*
Connection::Connection(int socketDescriptor, struct sockaddr *client_sin, unsigned int *addr_len) {
    this->socketDescriptor = socketDescriptor;
    this->client_sin =  client_sin;
    this->addr_len = addr_len;
}*/

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


