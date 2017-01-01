//
// Created by ohad on 01/01/17.
//

#ifndef EX4_CABFACTORY_H
#define EX4_CABFACTORY_H
#include "Cab.h"
#include "InputParsing.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

class CabFactory {
public:
    static Cab *createCab(string inputString);
    static Cab *createCab(int id, int cabType, Model_Of_Car carModel, Color_Of_Car color);
};


#endif //EX4_CABFACTORY_H
