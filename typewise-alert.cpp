#include "typewise-alert.h"
#include <stdio.h>

// Implementation of the breach inference function
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if (value < lowerLimit) return TOO_LOW;
  if (value > upperLimit) return TOO_HIGH;
  return NORMAL;
}

// Function to determine the upper limit based on cooling type
double getUpperLimit(CoolingType coolingType) {
  if (coolingType == PASSIVE_COOLING) return 35;
  if (coolingType == HI_ACTIVE_COOLING) return 45;
  if (coolingType == MED_ACTIVE_COOLING) return 40;
  return 0; // Default case for invalid cooling type
}

// Function to classify temperature based on cooling type
BreachType classifyTemperature(double temperatureInC, CoolingType coolingType) {
  double upperLimit = getUpperLimit(coolingType);
  double lowerLimit = 0; // Default lower limit
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

// Alerting functions
void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recipient = "a.b@c.com";
  if (breachType == TOO_LOW) {
    printf("To: %s\n", recipient);
    printf("Hi, the temperature is too low\n");
  } else if (breachType == TOO_HIGH) {
    printf("To: %s\n", recipient);
    printf("Hi, the temperature is too high\n");
  }
}

// Function to determine breach type
BreachType determineBreachType(CoolingType coolingType, double temperatureInC) {
  return classifyTemperature(temperatureInC, coolingType);
}

// Function to trigger alert
void triggerAlert(AlertTarget alertTarget, BreachType breachType) {
  if (alertTarget == TO_CONTROLLER) {
    sendToController(breachType);
  } else if (alertTarget == TO_EMAIL) {
    sendToEmail(breachType);
  }
}

// Main function to check and alert based on temperature
void checkAndAlert(
    AlertTarget alertTarget,
    BatteryCharacter batteryChar,
    double temperatureInC
) {
  BreachType breachType = determineBreachType(batteryChar.coolingType, temperatureInC);
  triggerAlert(alertTarget, breachType);
}
