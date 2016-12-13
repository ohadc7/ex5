#include <cstring>
#include "InputParsing.h"

InputParsing::InputParsing() {}

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
InputParsing::gridDimensions InputParsing::parseGridDimensions(string gridData) {
    InputParsing::gridDimensions dimensions;
    string::size_type spacePosition = gridData.find(" ");
    int width = stoi(gridData.substr(0, spacePosition));
    int height = stoi(gridData.substr(spacePosition + 1));
    dimensions.gridHeight = height;
    dimensions.gridWidth = width;
    return dimensions;
}

Point InputParsing::parsePoint(string pointData) {
    vector<string> coordinates = this->splitStrings(pointData, 2);
    Point p = Point(stoi(coordinates[0]),stoi(coordinates[1]));
    return p;
}

InputParsing::parsedDriverData InputParsing::parseDriverData(string driverData) {
    vector<string> listOfStringsOfDriverParameters = this->splitStrings(driverData, 5);
    Status_Of_Marriage driverStatus;
    //fix status of marriage according to the character in the third string of the list (S/M/D/W)
    if (listOfStringsOfDriverParameters[2] == "S") {
        driverStatus = SINGLE;
    } else if (listOfStringsOfDriverParameters[2] == "M") {
        driverStatus = MARRIED;
    } else if (listOfStringsOfDriverParameters[2] == "D") {
        driverStatus = DIVORCED;
    } else if (listOfStringsOfDriverParameters[2] == "W") {
        driverStatus = WIDOWED;
    }
    /*
    //create Driver
    Driver driver = Driver(stoi(listOfStringsOfDriverParameters[0]), stoi(listOfStringsOfDriverParameters[1]),
                           driverStatus, stoi(listOfStringsOfDriverParameters[3]));
    int vehicleId = stoi(listOfStringsOfDriverParameters[4]);
     */
    /*
    //create driverWithVehicleId struct
    driverWithVehicleId driverWithVehicleIdStruct = {driver,
                                                     vehicleId};
    */
    parsedDriverData driverParameters;
    driverParameters.id = stoi(listOfStringsOfDriverParameters[0]);
    driverParameters.age = stoi(listOfStringsOfDriverParameters[1]);
    driverParameters.status = driverStatus;
    driverParameters.yearsOfExperience = stoi(listOfStringsOfDriverParameters[3]);
    driverParameters.vehicleId = stoi(listOfStringsOfDriverParameters[4]);
    return driverParameters;
}

InputParsing::parsedTripData InputParsing::parseTripData(string tripData) {
    vector<string> listOfStringsOfTripParameters = this->splitStrings(tripData, 7);
    InputParsing::parsedTripData tripParameters;
    tripParameters.id = stoi(listOfStringsOfTripParameters[0]);
    int x = stoi(listOfStringsOfTripParameters[1]);
    int y = stoi(listOfStringsOfTripParameters[2]);
    tripParameters.start = Point(x,y);
    x = stoi(listOfStringsOfTripParameters[3]);
    y = stoi(listOfStringsOfTripParameters[4]);
    tripParameters.end = Point(x,y);
    tripParameters.numberOfPassengers = stoi(listOfStringsOfTripParameters[5]);
    tripParameters.tariff = stod(listOfStringsOfTripParameters[6]);
    return tripParameters;
}

InputParsing::parsedCabData InputParsing::parseVehicleData(string vehicleData) {
    return parsedCabData{};
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



