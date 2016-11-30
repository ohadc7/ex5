#ifndef EX2_LUXURYCAB_H
#define EX2_LUXURYCAB_H


#include "Cab.h"

class LuxuryCab: public Cab {
private:
    const int speed;
public:
    double getSpeed() const;

    double getRate() const;
};


#endif //EX2_LUXURYCAB_H
