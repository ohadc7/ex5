#ifndef EX1_VERSION_1_1_INPUTPARSING_H
#define EX1_VERSION_1_1_INPUTPARSING_H

#include <iostream>
#include <list>
#include "Grid.h"
#include "Driver.h"

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

    vector<string> splitStrings(string stringWithCommas, int numberOfSeparatedWords);
public:
    InputParsing(string inputString);
    int getGridWidth();
    int getGridHeight();
    int getSourcePointX();
    int getSourcePointY();
    int getDestinationPointX();
    int getDestinationPointY();
    Grid getGrid();

    //new functions:
    typedef struct {
        int gridWidth;
        int gridHeight;
    } gridDimensions;
    //"gridData" string format: "gridWidth gridHeight" (int int). example: 3 3
    gridDimensions getGridDimensions(string gridData);
    //"pointData" string format: "Xcoordinate,Ycoordinate" (int,int). example: 0,0
    Point getPoint(string pointData);

    typedef struct {
        Driver driver;
        int vehicleId;
    } driverWithVehicleId;
    /*
     * "driverData" string format: "id,age,status,experience,vehicleId"
     * (int,int,char:{S,M,D,W},int,int)
     *'status' is one of the following letters:
     * S / M / D / W  (represents: Single / Married / Divorced / Widowed)
     * example: 123456789,30,M,5,1122233
     */
    driverWithVehicleId getDriver(string driverData);

    /*
     * "tripData" string format: "id,xStart,yStart,xEnd,yEnd,numPassengers,tariff"
     * (int,int,int,int,int,int,double)
     */
    Trip getTrip(string tripData);

    /*
     * "vehicleData" string format: "id,taxiType,manufacturer,color"
     * (int,{1:NormalCab,2:LuxuryCab},char:{H,S,T,F},char:{R,B,G,P,W})
     * 'taxiType' is one of the following characters:
     * 1 / 2 (represents: StandardCab / LuxuryCab).
     * 'manufacturer' is one of the following letters:
     * H / S / T / F (represents: HONDA, SUBARO, TESLA, FIAT)
     * 'color' is one of the following letters:
     * R / B / G / P / W (represents: RED, BLUE, GREEN, PINK, WHITE)
     */
    Cab* getVehicle(string vehicleData);
};


#endif //EX1_VERSION_1_1_INPUTPARSING_H
