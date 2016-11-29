#include "Point.h"
#include <vector>


#ifndef EX1_VERSION_1_1_PROGRAMFLOW_H
#define EX1_VERSION_1_1_PROGRAMFLOW_H

enum Status_of_Marriage {SINGLE, MARRIED, DIVORCED, WIDOWED};

class ProgramFlow {
public:
    void createTaxiCenter();
    void createDriver(int id, int age, Status_of_Marriage status, int yearsOfExperience);
    void createCab(int id);
    void createMap(int width, int height, vector<Point> listOfObstacles);
};


#endif //EX1_VERSION_1_1_PROGRAMFLOW_H
