#include <gtest/gtest.h>
#include "../ProgramFlow.h"

//our tests:
TEST(ProgramFlowTest, SanityChecks) {
    ProgramFlow programFlow = ProgramFlow();
//    programFlow.createTaxiCenter();
    programFlow.createCab(1);
    /*
     * we didn't test the methods of
     * "createDriver(int id, int age, Status_of_Marriage status, int yearsOfExperience)"
     * and "createGrid(int width, int height, vector<Point> listOfObstacles)" because this two
     * methods just create objects we specificly check's in TestDriver and TestGrid.
     * */
}
