#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
    int id;
    double speed;
    double temperature;
    double fuel;

public:
    Vehicle(int id, double speed, double temperature, double fuel);
    
    int getId() const;
    double getSpeed() const;
    double getTemperature() const;
    double getFuel() const;
};

#endif // VEHICLE_H