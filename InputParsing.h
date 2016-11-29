#ifndef EX1_VERSION_1_1_INPUTPARSING_H
#define EX1_VERSION_1_1_INPUTPARSING_H

#include <iostream>

using namespace std;
class InputParsing {
private:
    int gridWidth;
    int gridHeight;
    int sourcePointX;
    int sourcePointY;
    int destinationPointX;
    int destinationPointY;
public:
    InputParsing(string inputString);
    int getgridWidth();
    int getgridHeight();
    int getsourcePointX();
    int getsourcePointY();
    int getdestinationPointX();
    int getdestinationPointY();

};


#endif //EX1_VERSION_1_1_INPUTPARSING_H
