#ifndef EX2_CAB_H
#define EX2_CAB_H

enum Model_Of_Car {
    HONDA, SUBARO, TESLA, FIAT
};
enum Color_Of_Car {
    RED, BLUE, GREEN, PINK, WHITE
};
typedef enum {
    STANDARD_CAB = 1, LUXURY_CAB = 2
} Taxi_Type;

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

    virtual Taxi_Type getTaxiType() = 0;

    virtual ~Cab();

};


#endif //EX2_CAB_H
