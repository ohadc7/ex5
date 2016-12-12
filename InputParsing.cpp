#include <cstring>
#include "InputParsing.h"

InputParsing::InputParsing(string inputString) {
    string gridWidthString, gridHeightString;
    string sourcePointXString, sourcePointYString;
    string destinationPointXString, destinationPointYString;

    //parsing of the input
    string::size_type commaPosition = inputString.find(",");
    string gridSize = inputString.substr(0, commaPosition);
    string sourceAndDestinationPoints = inputString.substr(commaPosition + 1);
    commaPosition = sourceAndDestinationPoints.find(",");
    string sourcePointString = sourceAndDestinationPoints.substr(0, commaPosition);
    string destinationPointString = sourceAndDestinationPoints.substr(commaPosition + 1);
    string::size_type underlinePosition = gridSize.find("_");
    gridWidthString = gridSize.substr(0, underlinePosition);
    gridHeightString = gridSize.substr(underlinePosition + 1);
    underlinePosition = sourcePointString.find("_");
    sourcePointXString = sourcePointString.substr(0, underlinePosition);
    sourcePointYString = sourcePointString.substr(underlinePosition + 1);
    underlinePosition = destinationPointString.find("_");
    destinationPointXString = destinationPointString.substr(0, underlinePosition);
    destinationPointYString = destinationPointString.substr(underlinePosition + 1);

    gridWidth = stoi(gridWidthString);
    gridHeight = stoi(gridHeightString);
    sourcePointX = stoi(sourcePointXString);
    sourcePointY = stoi(sourcePointYString);
    destinationPointX = stoi(destinationPointXString);
    destinationPointY = stoi(destinationPointYString);
}

int InputParsing::getGridWidth() {
    return gridWidth;
}

int InputParsing::getGridHeight() {
    return gridHeight;
}

int InputParsing::getSourcePointX() {
    return sourcePointX;
}

int InputParsing::getSourcePointY() {
    return sourcePointY;
}

int InputParsing::getDestinationPointX() {
    return destinationPointX;
}

int InputParsing::getDestinationPointY() {
    return destinationPointY;
}

Grid InputParsing::getGrid() {
    return Grid(this->gridWidth, this->getGridHeight());
}

//new functions
InputParsing::gridDimensions InputParsing::getGridDimensions(string gridData) {
    return InputParsing::gridDimensions();
}

Point InputParsing::getPoint(string pointData) {
    vector<string> coordinates = this->splitStrings(pointData, 2);
    Point p = Point(stoi(coordinates[0]),stoi(coordinates[1]));
    return p;
}

InputParsing::driverWithVehicleId InputParsing::getDriver(string driverData) {
    vector<string> driverParameters = this->splitStrings(driverData, 5);
    Status_Of_Marriage driverStatus;
    if (driverParameters[2] == "S") {
        driverStatus = SINGLE;
    } else if (driverParameters[2] == "M") {
        driverStatus = MARRIED;
    } else if (driverParameters[2] == "D") {
        driverStatus = DIVORCED;
    } else if (driverParameters[2] == "W") {
        driverStatus = WIDOWED;
    }
    driverWithVehicleId driverStruct = {Driver(stoi(driverParameters[0]), stoi(driverParameters[1]),
                                               driverStatus, stoi(driverParameters[3])),
                                        stoi(driverParameters[4])};
    driverStruct.driver = Driver(stoi(driverParameters[0]), stoi(driverParameters[1]),
                                 driverStatus, stoi(driverParameters[3]));
    driverStruct.vehicleId = stoi(driverParameters[4]);
    return driverStruct;
}

Trip InputParsing::getTrip(string tripData) {
    return Trip();
}

Cab *InputParsing::getVehicle(string vehicleData) {
    return nullptr;
}

vector<string> InputParsing::splitStrings(string stringWithCommas, int numberOfSeparatedWords) {
    vector<string> separatedWords = vector<string>();
    for (int i = 1; i < numberOfSeparatedWords; i++) {
        string::size_type commaPosition = stringWithCommas.find(",");
        string nextWord = stringWithCommas.substr(0, commaPosition);
        separatedWords.push_back(nextWord);
        stringWithCommas = stringWithCommas.substr(commaPosition + 1);
    }
    separatedWords.push_back(stringWithCommas);
    return separatedWords;
}

