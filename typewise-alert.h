#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

#include "breach.h"
#include "temperature.h"
#include "alert.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

#endif // TYPEWISE_ALERT_H
