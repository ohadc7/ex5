#include "gtest/gtest.h"
#include "../Driver.h"
#include "../Passenger.h"
#include "../StandardCab.h"

class TestDriver: public ::testing::Test {

protected:
    Driver driver,driver2,driver3;
    Point reuvenSourcePoint,reuvenDestinationPoint;
    Passenger reuven;
    StandardCab* cabForDriver1;
    TestDriver() : driver(1, 30, MARRIED, 5), driver2(2, 25, SINGLE, 5),
                   driver3(3, 28, SINGLE, 5), reuvenSourcePoint(2,2),
                   reuvenDestinationPoint(1,0),
                   reuven(reuvenSourcePoint, reuvenDestinationPoint, false),
                   cabForDriver1(new StandardCab(1122233, HONDA, BLUE)) {}

    virtual void SetUp() {
        driver.clientSatisfactions(5);
        driver.clientSatisfactions(4);
        driver2.clientSatisfactions(6);
        driver3.clientSatisfactions(0);
        driver.addPassenger(reuven);
        driver.attachCabToDriver((Cab**)&cabForDriver1);
    }

    virtual void TearDown(){
        delete cabForDriver1;
    }
};


    TEST_F(TestDriver, GettersCheck) {
    ASSERT_EQ(driver.getAge(), 30) << "test the age of the driver";
    ASSERT_EQ(driver.getId(), 1) << "test the id of the driver";
    ASSERT_EQ(driver.getStatus(), MARRIED) << "test the Marriage status of driver";
    ASSERT_EQ(driver.getYearsOfExperience(), 5) << "test years of experience";
    ASSERT_EQ(driver.getSatisfactions(), 4.5) << "test the average satisfaction change";
    EXPECT_EQ(driver2.getSatisfactions(),6) << "test should fail,average satisfaction can't be >5";
    EXPECT_EQ(driver3.getSatisfactions(),0) << "test should fail,average satisfaction can't be <1";
    EXPECT_EQ(driver.getListOfPassengers().front().getIsLuxury(),reuven.getIsLuxury()) <<
                                                           "check if inserted passenger works";
    EXPECT_EQ(driver2.getListOfPassengers().size(),0)<<"check that empty listOfPassenger is empty";
    EXPECT_EQ(driver.getInfoCab()->getColor(),cabForDriver1->getColor()) << "test the attached cab";
    ASSERT_EQ(driver3.isAvailable(), false) << "check if availability works";



}
