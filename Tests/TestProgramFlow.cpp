#include <gtest/gtest.h>
#include "../ProgramFlow.h"
#include "../StandardCab.h"
#include "../LuxuryCab.h"

class TestProgramFlow: public ::testing::Test {
protected:
    ProgramFlow pFlow;

    TestProgramFlow() : pFlow() {}
};


TEST_F(TestProgramFlow, SanityChecks) {
    Cab* cab = pFlow.createCab(2244466, STANDARD_CAB, HONDA, GREEN);
    Color_Of_Car colorOfTheCab = cab->getColor();
    ASSERT_EQ(colorOfTheCab, GREEN);
    Model_Of_Car modelOfTheCab = cab->getCarModel();
    ASSERT_EQ(modelOfTheCab, HONDA);
    ASSERT_EQ(cab->getId(), 2244466);
    ASSERT_EQ(cab->getSpeed(), SPEED_OF_STANDARD_CAB);

    cab = pFlow.createCab(1133355, LUXURY_CAB, TESLA, BLUE);
    ASSERT_EQ(cab->getSpeed(), SPEED_OF_LUXURY_CAB);

    //pFlow.createTaxiCenter();

    /*
     * we didn't test the methods of
     * "createDriver(int id, int age, Status_of_Marriage status, int yearsOfExperience)"
     * and "createGrid(int width, int height, vector<Point> listOfObstacles)" because this two
     * methods just create objects we specificly check's in TestDriver and TestGrid.
     * */
}
