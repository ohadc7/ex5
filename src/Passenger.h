
#ifndef EX1_VERSION_1_1_PASSENGER_H
#define EX1_VERSION_1_1_PASSENGER_H


#include "Point.h"

class Passenger {
private:
    Point source;
    Point destination;
    bool isLuxury;

public:
    Passenger(Point source, Point destination, bool isLuxury);

    int getSatisfaction() const;

    bool getIsLuxury();

    int giveFeedBack();
};


#endif
