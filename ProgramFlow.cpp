#include <string>
#include <iostream>
#include "ProgramFlow.h"

#include "InputParsing.h"
#include "TaxiCenter.h"
#include "Menu.h"

using namespace std;

void ProgramFlow::createTaxiCenter(BfsAlgorithm<Point> bfs) {
    TaxiCenter taxiCenter(bfs);
}

void ProgramFlow::createDriver(int id, int age, Status_Of_Marriage status, int yearsOfExperience) {


}

void ProgramFlow::createCab(int id) {

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
            case 1:

                break;
            case 2:
                /*int rideId, Point startingPoint, Point endingPoint, list <Passenger> customers
                Trip trip();
                createTrip(inputParsing.g)
                break;
            case 3:
                break;
            case 4:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                break;
        }
    }*/
}