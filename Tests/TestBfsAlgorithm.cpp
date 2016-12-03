#include "gtest/gtest.h"
#include "../BfsAlgorithm.h"

class TestBfsAlgorithm : public ::testing::Test{
protected:
        Grid *grid =  new Grid(10,10);
        BfsAlgorithm<Point> bfs = BfsAlgorithm<Point>(grid);
};

TEST_F(TestBfsAlgorithm,checkRoutes){

    Node<Point> startPoint(Point(0, 0));
    Node<Point> endPoint(Point(5,5));
    stack<Node<Point>> bfsOutput = bfs.navigate(startPoint,endPoint);
    Node<Point> startPoint2(Point(0, 0));
    Node<Point> endPoint2(Point(2,2));
    stack<Node<Point>> bfsOutput2 = bfs.navigate(startPoint2,endPoint2);

    stack<Node<Point>> bfsTest;
    bfsTest.push((Point(5,5)));bfsTest.push((Point(5,4)));bfsTest.push((Point(3,5)));
    bfsTest.push((Point(2,5)));bfsTest.push((Point(1,5)));bfsTest.push((Point(0,5)));
    bfsTest.push((Point(0,4)));bfsTest.push((Point(0,3)));bfsTest.push((Point(0,2)));
    bfsTest.push((Point(0,1)));bfsTest.push((Point(0,0)));

    stack<Node<Point>> bfsTest2;
    bfsTest2.push((Point(2,2)));bfsTest2.push((Point(1,2)));bfsTest2.push((Point(0,2)));
    bfsTest2.push((Point(0,1)));bfsTest2.push((Point(1,1)));


    for(int i=0; i<bfsOutput.size(); i++) {
        EXPECT_EQ(bfsOutput.top(), bfsTest.top()) << "check with true route to compere";
    }
    for(int i=0; i<bfsOutput2.size(); i++) {
        EXPECT_EQ(bfsOutput2.top(), bfsTest2.top()) << "should fail, check with "
                            "false route to compere";
    }
}