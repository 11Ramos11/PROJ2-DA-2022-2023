//
// Created by Ramos on 5/29/2023.
//

#ifndef PROJ2_DA_2022_2023_COORDINATES_H
#define PROJ2_DA_2022_2023_COORDINATES_H


#include <map>
#include <string>

class Coordinates {
    double longitude;
    double latitude;
public:
    Coordinates(double longitude, double latitude);

    double distanceTo(Coordinates coordinates);
};


#endif //PROJ2_DA_2022_2023_COORDINATES_H
