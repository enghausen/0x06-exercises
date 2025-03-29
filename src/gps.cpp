#define _USE_MATH_DEFINES
#include "gps.h"
#include <cmath>

double to_rad(double deg) {
    return deg * M_PI / 180.0;
}

double calculateDistance(GeoLocation loc1, GeoLocation loc2) {
    const double radius = 6371.0;

    // Grader til radianer
    loc1.latitude = to_rad(loc1.latitude);
    loc1.longitude = to_rad(loc1.longitude);
    loc2.latitude = to_rad(loc2.latitude);
    loc2.longitude = to_rad(loc2.longitude);

    // Haversine-formlen
    double dLat = loc2.latitude - loc1.latitude;
    double dLon = loc2.longitude - loc1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(loc1.latitude) * cos(loc2.latitude) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = radius * c;

    return distance;
}