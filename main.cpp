#include "typewise-alert.h"

int main() {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 30.0);
    return 0;
}
