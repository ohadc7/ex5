#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include "Node.h"
#include "Grid.h"
#include "BfsAlgorithm.h"
#include "InputParsing.h"
#include "Menu.h"
#include "ProgramFlow.h"

using namespace std;

int main(int argc, char* argv[]) {

    ::testing::InitGoogleTest(&argc, argv);

    //scan input string (gridWidth_gridHeight,startX_startY,endX_endY) and parse it
    string inputString;
    ProgramFlow programFlow;
    programFlow.run();
    inputString = "3_3,0_0,1_1"; //for debugging (instead of the next line)
    //getline(cin, inputString);
    InputParsing ip = InputParsing(inputString);
    Node<Point> startPoint(Point(ip.getSourcePointX(), ip.getSourcePointY()));
    Node<Point> endPoint(Point(ip.getDestinationPointX(), ip.getDestinationPointY()));
    Graph<Point>* g = new Grid(ip.getGridWidth(), ip.getGridHeight());
    BfsAlgorithm<Point> bfs(g);

    //finding the short path from startPoint to endPoint
    stack<Node<Point>> idealPath = bfs.navigate(startPoint, endPoint);
    //print the path
    while (!idealPath.empty()) {
        Node<Point> nodeOfIdealPath = idealPath.top();
        idealPath.pop();
        Point pointOfIdealPath = nodeOfIdealPath.getValue();
        cout << pointOfIdealPath << endl;
    }
    delete g;



    //check for inputParsing class:
    //*
    string sP = "2,3";
    Point p = ip.parsePoint(sP);
    cout << endl << endl << endl << p << endl << endl;
    string sG = "5 7";
    InputParsing::gridDimensions gd = ip.parseGridDimensions(sG);
    cout <<  "grid width: " << gd.gridWidth << endl;
    cout <<  "grid height: " << gd.gridHeight << endl;
    string sD = "123456789,30,W,5,1122233";
    InputParsing::parsedDriverData d = ip.parseDriverData(sD);
    cout << endl << "ID :" << d.id << endl;
    cout <<  "status: " << d.status << endl;
    cout << "vehicleId: " << d.vehicleId << endl << endl;
    //*/


    return RUN_ALL_TESTS();
}
