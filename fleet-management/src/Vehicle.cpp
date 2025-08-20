#include "Vehicle.h"

/**
 * @brief Constructs a Vehicle object with specified parameters.
 *
 * Initializes a new Vehicle instance with the given identifier, speed, temperature, and fuel level.
 * This constructor sets up the essential properties required for vehicle management and tracking.
 *
 * @param id Unique identifier for the vehicle.
 * @param speed Initial speed of the vehicle in appropriate units.
 * @param temperature Current temperature reading of the vehicle.
 * @param fuel Current fuel level of the vehicle.
 */
Vehicle::Vehicle(int id, double speed, double temperature, double fuel)
    : id(id), speed(speed), temperature(temperature), fuel(fuel) {}

/**
 * @brief Retrieves the unique identifier of the vehicle.
 *
 * This function returns the ID assigned to the vehicle instance.
 * The ID is used to distinguish between different vehicles in the fleet.
 *
 * @return int The unique vehicle ID.
 */
int Vehicle::getId() const {
    return id;
}

/**
 * @brief Retrieves the current speed of the vehicle.
 *
 * This accessor function returns the value of the vehicle's speed member variable.
 * It does not modify any state and can be used to query the speed for monitoring,
 * logging, or decision-making purposes within the fleet management system.
 *
 * @return The current speed of the vehicle as a double.
 */
double Vehicle::getSpeed() const {
    return speed;
}

/**
 * @brief Retrieves the current temperature reading of the vehicle.
 *
 * This accessor function returns the value of the temperature attribute
 * associated with the Vehicle instance. It provides a way to query the
 * vehicle's temperature for monitoring or diagnostic purposes.
 *
 * @return The current temperature value of the vehicle as a double.
 */
double Vehicle::getTemperature() const {
    return temperature;
}

/**
 * @brief Retrieves the current fuel level of the vehicle.
 *
 * This function returns the amount of fuel currently available in the vehicle.
 * It is a const member function and does not modify any member variables.
 *
 * @return The current fuel level as a double.
 */
double Vehicle::getFuel() const {
    return fuel;
}