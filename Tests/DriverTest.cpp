#include "gtest/gtest.h"
#include "../Driver.h"
#include "../LuxuryCab.h"

class DriverTest: public ::testing::Test {

protected:
    Cab *luxuryCab = new LuxuryCab(3, HONDA, RED);
    Cab *luxuryCab2 = new LuxuryCab(3, HONDA, RED);
    Driver driver = Driver(1, 30, MARRIED, 5, luxuryCab);
    Driver driver2 = Driver(1, 30, MARRIED, 5, luxuryCab2);

};

TEST_F(DriverTest, sanityCheck) {
    //ASSERT_EQ(driver,driver2);
}

TEST_F(DriverTest, GettersCheck) {
    ASSERT_EQ(driver.getAge(), 30) << "test the age of the driver";
    ASSERT_EQ(driver.getId(), 1) << "test the id of the driver";
    ASSERT_EQ(driver.getStatus(), MARRIED) << "test the Marriage status of driver";
    ASSERT_EQ(driver.getYearsOfExperience(), 5) << "test years of experience";
//    ASSERT_EQ(luxuryCab2, driver.getInfoCab()) << "Assert the Cab of the driver";

}
