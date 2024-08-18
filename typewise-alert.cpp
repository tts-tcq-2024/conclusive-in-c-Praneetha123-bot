#include "typewise-alert.h"
#include <stdio.h>

// Implementation of the breach inference function
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if (value < lowerLimit) return TOO_LOW;
  if (value > upperLimit) return TOO_HIGH;
  return NORMAL;
}

// Implementation of classification functions
BreachType classifyPassiveCooling(double temperatureInC) {
  return inferBreach(temperatureInC, 0, 35);
}

BreachType classifyHiActiveCooling(double temperatureInC) {
  return inferBreach(temperatureInC, 0, 45);
}

BreachType classifyMedActiveCooling(double temperatureInC) {
  return inferBreach(temperatureInC, 0, 40);
}

// Classification function based on CoolingType
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  if (coolingType == PASSIVE_COOLING) return classifyPassiveCooling(temperatureInC);
  if (coolingType == HI_ACTIVE_COOLING) return classifyHiActiveCooling(temperatureInC);
  if (coolingType == MED_ACTIVE_COOLING) return classifyMedActiveCooling(temperatureInC);
  return NORMAL; // Default case
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
  return classifyTemperatureBreach(coolingType, temperatureInC);
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
