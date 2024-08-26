#ifndef ALERT_H
#define ALERT_H

#include "typewise-alert.h"

void triggerAlert(AlertTarget alertTarget, BreachType breachType);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

#endif // ALERT_H
