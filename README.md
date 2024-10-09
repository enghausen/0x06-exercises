# Exercise 0x06
The Danish police wants and new fleet management system (FMS) to optimize patrolling in
the different districts.

Requirements
Given a fleet of vehicles, the system shall be capable of identifying the vehicle nearest
to a location provided by the user in the format LAT LNG , (e.g. 56.13466783419156 10.205487752946347 )

Each patrol car is described by the following data
- Make (e.g. Volkwagen, Volvo or Ford)
- Model (e.g. V90, ID4, Mondeo, Passat)
- Type (BRAVO, HOTEL, ROMEO)
- Number (e.g. 1, 2, 3, 4)
- GPS coordinate (latitude and longitude)

Consider the following:
- What are good candidates for structures given the description above?
- Are there an obvious way to organize data in a hierachy?
- What data types should be used to represent the individual data points for a vehicle?

Example implementation of the fleet
```cpp
Vehicle b0 = { "BMW", "M3", 1, { 56.08879136135274, 10.2233311613884 }, BRAVO }; // Moesgaard Museum
Vehicle b1 = { "Volkswagen", "Golf", 2, { 56.127760815765505, 10.20281162730732 }, BRAVO }; // Marselisborg Palace
Vehicle b2 = { "Honda", "Accord", 3, { 56.17100325888462, 10.19929977544253 }, BRAVO }; // Aarhus University
Vehicle h1 = { "Volkswagen", "Golf", 6, { 56.15255312320674, 10.203038127629382 }, HOTEL }; //Aarhus City Hall
Vehicle h2 = { "Fiat", "500", 1, { 56.16217140423636, 10.18949261907776 }, HOTEL }; // Botanical Garden and Greenhouses
Vehicle r0 = { "Fiat", "500", 4, { 56.153889095359624, 10.199705269637143 }, ROMEO }; // ARoS Aarhus Art Museum
Vehicle r1 = { "Honda", "Civic", 2, { 56.150191891576384, 10.204729114263282 }, ROMEO }; // Aarhus Central Station

vector<Vehicle> fleet = { b0, b1, b2, h1, h2, r0, r1 };
```

The program will prompt the user for latitude and longitude and return the vehicle closest to
the provided location.

Example output
```
Enter coordinates: 56.12929161858004 10.184481194595108
BRAVO 3 (Volkswagen Golf) is 1.14866 meters away

Enter coordinates: 56.14139560553661 10.177339593224056
ROMEO 2 (Honda Civic) is 1.95838 m away

Enter coordinates: 
```

_**Hint** Go to https://www.google.dk/maps/place/Aarhus/ and right-click on the map to copy
GPS coordinates for testing_

Calculating the distance

$` d = {\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2} } `$

Translate the equation above into code, and consider the following:
- How could you use a `struct` to organize the function parameters?

The equation above doesn't take into account the curvature of the Earth, but that's okay, since we're focusing on structures in this exercise, but if you want to get more percise, take a look at the following code and see if you can work it into your solution:
```cpp
double to_rad(double deg) {
    return deg * M_PI / 180.0;
}

double calculateDistance(GeoLocation loc1, GeoLocation loc2) {
    // Earth radius in kilometers
    const double radius = 6371.0;

    // Convert latitude and longitude from degrees to radians
    loc1.latitude = to_rad(loc1.latitude);
    loc1.longitude = to_rad(loc1.longitude);
    loc2.latitude = to_rad(loc2.latitude);
    loc2.longitude = to_rad(loc2.longitude);

    // Haversine formula
    double dLat = loc2.latitude - loc1.latitude;
    double dLon = loc2.longitude - loc1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(loc1.latitude) * cos(loc2.latitude) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = radius * c;

    return distance;
}
```