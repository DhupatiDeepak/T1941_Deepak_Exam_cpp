#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>

// Constants for thresholds
namespace Constants {
    constexpr double CRITICAL_TEMP = 110.0;
    constexpr double LOW_FUEL_THRESHOLD = 15.0;
}

/**
 * @class Vehicle
 * @brief Represents a vehicle with properties such as ID, speed, temperature, and fuel level.
 *
 * Provides methods to access vehicle parameters and check status conditions like overheating and low fuel.
 */

/**
 * @brief Constructs a Vehicle object with specified parameters.
 *        Validates input values to ensure they are within acceptable ranges.
 * @param id Unique identifier for the vehicle.
 * @param spd Initial speed of the vehicle (must be non-negative).
 * @param temp Initial temperature of the vehicle (must be non-negative).
 * @param fl Initial fuel level of the vehicle (must be between 0 and 100).
 * @throws std::invalid_argument if any parameter is out of valid range.
 */

/**
 * @brief Retrieves the unique identifier of the vehicle.
 * @return int The vehicle's ID.
 */

/**
 * @brief Retrieves the current speed of the vehicle.
 * @return double The vehicle's speed.
 */

/**
 * @brief Retrieves the current temperature of the vehicle.
 * @return double The vehicle's temperature.
 */

/**
 * @brief Retrieves the current fuel level of the vehicle.
 * @return double The vehicle's fuel level.
 */

/**
 * @brief Checks if the vehicle is overheating based on its temperature.
 * @return true if the temperature exceeds the critical threshold, false otherwise.
 */

/**
 * @brief Checks if the vehicle has low fuel based on its fuel level.
 * @return true if the fuel level is below the low fuel threshold, false otherwise.
 */
class Vehicle {
private:
    int id;
    double speed;
    double temperature;
    double fuel;

public:
    // Constructor with validation
    Vehicle(int id, double spd, double temp, double fl) 
        : id(id), speed(spd), temperature(temp), fuel(fl) {
        if (speed < 0 || temperature < 0 || fuel < 0 || fuel > 100) {
            throw std::invalid_argument("Invalid vehicle parameters");
        }
    }

    // Getters with const correctness
    [[nodiscard]] int getId() const { return id; }
    [[nodiscard]] double getSpeed() const { return speed; }
    [[nodiscard]] double getTemperature() const { return temperature; }
    [[nodiscard]] double getFuel() const { return fuel; }

    // Check vehicle status
    bool isOverheating() const {
        return temperature > Constants::CRITICAL_TEMP;
    }

    bool hasLowFuel() const {
        return fuel < Constants::LOW_FUEL_THRESHOLD;
    }
};

/**
 * @class FleetManager
 * @brief Manages a fleet of vehicles, providing functionality to add vehicles, 
 *        process alerts, and compute fleet statistics.
 *
 * This class encapsulates a collection of Vehicle objects and offers methods 
 * to add new vehicles, check for critical alerts (such as overheating or low fuel), 
 * and calculate average speed across the fleet. It is designed to improve code 
 * readability and maintainability by centralizing fleet operations.
 */

/**
 * @brief Adds a vehicle to the fleet.
 * @param vehicle The Vehicle object to be added to the fleet.
 * 
 * This method appends the given vehicle to the internal collection, 
 * allowing it to be managed and monitored by the FleetManager.
 */

/**
 * @brief Processes and displays alerts for each vehicle in the fleet.
 * 
 * Iterates through all vehicles and prints their status, including speed, 
 * temperature, and fuel level. Displays critical alerts if a vehicle is 
 * overheating or has low fuel, helping operators respond to urgent conditions.
 */

/**
 * @brief Calculates the average speed of all vehicles in the fleet.
 * @return double The average speed of the fleet. Returns 0.0 if the fleet is empty.
 * 
 * This method computes the mean speed by summing the speeds of all vehicles 
 * and dividing by the total number of vehicles, providing a useful fleet-wide metric.
 */
class FleetManager {
private:
    std::vector<Vehicle> vehicles;

public:
    // Add vehicle to fleet
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    // Process and display alerts
    void checkAlerts() const {
        for (const auto& vehicle : vehicles) {
            std::cout << "Vehicle " << vehicle.getId() 
                     << " Speed: " << vehicle.getSpeed() 
                     << " Temp: " << vehicle.getTemperature() 
                     << " Fuel: " << vehicle.getFuel() << "\n";

            if (vehicle.isOverheating()) {
                std::cout << "Critical Temperature Alert!\n";
            }
            if (vehicle.hasLowFuel()) {
                std::cout << "Low Fuel Warning!\n";
            }
        }
    }

    // Get fleet statistics
    double getAverageSpeed() const {
        if (vehicles.empty()) return 0.0;
        double total = std::accumulate(vehicles.begin(), vehicles.end(), 0.0,
            [](double sum, const Vehicle& v) { return sum + v.getSpeed(); });
        return total / vehicles.size();
    }
};

/**
 * @brief Entry point for the Fleet Management application.
 *
 * This function initializes a FleetManager instance, loads sample vehicle data,
 * validates and adds vehicles to the fleet, processes alerts, and displays fleet statistics.
 * It demonstrates exception handling for both vehicle creation and overall application errors.
 *
 * Steps performed:
 *  - Initializes FleetManager.
 *  - Loads sample vehicle data (could be replaced with file input).
 *  - Validates and adds vehicles to the fleet, reporting any invalid data.
 *  - Checks and displays alerts for vehicles in the fleet.
 *  - Calculates and displays fleet statistics (e.g., average speed).
 *
 * @return int Returns 0 on successful execution, or 1 if a fatal error occurs.
 */
int main() {
    try {
        FleetManager fleet;

        // Sample data (could be loaded from file)
        std::vector<std::tuple<int, double, double, double>> vehicleData = {
            {1, 120, 130, 10},
            {2, 80, 90, 40},
            {3, 0, 85, 50}
        };

        // Add vehicles with validation
        for (const auto& vehicleTuple : vehicleData) {
            try {
                int id = std::get<0>(vehicleTuple);
                double speed = std::get<1>(vehicleTuple);
                double temp = std::get<2>(vehicleTuple);
                double fuel = std::get<3>(vehicleTuple);
                Vehicle vehicle(id, speed, temp, fuel);
                fleet.addVehicle(vehicle);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error creating vehicle " << std::get<0>(vehicleTuple) << ": " << e.what() << "\n";
                continue;
            }
        }

        // Process and display alerts
        std::cout << "\n--- Fleet Status Report ---\n";
        fleet.checkAlerts();

        // Display fleet statistics
        std::cout << "\n--- Fleet Statistics ---\n";
        std::cout << "Average Speed: " << fleet.getAverageSpeed() << " km/h\n";

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }
}