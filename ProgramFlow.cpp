#include <string>
#include <iostream>
#include "ProgramFlow.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "InputParsing.h"

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
        return new StandardCab(id, carModel, color);
    } else {
        return new LuxuryCab(id, carModel, color);
    }
}


BfsAlgorithm<Point> ProgramFlow::createGrid(int width, int height, vector<Point> listOfObstacles) {
    Graph<Point> *g = new Grid(width, height);
    BfsAlgorithm<Point> bfs(g);
    return bfs;
}

int ProgramFlow::run() {

    string inputString;
    getline(cin, inputString);
    InputParsing inputParsing = InputParsing();
    InputParsing::gridDimensions gd = inputParsing.parseGridDimensions(inputString);
    getline(cin, inputString);
    int numOfObstacles;
    numOfObstacles = stoi(inputString);
    vector<Point> listOfObstacles = vector<Point>();
    if (numOfObstacles > 0) {
        for (int i = 0; i < numOfObstacles; i++) {
            getline(cin, inputString);
            Point p(inputParsing.parsePoint(inputString));

            listOfObstacles.push_back(p);
        }
    }
    BfsAlgorithm<Point> bfs = createGrid(gd.gridWidth, gd.gridHeight, listOfObstacles);
    TaxiCenter taxiCenter = createTaxiCenter(bfs);

    while (true) {
        getline(cin, inputString);
        switch (stoi(inputString)) {
            case 1: {
                getline(cin, inputString);
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
                getline(cin, inputString);
                InputParsing::parsedTripData trip = inputParsing.parseTripData(inputString);
                taxiCenter.createTrip(trip);
                break;
            }
            case 3: {
                getline(cin, inputString);
                InputParsing::parsedCabData cab = inputParsing.parseVehicleData(inputString);
                taxiCenter.addCab(createCab(cab.id, cab.taxiType, cab.manufacturer, cab.color));
                break;
            }
            case 4: {
                getline(cin, inputString);
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
                return 0;
            }
            default:
                break;
        }
    }
}