#include "Point.h"
#include "Grid.h"
#include <vector>
#include "Driver.h"
#include "BfsAlgorithm.h"
#include "TaxiCenter.h"

#ifndef EX1_VERSION_1_1_PROGRAMFLOW_H
#define EX1_VERSION_1_1_PROGRAMFLOW_H


class ProgramFlow {
public:
    void run();

    TaxiCenter createTaxiCenter(BfsAlgorithm<Point> bfs);

    Driver createDriver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, Cab* cab);

    Cab * createCab(int id,int cabType, Model_Of_Car carModel, Color_Of_Car color);

    BfsAlgorithm<Point> createGrid(int width, int height, vector<Point> listOfObstacles);
};

#endif //EX1_VERSION_1_1_PROGRAMFLOW_H
