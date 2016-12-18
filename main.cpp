#include <string>
#include <gtest/gtest.h>
#include "ProgramFlow.h"

using namespace std;

int main(int argc, char* argv[]) {

    ::testing::InitGoogleTest(&argc, argv);

    //scan input string (gridWidth_gridHeight,startX_startY,endX_endY) and parse it
    string inputString;
    ProgramFlow programFlow;
    programFlow.run();
    //return 0;
    return RUN_ALL_TESTS();
}
