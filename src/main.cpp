#include <iostream>
#include <vector>
#include <limits>
#include "vehicle.h"
#include "gps.h"

using namespace std;

int main() {
  cout << "Exercise 0x06" << endl;
  vector<Vehicle> fleet = {
    {"BMW", "M3", 1, {56.08879136135274, 10.2233311613884}, BRAVO},
    {"Volkswagen", "Golf", 2, {56.127760815765505, 10.20281162730732}, BRAVO},
    {"Honda", "Accord", 3, {56.17100325888462, 10.19929977544253}, BRAVO},
    {"Volkswagen", "Golf", 6, {56.15255312320674, 10.203038127629382}, HOTEL},
    {"Fiat", "500", 1, {56.16217140423636, 10.18949261907776}, HOTEL},
    {"Fiat", "500", 4, {56.153889095359624, 10.199705269637143}, ROMEO},
    {"Honda", "Civic", 2, {56.150191891576384, 10.204729114263282}, ROMEO}
};

double inputLat, inputLng;
cout << "Enter coordinates: ";
while (cin >> inputLat >> inputLng) {
    GeoLocation userLocation = {inputLat, inputLng};

    double minDistance = numeric_limits<double>::max();
    Vehicle closestVehicle;

    for (const Vehicle& vehicle : fleet) {
        double distance = calculateDistance(userLocation, vehicle.location);
        if (distance < minDistance) {
            minDistance = distance;
            closestVehicle = vehicle;
        }
    }

    string typeStr = (closestVehicle.type == BRAVO) ? "BRAVO" :
                     (closestVehicle.type == HOTEL) ? "HOTEL" : "ROMEO";

    cout << typeStr << " " << closestVehicle.number
         << " (" << closestVehicle.make << " " << closestVehicle.model << ") is "
         << minDistance * 1000 << " meters away" << endl; // *1000 = km til meter

    cout << "\nEnter coordinates: ";
}

return 0;
}
