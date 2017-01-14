//
// Created by ohad on 12/01/17.
//

#ifndef EX5_CONNECTION_H
#define EX5_CONNECTION_H

#include <vector>
#include "TaxiCenter.h"


using namespace std;
class Connection {

private:
    int socketDescriptor;

    vector<int> vectorOfClientsDescriptor;

public:
    //Connection(int socketDescriptor, struct sockaddr_in client_sin, unsigned int *addr_len);

    Connection(int socketDescriptor);
    void makeConnect(void * socket, TaxiCenter *taxiCenter);

    vector<int> getVectorOfClientsDescriptor();
    struct socketAndDescriptor{
        void* socket;
        int socketDescriptor;
        TaxiCenter *taxiCenter;
    };
};


#endif //EX5_CONNECTION_H
