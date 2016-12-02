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
    int getgridWidth();
    int getgridHeight();
    int getsourcePointX();
    int getsourcePointY();
    int getdestinationPointX();
    int getdestinationPointY();
    Grid getGrid();
};


#endif //EX1_VERSION_1_1_INPUTPARSING_H
