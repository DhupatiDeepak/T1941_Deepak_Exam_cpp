# Fleet Management System

## Introduction
The Fleet Management System is a C++ application that monitors and manages a fleet of vehicles in real-time. It tracks vital statistics like speed, temperature, and fuel levels, providing alerts for critical conditions such as overheating or low fuel scenarios.

### Key Features
- Real-time vehicle monitoring and tracking
- Automatic alert generation for critical conditions
- Statistical analysis of fleet performance
## Detailed Features

### Core Functionality
- Real-time vehicle monitoring and tracking
- Automated alert generation system
- Statistical analysis and reporting
- CSV data import/export capabilities

### Technical Features
- Thread-safe operations for concurrent access
- Comprehensive exception handling
- Memory leak prevention
- Performance optimized algorithms
- Robust data validation

### Testing & Quality
- Comprehensive unit test suite using Catch2
- Edge case coverage
- Performance benchmarking
- Memory leak detection
- Thread safety verification

### Documentation
- Doxygen-style code documentation
- Detailed API documentation
- Implementation examples
- Troubleshooting guides

### Alert Thresholds
- Temperature > 110°C : Critical Overheating Alert
- Fuel < 15% : Low Fuel Warning

## System Requirements

### Required Tools
- C++ Compiler (g++ 7.0 or higher)
- CMake (version 3.10 or higher)
- Git (for version control)
- Visual Studio Code

### VS Code Extensions
- C/C++ Extension Pack
- CMake Tools
- Code Runner
- Git Graph (optional, for visualization)

### Libraries
- Standard C++ Libraries:
  - `iostream`: For input/output operations
  - `fstream`: For file handling
  - `vector`: For dynamic arrays
  - `string`: For string manipulation
  - `sstream`: For string stream operations
  - `algorithm`: For standard algorithms
  - `numeric`: For numeric operations

### Project Dependencies
- Catch2 (included in project for unit testing)
- C++17 compatible compiler (for better performance and modern features)
- CMake build system (3.10 or higher)
- Standard Template Library (STL)
- Threading support for concurrent operations
- File system library for data handling

## Project Structure

Workspace
Collecting workspace information

I'll help you create a comprehensive README.md file for your Fleet Management project:

fleet-management/
├── src/
│   ├── Vehicle.h          # Vehicle class definition
│   ├── Vehicle.cpp        # Vehicle class implementation
│   ├── FleetManager.h     # FleetManager class definition
│   ├── FleetManager.cpp   # FleetManager class implementation
│   ├── main.cpp           # Main application entry point
│   └── tests/             # Unit tests directory
│       ├── catch.hpp      # Catch2 testing framework
│       └── FleetTests.cpp # Test implementations
├── data/
│   └── vehicles.csv       # Sample vehicle data
├── CMakeLists.txt         # CMake configuration
└── README.md              # Project documentation



## Project Workflow

1. **Data Input**
   - Load vehicle data from CSV file
   - Parse and validate input data
   - Create vehicle objects

2. **Data Processing**
   - Calculate fleet statistics
   - Compute averages for:
     - Speed
     - Temperature
     - Fuel levels

3. **Monitoring & Alerts**
   - Temperature monitoring (Alert > 110°C)
   - Fuel level monitoring (Warning < 15%)
   - Real-time alert generation

4. **Output**
   - Display fleet statistics
   - Show critical alerts
   - Present average metrics

## Quick Start Guide

### Prerequisites
1. Ensure all required tools are installed
2. Clone the repository
3. Create a data directory and add vehicle data CSV file

### Build Options

#### Option 1: Using g++ directly (Quick Start)


This README.md provides:
- Clear introduction
- Comprehensive system requirements
- Detailed project structure
- Step-by-step workflow
- Build and run instructions
- Testing information
- Error handling overview
- Contributing guidelines
- License information

The format is clean and well-organized, making it easy for new developers to understand and work with the project.This README.md provides:
- Clear introduction
- Comprehensive system requirements
- Detailed project structure
- Step-by-step workflow
- Build and run instructions
- Testing information
- Error handling overview
- Contributing guidelines
- License information

The format is clean and well-organized, making it easy for new developers to understand and work with
