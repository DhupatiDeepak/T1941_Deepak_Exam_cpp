#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Vehicle.h"
#include "FleetManager.h"

/**
 * @brief Loads vehicle data from a CSV file into a vector of Vehicle objects.
 *
 * This function reads vehicle information from the specified CSV file, parses each line,
 * and constructs Vehicle objects which are appended to the provided vector. The CSV file
 * is expected to have the following columns: ID, Speed, Temperature, Fuel. The first line
 * (header) is skipped. If a line cannot be parsed, an error message is printed and the line is skipped.
 *
 * @param filename The path to the CSV file containing vehicle data.
 * @param vehicles Reference to a vector where the loaded Vehicle objects will be stored.
 *
 * @throws std::runtime_error If the file cannot be opened.
 */
void loadVehicleData(const std::string& filename, std::vector<Vehicle>& vehicles) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }
    
    std::string line;
    // Skip header line if exists
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string idStr, speedStr, tempStr, fuelStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, speedStr, ',');
        std::getline(ss, tempStr, ',');
        std::getline(ss, fuelStr);

        try {
            int id = std::stoi(idStr);
            double speed = std::stod(speedStr);
            double temperature = std::stod(tempStr);
            double fuel = std::stod(fuelStr);

            vehicles.emplace_back(id, speed, temperature, fuel);
            std::cout << "Loaded vehicle ID: " << id << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
    }
}

int main() {
    try {
        std::vector<Vehicle> vehicles;
        // Use the correct path relative to where the executable is run
        loadVehicleData("fleet-management/data/vehicles.csv", vehicles);

        if (vehicles.empty()) {
            std::cerr << "No vehicles loaded from file" << std::endl;
            return 1;
        }

        std::cout << "\n--- Fleet Management System ---\n\n";

        // Create FleetManager with loaded vehicles
        FleetManager fleetManager(vehicles);
        
        // Compute and display averages
        fleetManager.computeAverages();
        std::cout << "Average Speed: " << fleetManager.averageSpeed() << " km/h\n";
        std::cout << "Average Temperature: " << fleetManager.averageTemperature() << " °C\n";
        std::cout << "Average Fuel: " << fleetManager.averageFuel() << "%\n\n";
        
        // Display alerts
        std::cout << "--- Alerts ---\n";
        fleetManager.checkAlerts();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}