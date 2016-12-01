#include <gtest/gtest.h>
#include "../Point.h"
#include "../Graph.h"
#include "../Grid.h"
#include "../ProgramFlow.h"

class GridTest: public ::testing::Test {
protected:
    Grid grid1;
    int width;
    int height;
    Graph<Point>* graph1;

    virtual void SetUp() {
        grid1 = Grid(width,height);
        graph1 = new Grid(width,height);
    }
public:
    GridTest() : width(2), height(3), grid1(1,1){}

 };


TEST_F(GridTest, SanityChecks) {
    Node<Point> n1(Point(0,1)), n2(Point(1,0));
    queue<Node<Point>> neighborsOfOriginPoint;
    neighborsOfOriginPoint.push(n1);
    neighborsOfOriginPoint.push(n2);

    ASSERT_EQ("string", "string");

    bool boolVarTrue = true;
    bool boolVarFalse = false;

    //empty vector (so far)
    vector<Point> vectorOfObstaclesPoints;
    ProgramFlow programFlow = ProgramFlow();
    programFlow.createMap(1,1,vectorOfObstaclesPoints);


    Point obstaclePoint = Point(0,0);
    vectorOfObstaclesPoints.push_back(obstaclePoint);
    programFlow.createMap(1,1,vectorOfObstaclesPoints);
    Graph<Point>* g = new Grid(1,1);
    //ASSERT_EQ();
    delete g;
}
