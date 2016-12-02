cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp BfsAlgorithm.h
        Grid.cpp
        Grid.h
        Node.h Graph.h Point.cpp Point.h InputParsing.cpp InputParsing.h ProgramFlow.cpp
        ProgramFlow.h TaxiCenter.cpp TaxiCenter.h Passenger.cpp Passenger.h
        Driver.cpp Driver.h Trip.cpp Trip.h Cab.cpp Cab.h
        StandardCab.cpp StandardCab.h
        LuxuryCab.cpp LuxuryCab.h Tests/TestPoint.cpp  Tests/ProgramFlowTest.cpp
        Tests/DriverTest.cpp Tests/TestGrid.cpp Tests/TestTrip.cpp Tests/TestCabs.cpp Tests/TestInputParsing.cpp Tests/TestTaxiCenter.cpp)
add_executable(ex2 ${SOURCE_FILES} Tests/ProgramFlowTest.cpp
        Tests/DriverTest.cpp Tests/TestGrid.cpp)
target_link_libraries(ex2 gtest gtest_main)