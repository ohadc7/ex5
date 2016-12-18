#ifndef EX2_STANDARDCAB_H
#define EX2_STANDARDCAB_H

#define SPEED_OF_STANDARD_CAB 1
#define RATE_OF_STANDARD_CAB  100

#include "Cab.h"

class StandardCab : public Cab {
private:
    const double speed;
    const double rate;
public:
    StandardCab(int id, Model_Of_Car carModel, Color_Of_Car color);

    double getSpeed() const;

    double getRate() const;

    virtual ~StandardCab();
};


#endif
