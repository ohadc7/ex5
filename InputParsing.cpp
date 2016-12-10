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
    return Point();
}

Driver InputParsing::getDriver(string driverData) {
    return Driver(0, 0, MARRIED, 0);
}

Trip InputParsing::getTrip(string tripData) {
    return Trip();
}

Cab *InputParsing::getVehicle(string vehicleData) {
    return nullptr;
}

list <string> InputParsing::splitStrings(string stringWithCommas, int numberOfSeparatedWords) {
    list<string> separatedWords = list<string>();
    for (int i = 1; i < numberOfSeparatedWords; i++) {
        string::size_type commaPosition = stringWithCommas.find(",");
        string nextWord = stringWithCommas.substr(0, commaPosition);
        separatedWords.push_back(nextWord);
        stringWithCommas = stringWithCommas.substr(commaPosition + 1);
    }
    return list<string>();
}

