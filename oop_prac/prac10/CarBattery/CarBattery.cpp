#include "CarBattery.h"

void CarBattery::setCapacity(double capacity) {
    _capacity = capacity;
}

void CarBattery::setBatteryId(const MyString &batteryId) {
    _batteryId = batteryId;
}

CarBattery::CarBattery(const MyString &manufacturerName, const MyString &description, double capacity,
                       const MyString &batteryId) : CarPart(manufacturerName, batteryId) {
    setCapacity(capacity);
    setBatteryId(batteryId);
}
