#ifndef EX2_LUXURYCAB_H
#define EX2_LUXURYCAB_H


#include "Cab.h"

class LuxuryCab: public Cab {
private:
    const double speed;
    const double rate;

public:
    LuxuryCab(int id, Model_Of_Car carModel, Color_Of_Car color);

    double getSpeed() const;

    double getRate() const;
};


#endif //EX2_LUXURYCAB_H
