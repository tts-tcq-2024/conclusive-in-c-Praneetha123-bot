#include <gtest/gtest.h>
#include "typewise-alert.h"

// Test case: Infers breach when temperature is below lower limit
TEST(TypeWiseAlertTestSuite, InfersBreachBelowLowerLimits) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, -5.0); // Temperature below 0°C
}

// Test case: Infers breach when temperature is above upper limit
TEST(TypeWiseAlertTestSuite, InfersBreachAboveUpperLimits) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 40.0); // Temperature above 35°C
}

// Test case: Infers breach when temperature is exactly on the lower limit
TEST(TypeWiseAlertTestSuite, InfersBreachOnLowerLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 0.0); // Temperature exactly at 0°C
}

// Test case: Infers breach when temperature is exactly on the upper limit
TEST(TypeWiseAlertTestSuite, InfersBreachOnUpperLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 35.0); // Temperature exactly at 35°C
}

// Test case: Check the output when temperature is within normal limits
TEST(TypeWiseAlertTestSuite, CheckNormalTemperatureToController) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 25.0); // Temperature within 0°C to 35°C
}

// Test case: Check the output when temperature is too low and send email
TEST(TypeWiseAlertTestSuite, CheckTooLowTemperatureToEmail) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_EMAIL, batteryChar, -10.0); // Temperature below 0°C
}

// Test case: Check the output when temperature is too high and send email
TEST(TypeWiseAlertTestSuite, CheckTooHighTemperatureToEmail) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_EMAIL, batteryChar, 50.0); // Temperature above 35°C
}

TEST(TypeWiseAlertTestSuite, HandlesInvalidCoolingType) {
    BatteryCharacter batteryChar = { (CoolingType)100, "TestBrand" }; // Invalid CoolingType
    checkAndAlert(TO_CONTROLLER, batteryChar, 30); // Test with a temperature within valid range
}

TEST(TypeWiseAlertTestSuite, HandlesInvalidCoolingType) {
    BatteryCharacter batteryChar = { (CoolingType)100, "TestBrand" }; // Invalid CoolingType
    checkAndAlert((AlertTarget)100, batteryChar, 30); // Test with a temperature within valid range
}

