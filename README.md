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
Vehicle b0 = { "BMW", "M3", 2023, { 56.08879136135274, 10.2233311613884 }, BRAVO }; // Moesgaard Museum
Vehicle b1 = { "Volkswagen", "Golf", 2015, { 56.127760815765505, 10.20281162730732 }, BRAVO }; // Marselisborg Palace
Vehicle b2 = { "Honda", "Accord", 2020, { 56.17100325888462, 10.19929977544253 }, BRAVO }; // Aarhus University
Vehicle h1 = { "Volkswagen", "Golf", 2020, { 56.15255312320674, 10.203038127629382 }, HOTEL }; //Aarhus City Hall
Vehicle h2 = { "Fiat", "500", 2023, { 56.16217140423636, 10.18949261907776 }, HOTEL }; // Botanical Garden and Greenhouses
Vehicle r0 = { "Fiat", "500", 2023, { 56.153889095359624, 10.199705269637143 }, ROMEO }; // ARoS Aarhus Art Museum
Vehicle r1 = { "Honda", "Civic", 2022, { 56.150191891576384, 10.204729114263282 }, ROMEO }; // Aarhus Central Station

vector<Vehicle> fleet = { b0, b1, b2, h1, h2, r0, r1 };
```

The program will prompt the user for latitude and longitude and return the vehicle closest to
the provided location.
