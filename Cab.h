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

public:
    Cab(int id, Model_Of_Car carModel, Color_Of_Car color);

    int getId() const;

    int getPassedKilometers() const;

    Model_Of_Car getCarModel() const;

    Color_Of_Car getColor() const;

    virtual double getSpeed() const = 0;

    virtual double getRate() const = 0;

};


#endif //EX2_CAB_H
