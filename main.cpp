#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include "Node.h"
#include "Grid.h"
#include "BfsAlgorithm.h"
#include "InputParsing.h"

using namespace std;

int main(int argc, char* argv[]) {

    ::testing::InitGoogleTest(&argc, argv);

    //scan input string (gridWidth_gridHeight,startX_startY,endX_endY) and parse it
    string inputString;
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
    return RUN_ALL_TESTS();
}
