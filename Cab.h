#ifndef EX2_CAB_H
#define EX2_CAB_H

enum Model_Of_Car {HONDA, SUBARO, TESLA, FIAT};
enum Color_Of_Car {RED, BLUE, GREEN, PINK, WHITE};

class Cab {
private:
    int id;
    int passedKilometers;
    Model_Of_Car carModel;
    Color_Of_Car color;
    double rate;   //tariff
};


#endif //EX2_CAB_H
