#include <string>
#include <iostream>
#include "ProgramFlow.h"

#include "InputParsing.h"
#include "TaxiCenter.h"
#include "Menu.h"

using namespace std;

void ProgramFlow::createTaxiCenter() {
    TaxiCenter taxiCenter();
}

void ProgramFlow::createDriver(int id, int age, Status_Of_Marriage status, int yearsOfExperience) {

}

void ProgramFlow::createCab(int id) {

}

void ProgramFlow::createGrid(int width, int height, vector<Point> listOfObstacles) {


}

void ProgramFlow::run() {
    string inputString;
    Menu menu;
    while (getline(cin, inputString)){
        menu.chooseOption(stoi(inputString));
    }
}
