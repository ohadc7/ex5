cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES src/main.cpp src/BfsAlgorithm.h
        src/Grid.cpp
        src/Grid.h
        src/Node.h src/Graph.h src/Point.cpp src/Point.h src/InputParsing.cpp src/InputParsing.h src/ProgramFlow.cpp
        src/ProgramFlow.h src/TaxiCenter.cpp src/TaxiCenter.h src/Passenger.cpp src/Passenger.h
        src/Driver.cpp src/Driver.h src/Trip.cpp src/Trip.h src/Cab.cpp src/Cab.h
        src/StandardCab.cpp src/StandardCab.h
        src/LuxuryCab.cpp src/LuxuryCab.h Tests/TestPoint.cpp Tests/TestProgramFlow.cpp
        Tests/TestDriver.cpp Tests/TestGrid.cpp Tests/TestTrip.cpp Tests/TestCabs.cpp
        Tests/TestInputParsing.cpp Tests/TestTaxiCenter.cpp Tests/TestBfsAlgorithm.cpp Tests/TestPassenger.cpp Tests/main_test.cpp)
add_executable(ex2 ${SOURCE_FILES} Tests/TestProgramFlow.cpp
        Tests/TestDriver.cpp Tests/TestGrid.cpp Tests/TestBfsAlgorithm.cpp Tests/TestPassenger.cpp Tests/main_test.cpp)
target_link_libraries(ex2 gtest gtest_main)