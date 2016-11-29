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

int InputParsing::getgridWidth() {
    return gridWidth;
}

int InputParsing::getgridHeight() {
    return gridHeight;
}

int InputParsing::getsourcePointX() {
    return sourcePointX;
}

int InputParsing::getsourcePointY() {
    return sourcePointY;
}

int InputParsing::getdestinationPointX() {
    return destinationPointX;
}

int InputParsing::getdestinationPointY() {
    return destinationPointY;
}