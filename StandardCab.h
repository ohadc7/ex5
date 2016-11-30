#ifndef EX2_STANDARDCAB_H
#define EX2_STANDARDCAB_H


#include "Cab.h"

class StandardCab: public Cab {
private:
    const int speed;
public:
    double getSpeed() const;

    double getRate() const;

};


#endif //EX2_STANDARDCAB_H
