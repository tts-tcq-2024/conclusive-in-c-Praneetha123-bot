#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachBelowLowerLimits) {
  EXPECT_EQ(inferBreach(-1, 0, 35), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite,InfersBreachAboveUpperLimits) {
    //  Temperature above upper limit
    EXPECT_EQ(inferBreach(36, 0, 35), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite,InfersBreachWithinLimits) {
    // Temperature within limits
    EXPECT_EQ(inferBreach(20, 0, 35), NORMAL);
}   
TEST(TypeWiseAlertTestSuite,InfersBreachExactlyOnLowerLimits) {
    // Temperature exactly on the lower limit
    EXPECT_EQ(inferBreach(0, 0, 35), NORMAL);
}    

TEST(TypeWiseAlertTestSuite,InfersBreachExactlyOnUpperLimits) {
    // Temperature exactly on the upper limit
    EXPECT_EQ(inferBreach(35, 0, 35), NORMAL);

}

  
