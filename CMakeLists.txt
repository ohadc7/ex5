cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp BfsAlgorithm.h
        Grid.cpp
        Grid.h
        Node.h Graph.h Point.cpp Point.h InputParsing.cpp InputParsing.h ProgramFlow.cpp
        ProgramFlow.h TaxiCenter.cpp TaxiCenter.h Passenger.cpp Passenger.h Driver.cpp Driver.h Tests/test.cpp Trip.cpp Trip.h Cab.cpp Cab.h Tests/TestPoint.cpp Tests/CabTest.cpp)
add_executable(ex2 ${SOURCE_FILES} Tests/test.cpp Tests/CabTest.cpp)
target_link_libraries(ex2 gtest gtest_main)