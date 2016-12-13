#include "Point.h"
#include "Grid.h"
#include <vector>
#include "Driver.h"

#ifndef EX1_VERSION_1_1_PROGRAMFLOW_H
#define EX1_VERSION_1_1_PROGRAMFLOW_H

//enum Status_of_Marriage {SINGLE, MARRIED, DIVORCED, WIDOWED};

class ProgramFlow {
public:
    void run();
    void createTaxiCenter();
    void createDriver(int id, int age, Status_Of_Marriage status, int yearsOfExperience);
    void createCab(int id);
    void createGrid(int width, int height, vector<Point> listOfObstacles);
};


#endif //EX1_VERSION_1_1_PROGRAMFLOW_H
