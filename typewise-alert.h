#pragma once
 
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;
 
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;
 
typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;
 
typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;
 
// Function to infer breach type based on limits
BreachType inferBreach(double value, double lowerLimit, double upperLimit);
 
// Function to classify temperature based on cooling type
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
 
// Function to handle alerting based on the alert target
void performAlert(AlertTarget alertTarget, BreachType breachType);
 
// Function to check temperature and send alerts
void checkAndAlert(
    AlertTarget alertTarget,
    BatteryCharacter batteryChar,
    double temperatureInC
);
 
// Helper functions for checking and alerting
BreachType determineBreachType(CoolingType coolingType, double temperatureInC);
void triggerAlert(AlertTarget alertTarget, BreachType breachType);
