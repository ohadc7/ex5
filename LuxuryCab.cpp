#include "LuxuryCab.h"
const double SPEED_OF_LUXURY_CAB = 2;
const double RATE_OF_LUXURY_CAB = 200;
LuxuryCab::LuxuryCab(int id, Model_Of_Car carModel, Color_Of_Car color) : Cab(id, carModel, color),
                                    speed(SPEED_OF_LUXURY_CAB), rate(RATE_OF_LUXURY_CAB) {}

double LuxuryCab::getSpeed() const {
    return 0;
}

double LuxuryCab::getRate() const {
    return 0;
}


