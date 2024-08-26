#include "temperature.h"
#include "breach.h"

void getLimits(CoolingType coolingType, double* lowerLimit, double* upperLimit) {
    static const double upperLimits[] = {
        35, // PASSIVE_COOLING
        45, // HI_ACTIVE_COOLING
        40  // MED_ACTIVE_COOLING
    };
    
    *lowerLimit = 0;
    
    if (coolingType < sizeof(upperLimits)/sizeof(upperLimits[0])) {
        *upperLimit = upperLimits[coolingType];
    } else {
        *upperLimit = 0;
    }
}

BreachType classifyTemperature(double temperatureInC, CoolingType coolingType) {
    double lowerLimit, upperLimit;
    getLimits(coolingType, &lowerLimit, &upperLimit);
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}
