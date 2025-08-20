#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Vehicle.h"
#include "../FleetManager.h"
#include <vector>

// Existing test cases...

// Additional 20 edge/bottleneck test cases

TEST_CASE("Vehicle Negative Values", "[edge]") {
    SECTION("Negative speed") {
        Vehicle v(1, -10, 90, 50);
        REQUIRE(v.getSpeed() == -10);
    }
    SECTION("Negative temperature") {
        Vehicle v(1, 60, -20, 50);
        REQUIRE(v.getTemperature() == -20);
    }
    SECTION("Negative fuel") {
        Vehicle v(1, 60, 90, -5);
        REQUIRE(v.getFuel() == -5);
    }
}

TEST_CASE("Vehicle Extreme Float Values", "[edge]") {
    SECTION("Very high speed") {
        Vehicle v(1, 1e6, 90, 50);
        REQUIRE(v.getSpeed() == Approx(1e6));
    }
    SECTION("Very low speed") {
        Vehicle v(1, -1e6, 90, 50);
        REQUIRE(v.getSpeed() == Approx(-1e6));
    }
}

TEST_CASE("FleetManager Large Dataset", "[performance]") {
    SECTION("10000 vehicles average") {
        std::vector<Vehicle> vehicles;
        for (int i = 0; i < 10000; ++i)
            vehicles.emplace_back(i, 100, 100, 100);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 100);
        REQUIRE(fm.averageTemperature() == 100);
        REQUIRE(fm.averageFuel() == 100);
    }
}

TEST_CASE("FleetManager Single Vehicle", "[edge]") {
    SECTION("Single vehicle averages") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(42, 77, 88, 99);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 77);
        REQUIRE(fm.averageTemperature() == 88);
        REQUIRE(fm.averageFuel() == 99);
    }
}

TEST_CASE("FleetManager Zero Values", "[edge]") {
    SECTION("All zero values") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 0, 0, 0);
        vehicles.emplace_back(2, 0, 0, 0);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 0);
        REQUIRE(fm.averageTemperature() == 0);
        REQUIRE(fm.averageFuel() == 0);
    }
}

TEST_CASE("FleetManager Mixed Values", "[edge]") {
    SECTION("Mixed positive and negative values") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 100, 100, 100);
        vehicles.emplace_back(2, -100, -100, -100);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 0);
        REQUIRE(fm.averageTemperature() == 0);
        REQUIRE(fm.averageFuel() == 0);
    }
}

TEST_CASE("Vehicle ID Edge Cases", "[edge]") {
    SECTION("Zero ID") {
        Vehicle v(0, 60, 90, 50);
        REQUIRE(v.getId() == 0);
    }
    SECTION("Negative ID") {
        Vehicle v(-1, 60, 90, 50);
        REQUIRE(v.getId() == -1);
    }
}

TEST_CASE("FleetManager Empty Fleet", "[edge]") {
    SECTION("No vehicles") {
        std::vector<Vehicle> vehicles;
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 0);
        REQUIRE(fm.averageTemperature() == 0);
        REQUIRE(fm.averageFuel() == 0);
    }
}

TEST_CASE("FleetManager All Alerts", "[alerts]") {
    SECTION("All vehicles trigger alerts") {
        std::vector<Vehicle> vehicles;
        for (int i = 0; i < 5; ++i)
            vehicles.emplace_back(i, 60, 120, 10);
        FleetManager fm(vehicles);
        REQUIRE_NOTHROW(fm.checkAlerts());
    }
}

TEST_CASE("FleetManager No Alerts", "[alerts]") {
    SECTION("No vehicles trigger alerts") {
        std::vector<Vehicle> vehicles;
        for (int i = 0; i < 5; ++i)
            vehicles.emplace_back(i, 60, 90, 50);
        FleetManager fm(vehicles);
        REQUIRE_NOTHROW(fm.checkAlerts());
    }
}

TEST_CASE("FleetManager Alternating Alerts", "[alerts]") {
    SECTION("Alternating alert conditions") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 60, 120, 10);
        vehicles.emplace_back(2, 60, 90, 50);
        vehicles.emplace_back(3, 60, 120, 10);
        vehicles.emplace_back(4, 60, 90, 50);
        FleetManager fm(vehicles);
        REQUIRE_NOTHROW(fm.checkAlerts());
    }
}

TEST_CASE("Vehicle Boundary Conditions", "[edge]") {
    SECTION("Temperature just below critical") {
        Vehicle v(1, 60, 109.99, 50);
        REQUIRE(v.getTemperature() < 110);
    }
    SECTION("Fuel just above warning") {
        Vehicle v(1, 60, 90, 15.01);
        REQUIRE(v.getFuel() > 15);
    }
}

TEST_CASE("FleetManager Floating Point Precision", "[precision]") {
    SECTION("Averages with floating point values") {
        /**
         * @brief A dynamic array container that holds multiple Vehicle objects.
         *
         * This vector is used to store and manage a collection of Vehicle instances,
         * allowing for efficient insertion, removal, and iteration over the fleet.
         *
         * @param Vehicle The type of objects stored in the vector, representing individual vehicles in the fleet.
         * @return None. This is a declaration of a member variable.
         */
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 60.5, 90.5, 50.5);
        vehicles.emplace_back(2, 61.5, 91.5, 51.5);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == Approx(61.0));
        REQUIRE(fm.averageTemperature() == Approx(91.0));
        REQUIRE(fm.averageFuel() == Approx(51.0));
    }
}

TEST_CASE("FleetManager Large Negative Dataset", "[edge]") {
    SECTION("All negative values") {
        std::vector<Vehicle> vehicles;
        for (int i = 0; i < 10; ++i)
            vehicles.emplace_back(i, -100, -100, -100);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == -100);
        REQUIRE(fm.averageTemperature() == -100);
        REQUIRE(fm.averageFuel() == -100);
    }
}

TEST_CASE("Vehicle Maximum Fuel", "[edge]") {
    SECTION("Fuel at 100%") {
        Vehicle v(1, 60, 90, 100);
        REQUIRE(v.getFuel() == 100);
    }
}

TEST_CASE("Vehicle Minimum Fuel", "[edge]") {
    SECTION("Fuel at 0%") {
        Vehicle v(1, 60, 90, 0);
        REQUIRE(v.getFuel() == 0);
    }
}

TEST_CASE("Vehicle Maximum Temperature", "[edge]") {
    SECTION("Temperature at 999.99°C") {
        Vehicle v(1, 60, 999.99, 50);
        REQUIRE(v.getTemperature() == Approx(999.99));
    }
}

TEST_CASE("Vehicle Minimum Temperature", "[edge]") {
    SECTION("Temperature at -273.15°C (absolute zero)") {
        Vehicle v(1, 60, -273.15, 50);
        REQUIRE(v.getTemperature() == Approx(-273.15));
    }
}

TEST_CASE("FleetManager Mixed Alerts", "[alerts]") {
    SECTION("Some vehicles alert, some do not") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 60, 120, 10); // alert
        vehicles.emplace_back(2, 60, 90, 50);  // no alert
        vehicles.emplace_back(3, 60, 120, 50); // temp alert
        vehicles.emplace_back(4, 60, 90, 10);  // fuel alert
        FleetManager fm(vehicles);
        REQUIRE_NOTHROW(fm.checkAlerts());
    }
}

TEST_CASE("FleetManager Zero and Nonzero Mix", "[edge]") {
    SECTION("Mix of zero and nonzero values") {
        std::vector<Vehicle> vehicles;
        vehicles.emplace_back(1, 0, 0, 0);
        vehicles.emplace_back(2, 100, 100, 100);
        FleetManager fm(vehicles);
        fm.computeAverages();
        REQUIRE(fm.averageSpeed() == 50);
        REQUIRE(fm.averageTemperature() == 50);
        REQUIRE(fm.averageFuel() == 50);
    }
}