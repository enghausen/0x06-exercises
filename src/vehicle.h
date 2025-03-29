#pragma once
#include <string>

struct GeoLocation {
    double latitude;
    double longitude;
};

enum VehicleType { BRAVO, HOTEL, ROMEO };

struct Vehicle {
    std::string make;
    std::string model;
    int number;
    GeoLocation location;
    VehicleType type;
};
