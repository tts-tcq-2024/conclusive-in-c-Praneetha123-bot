#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachBelowLowerLimits) {
   BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
   checkAndAlert(TO_CONTROLLER, batteryChar, 30);
}

// TEST(TypeWiseAlertTestSuite,InfersBreachAboveUpperLimits) {
//     //  Temperature above upper limit
//     EXPECT_EQ(checkAndAlert(36, 0, 35), TOO_HIGH);
// }

// TEST(TypeWiseAlertTestSuite,InfersBreachWithinLimits) {
//     // Temperature within limits
//     EXPECT_EQ(checkAndAlert(20, 0, 35), NORMAL);
// }   
// TEST(TypeWiseAlertTestSuite,InfersBreachExactlyOnLowerLimits) {
//     // Temperature exactly on the lower limit
//     EXPECT_EQ(checkAndAlert(0, 0, 35), NORMAL);
// }    

// TEST(TypeWiseAlertTestSuite,InfersBreachExactlyOnUpperLimits) {
//     // Temperature exactly on the upper limit
//     EXPECT_EQ(checkAndAlert(35, 0, 35), NORMAL);

// }

  
