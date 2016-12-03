#include "Passenger.h"

Passenger::Passenger(Point source, Point destination, bool isLuxury):
        source(source), destination(destination), isLuxury(isLuxury){}

int Passenger::getSatisfaction() const{
    return satisfactionNum;
}

bool Passenger::getIsLuxury() {
    return false;
}

void Passenger::setSatisfaction(int satisfaction){
    satisfactionNum = satisfaction;
}
