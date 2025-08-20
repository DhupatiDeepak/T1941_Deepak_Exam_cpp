#pragma once

#include <vector>
#include "Vehicle.h"

class FleetManager {
private:
    std::vector<Vehicle> vehicles;
    double avgSpeed{0.0};
    double avgTemp{0.0};
    double avgFuel{0.0};

public:
    explicit FleetManager(const std::vector<Vehicle>& fleet);
    void computeAverages();  // No parameters needed
    void checkAlerts() const;
    double averageSpeed() const;
    double averageTemperature() const;
    double averageFuel() const;
};