#ifndef EX2_STANDARDCAB_H
#define EX2_STANDARDCAB_H


#include "Cab.h"

class StandardCab: public Cab {
private:
    const double speed;
    const double rate;
public:
    StandardCab(int id, Model_Of_Car carModel, Color_Of_Car color);

    double getSpeed() const;

    double getRate() const;

};


#endif //EX2_STANDARDCAB_H
