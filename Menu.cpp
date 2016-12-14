//
// Created by ohad on 13/12/16.
//

#include "Menu.h"
#include "InputParsing.h"
#include "ProgramFlow.h"


void Menu::optionOneInsertDriver() {
    InputParsing inputParsing = InputParsing();
    inputParsing.parseDriverData("test");
    //programFlow.createDriver(inputParsing().getDriver("test"))
}

void Menu::optionTwoInsertNewRide() {

}

void Menu::optionThreeInsertVeichle() {

}

void Menu::optionFourRequsetDriverLocation() {

}

void Menu::optionSixStartDriving() {

}

void Menu::optionSevenExit() {

}

void Menu::chooseOption(int optionNum) {
    switch (optionNum){
        case 1:
            optionOneInsertDriver();
            break;
        case 2:
            optionTwoInsertNewRide();
            break;
        case 3:
            optionThreeInsertVeichle();
            break;
        case 4:
            optionFourRequsetDriverLocation();
            break;
        case 6:
            optionSixStartDriving();
            break;
        case 7:
            optionSevenExit();
            break;
        default:
            break;
    }

}
