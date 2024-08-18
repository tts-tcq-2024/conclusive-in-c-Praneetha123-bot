#pragma once

// Define enums for CoolingType, BreachType, and AlertTarget
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

// Define the BatteryCharacter struct
typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

// Function prototypes for breach inference and alert handling
BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

// Function prototypes for alerting
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

// Main function prototype
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
