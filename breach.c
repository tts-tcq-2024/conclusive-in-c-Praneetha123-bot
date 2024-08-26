#include "breach.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if (value < lowerLimit) return TOO_LOW;
    if (value > upperLimit) return TOO_HIGH;
    return NORMAL;
}

BreachType determineBreachType(CoolingType coolingType, double temperatureInC) {
    return classifyTemperature(temperatureInC, coolingType);
}
