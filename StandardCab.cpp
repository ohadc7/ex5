#include "StandardCab.h"
const double SPEED_OF_STANDARD_CAB = 1;
const double RATE_OF_STANDARD_CAB = 100;
StandardCab::StandardCab(int id, Model_Of_Car carModel, Color_Of_Car color) :
        Cab(id, carModel, color), speed(SPEED_OF_STANDARD_CAB), rate(RATE_OF_STANDARD_CAB) {}

double StandardCab::getSpeed() const {
    return 0;
}

double StandardCab::getRate() const {
    return 0;
}

StandardCab::~StandardCab() {

}
