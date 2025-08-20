cmake_minimum_required(VERSION 3.10)

# Set the project name
project(FleetManagement)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    src/Vehicle.cpp
    src/FleetManager.cpp
    src/main.cpp
)

# Add the executable
add_executable(FleetManagement ${SOURCES})