#ifndef BREACH_H
#define BREACH_H

#include "typewise-alert.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType determineBreachType(CoolingType coolingType, double temperatureInC);

#endif // BREACH_H
