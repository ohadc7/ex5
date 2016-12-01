#include <gtest/gtest.h>
#include "../ProgramFlow.h"

//our tests:
TEST(ProgramFlowTest, SanityChecks) {
    ProgramFlow programFlow = ProgramFlow();
   // programFlow.createCab(1);
    //programFlow.createDriver(1,30,MARRIED,5);
    vector<Point> vector1;
    vector1.push_back(Point(2,2));

    Grid grid =  programFlow.createGrid(10,10,vector1);
    Grid gridToTest = Grid(10,10, vector1);
 //   ASSERT_EQ(grid,gridToTest);
}
