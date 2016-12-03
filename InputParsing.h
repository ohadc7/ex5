#ifndef EX1_VERSION_1_1_INPUTPARSING_H
#define EX1_VERSION_1_1_INPUTPARSING_H

#include <iostream>
#include <list>
#include "Grid.h"

using namespace std;
class InputParsing {
private:
    int gridWidth;
    int gridHeight;
    int sourcePointX;
    int sourcePointY;
    int destinationPointX;
    int destinationPointY;
    list<Point> obstacles;
public:
    InputParsing(string inputString);
    int getGridWidth();
    int getGridHeight();
    int getSourcePointX();
    int getSourcePointY();
    int getDestinationPointX();
    int getDestinationPointY();
    Grid getGrid();
};


#endif //EX1_VERSION_1_1_INPUTPARSING_H
