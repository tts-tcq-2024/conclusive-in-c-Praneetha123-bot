#include "typewise-alert.h"
#include <stdio.h>

// Implementation of the breach inference function
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
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

// Function pointer type for classification and alerting
typedef BreachType (*ClassifyBreachFunction)(double temperatureInC);
typedef void (*AlertFunction)(BreachType breachType);

// Arrays to map CoolingType to classification functions
static const ClassifyBreachFunction classifyFunctions[] = {
  classifyPassiveCooling,
  classifyHiActiveCooling,
  classifyMedActiveCooling
};

// Arrays to map AlertTarget to alert functions
static const AlertFunction alertFunctions[] = {
  sendToController,
  sendToEmail
};

// Implementation of alerting functions
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

// Main function to check and alert based on temperature
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  // Ensure indices are valid
  if (batteryChar.coolingType < sizeof(classifyFunctions)/sizeof(classifyFunctions[0]) &&
      alertTarget < sizeof(alertFunctions)/sizeof(alertFunctions[0])) {
    
    // Get function pointers
    ClassifyBreachFunction classifyBreach = classifyFunctions[batteryChar.coolingType];
    AlertFunction alert = alertFunctions[alertTarget];

    // Perform classification and alert
    BreachType breachType = classifyBreach(temperatureInC);
    alert(breachType);
  }
}
