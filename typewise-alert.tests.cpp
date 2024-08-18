#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
  EXPECT_EQ(inferBreach(-1, 0, 35), TOO_LOW);

    //  Temperature above upper limit
    EXPECT_EQ(inferBreach(36, 0, 35), TOO_HIGH);
    
    // Temperature within limits
    EXPECT_EQ(inferBreach(20, 0, 35), NORMAL);
    
    // Temperature exactly on the lower limit
    EXPECT_EQ(inferBreach(0, 0, 35), NORMAL);
    
    // Temperature exactly on the upper limit
    EXPECT_EQ(inferBreach(35, 0, 35), NORMAL);
    
    // Testing with different limits
    EXPECT_EQ(inferBreach(-1, -10, 10), TOO_LOW);
    EXPECT_EQ(inferBreach(11, -10, 10), TOO_HIGH);
    EXPECT_EQ(inferBreach(0, -10, 10), NORMAL);
}

  
