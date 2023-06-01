//
// Created by Ramos on 5/29/2023.
//

#ifndef PROJ2_DA_2022_2023_COORDINATES_H
#define PROJ2_DA_2022_2023_COORDINATES_H


#include <map>
#include <string>

class Coordinates {
    double x;
    double y;
public:
    Coordinates(double x, double y);

    double getX() const;

    double getY() const;
};


#endif //PROJ2_DA_2022_2023_COORDINATES_H
