#ifndef EX2_LUXURYCAB_H
#define EX2_LUXURYCAB_H

#define SPEED_OF_LUXURY_CAB 2
#define RATE_OF_LUXURY_CAB 200

#include "Cab.h"

class LuxuryCab : public Cab {
private:
    const double speed;
    const double rate;

public:
    LuxuryCab(int id, Model_Of_Car carModel, Color_Of_Car color);

    virtual Taxi_Type getTaxiType();

    double getSpeed() const;

    double getRate() const;

    virtual ~LuxuryCab();
};


#endif //EX2_LUXURYCAB_H
