#include "typewise-alert.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
    BreachType breachType = determineBreachType(batteryChar.coolingType, temperatureInC);
    triggerAlert(alertTarget, breachType);
}
