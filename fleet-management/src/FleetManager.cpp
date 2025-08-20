#include "FleetManager.h"
#include <iostream>
#include <numeric>
#include <algorithm>

/**
 * @brief Anonymous namespace containing utility constants and functions for FleetManager.
 *
 * Defines critical temperature and low fuel threshold constants used for vehicle monitoring.
 * Provides a template function to compute the average of a property across a collection of vehicles.
 */

/**
 * @brief Computes the average value of a specific property for a collection of vehicles.
 *
 * This template function iterates over the provided vector of Vehicle objects and applies
 * the specified member function getter to each vehicle to retrieve the property value.
 * It then calculates and returns the average of these values.
 *
 * @tparam Getter Type of member function pointer used to access the property from Vehicle.
 * @param vehicles Vector of Vehicle objects to compute the average from.
 * @param getter Member function pointer to retrieve the desired property from each Vehicle.
 * @return The average value of the specified property across all vehicles, or 0.0 if the vector is empty.
 */
namespace {
    constexpr double CRITICAL_TEMP = 110.0;
    constexpr double LOW_FUEL_THRESHOLD = 15.0;
    
    template<typename Getter>
    double computeAverage(const std::vector<Vehicle>& vehicles, Getter getter) {
        if (vehicles.empty()) return 0.0;
        double total = std::accumulate(vehicles.begin(), vehicles.end(), 0.0,
            [getter](double sum, const Vehicle& v) { return sum + (v.*getter)(); });
        return total / vehicles.size();
    }
}

FleetManager::FleetManager(const std::vector<Vehicle>& fleet) : vehicles(fleet) {}

/**
 * @brief Computes and updates the average speed, temperature, and fuel level for all vehicles in the fleet.
 *
 * This function iterates over the collection of vehicles and calculates the average values for speed,
 * temperature, and fuel by invoking the computeAverage utility with the appropriate member function pointers.
 * The computed averages are stored in the corresponding member variables: avgSpeed, avgTemp, and avgFuel.
 *
 * @note This method assumes that the vehicles container is properly populated and that the Vehicle class
 * provides the getSpeed, getTemperature, and getFuel member functions.
 *
 * @return void This function does not return a value; it updates the FleetManager's average statistics.
 */
void FleetManager::computeAverages() {
    avgSpeed = computeAverage(vehicles, &Vehicle::getSpeed);
    avgTemp = computeAverage(vehicles, &Vehicle::getTemperature);
    avgFuel = computeAverage(vehicles, &Vehicle::getFuel);
}

double FleetManager::averageSpeed() const { return avgSpeed; }
/**
 * @brief Calculates and returns the average temperature of the fleet.
 *
 * This function provides the average temperature value, which is maintained
 * internally by the FleetManager class. It can be used to monitor and analyze
 * the overall temperature status of the fleet vehicles.
 *
 * @return The current average temperature of all vehicles managed by the fleet.
 */
double FleetManager::averageTemperature() const { return avgTemp; }
double FleetManager::averageFuel() const { return avgFuel; }

/**
 * @brief Checks all vehicles in the fleet for critical alerts such as overheating and low fuel.
 *
 * Iterates through the list of vehicles managed by the FleetManager and prints alert messages
 * to the standard output if any vehicle exceeds the critical temperature threshold or falls
 * below the low fuel threshold.
 *
 * @return void This function does not return a value; alerts are output to the console.
 */
void FleetManager::checkAlerts() const {
    for (const auto& vehicle : vehicles) {
        if (vehicle.getTemperature() > CRITICAL_TEMP) {
            std::cout << "Vehicle ID " << vehicle.getId() 
                     << ": Critical Overheating\n";
        }
        if (vehicle.getFuel() < LOW_FUEL_THRESHOLD) {
            std::cout << "Vehicle ID " << vehicle.getId() 
                     << ": Low Fuel Warning\n";
        }
    }
}

