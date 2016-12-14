#include <string>
#include <iostream>
#include "ProgramFlow.h"

#include "InputParsing.h"
#include "TaxiCenter.h"
#include "Menu.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

using namespace std;

void ProgramFlow::createTaxiCenter(BfsAlgorithm<Point> bfs) {
    taxiCenter = TaxiCenter(bfs);
}

void ProgramFlow::createDriver(int id, int age, Status_Of_Marriage status,
                               int yearsOfExperience, int vehicleId) {
   taxiCenter.addDriver(Driver(id,age,status,yearsOfExperience,vehicleId));
}


void ProgramFlow::createCab(int id,int cabType, Model_Of_Car carModel, Color_Of_Car color) {
    if(cabType==1){
        Cab *standardCab;
        standardCab = new StandardCab(id, carModel, color);
    }else if(cabType==2){
        Cab* luxuryCab;
        luxuryCab = new LuxuryCab(id, carModel, color);
    }

}


BfsAlgorithm<Point> ProgramFlow::createGrid(int width, int height, vector<Point> listOfObstacles) {
    Graph<Point>* g = new Grid(width, height);
     BfsAlgorithm<Point> bfs(g);
    return bfs;
}

void ProgramFlow::run() {

    string inputString;
    getline(cin, inputString);
    InputParsing inputParsing = InputParsing(inputString);
    InputParsing::gridDimensions gd = inputParsing.parseGridDimensions(inputString);
    getline(cin, inputString);
    int numOfObstacles;
    numOfObstacles = stoi(inputString);
    vector<Point> listOfObstacles = vector<Point>();
    if(numOfObstacles>0){
        for(int i=0; i<numOfObstacles; i++){
            getline(cin, inputString);
            Point p(inputParsing.parsePoint(inputString));

            listOfObstacles.push_back(p);
        }
    }
    BfsAlgorithm<Point> bfs = createGrid(gd.gridWidth, gd.gridHeight, listOfObstacles);
    createTaxiCenter(bfs);

    while (true) {
        getline(cin, inputString);
        switch (stoi(inputString)) {
            case 1: {
                InputParsing::parsedDriverData driver = inputParsing.parseDriverData(inputString);
                createDriver(driver.id, driver.age, driver.status, driver.yearsOfExperience,
                             driver.vehicleId);
                break;
            }
                case 2: {
                    InputParsing::parsedTripData trip = inputParsing.parseTripData(inputString);
                    taxiCenter.createTrip(trip);
                    break;
                }
            case 3: {
                InputParsing::parsedCabData cab = inputParsing.parseVehicleData(inputString);
                createCab(cab.id, cab.taxiType, cab.manufacturer, cab.color);
                break;
            }
                case 4: {
                    getline(cin, inputString);
                    Point point(taxiCenter.getDriverLocation(stoi(inputString)));
                    cout << point;
                    break;
                }
                    case 6: {
                        break;
                    }
            case 7: {
                exit(0);
            }
            default:
                break;
        }
    }
}

ProgramFlow::ProgramFlow() {

}
