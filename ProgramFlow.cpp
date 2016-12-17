#include <string>
#include <iostream>
#include "ProgramFlow.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

using namespace std;

TaxiCenter ProgramFlow::createTaxiCenter(BfsAlgorithm<Point> bfs) {
    return TaxiCenter(bfs);
}

Driver ProgramFlow::createDriver(int id, int age, Status_Of_Marriage status,
                                 int yearsOfExperience, Cab *cab) {
    return Driver(id, age, status, yearsOfExperience, cab);
}


Cab *ProgramFlow::createCab(int id, int cabType, Model_Of_Car carModel, Color_Of_Car color) {
    if (cabType == 1) {
        Cab *standard = new StandardCab(id, carModel, color);
        return standard;
    } else {
        Cab *luxury = new LuxuryCab(id, carModel, color);
        return luxury;
    }
}


Graph<Point> *ProgramFlow::createGrid(int width, int height, vector<Point> listOfObstacles) {
    Graph<Point> *g = new Grid(width, height, listOfObstacles);
    return g;
}

int ProgramFlow::run(istream &inputStream) {
    string inputString;
    getline(inputStream, inputString);
    InputParsing inputParsing = InputParsing();
    InputParsing::gridDimensions gd = inputParsing.parseGridDimensions(inputString);
    getline(inputStream, inputString);
    int numOfObstacles;
    numOfObstacles = stoi(inputString);
    vector<Point> listOfObstacles = vector<Point>();
    if (numOfObstacles > 0) {
        for (int i = 0; i < numOfObstacles; i++) {
            getline(inputStream, inputString);
            Point p(inputParsing.parsePoint(inputString));
            listOfObstacles.push_back(p);
        }
    }
    Graph<Point> *grid = createGrid(gd.gridWidth, gd.gridHeight, listOfObstacles);
    BfsAlgorithm<Point> bfs(grid);
    TaxiCenter taxiCenter = createTaxiCenter(bfs);

    while (true) {
        getline(inputStream, inputString);
        switch (stoi(inputString)) {
            case 1: {
                getline(inputStream, inputString);
                InputParsing::parsedDriverData driver = inputParsing.parseDriverData(inputString);
                try {
                    taxiCenter.addDriver(createDriver(driver.id,
                                                      driver.age, driver.status,
                                                      driver.yearsOfExperience,
                                                      taxiCenter.getCab(driver.vehicleId)));
                } catch (const char *msg) {
                    cerr << msg << endl;
                }
                break;
            }
            case 2: {
                getline(inputStream, inputString);
                InputParsing::parsedTripData trip = inputParsing.parseTripData(inputString);
                taxiCenter.createTrip(trip);
                break;
            }
            case 3: {
                getline(inputStream, inputString);
                InputParsing::parsedCabData cab = inputParsing.parseVehicleData(inputString);
                taxiCenter.addCab(createCab(cab.id, cab.taxiType, cab.manufacturer, cab.color));
                break;
            }
            case 4: {
                getline(inputStream, inputString);
                try {
                     Point point(taxiCenter.getDriverLocation(stoi(inputString)));
                    cout << point << '\n';
                } catch (const char *msg) {
                    cerr << msg << endl;
                }
                break;
            }
            case 6: {
                taxiCenter.startDriving();
                break;
            }
            case 7: {
                delete grid;
                return 0;
            }
            default:
                break;
        }
    }
}
