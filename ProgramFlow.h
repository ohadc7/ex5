#include "Point.h"
#include "Grid.h"
#include <vector>
#include "Driver.h"
#include "BfsAlgorithm.h"
#include "TaxiCenter.h"

#ifndef EX1_VERSION_1_1_PROGRAMFLOW_H
#define EX1_VERSION_1_1_PROGRAMFLOW_H

/*
 * This class manage the flow of the program.
 * It has methods for creating the grid (map), taxi center, drivers and cabs.
 * The run() method is responsible to get data from the user about the grid and
 * the wanted operations and to perform them.
 *
 */
class ProgramFlow {
public:
    /*
     * run the program menu in order to get the user input and do the suitable operations:
     * The first thing which the program takes as input is the size of the grid.
     * The next thing, is the number of obstacles inside the map.
     * Then, if there are any obstacles, the program will expect their locations.
     * After all the relevant input regarding the grid is given,
     * the program should expect a number which represents a command.
     * Here are all the possible inputs it can get:
     * 1 - insert a driver in the following format: (id,age,status,exp erience,vehicle_id)
     *                                              - (int,int,char:{S,M,D,W},int,int)
     * 2 - insert a new ride: (id,x_start,y_start,x_end,y_end,num_passengers,tariff)
     *                                              - (int,int,int,int,int,int,double)
     * 3 - insert a vehicle: (id,taxi_typ e,manufacturer,color)
     *                  - (int,{1: NormalCab,2:LuxuryCab},char:{H,S,T,F},char:{R,B,G,P,W})
     * 4 - request for a driver location: (driver_id)
     * output: driver location in the format: '(x,y)'.
     * 6 - start driving (no input afterwards. Meaning getting all drivers to their end point).
     * 7 - exit (cleaning up the program and exiting).
    */
    int run(istream &inputStream = cin, ostream &outputStream = cout);

    /*
     * create taxi center. the taxi center has to contain "bfs" (that know the grid and the
     * obstacles) in order to be able to navigate.
     */
    TaxiCenter createTaxiCenter(BfsAlgorithm<Point> bfs);

    //create a driver according to the given parameters
    Driver createDriver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, Cab* cab);

    //create a cab according to the given parameters
    Cab * createCab(int id,int cabType, Model_Of_Car carModel, Color_Of_Car color);

    //create rectangular matrix with list of impassable points
    Graph<Point> *createGrid(int width, int height, vector<Point> listOfObstacles);
};

#endif //EX1_VERSION_1_1_PROGRAMFLOW_H
