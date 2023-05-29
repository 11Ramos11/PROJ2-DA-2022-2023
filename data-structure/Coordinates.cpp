//
// Created by Ramos on 5/29/2023.
//

#include "Coordinates.h"

Coordinates::Coordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

double Coordinates::getX() const {
    return x;
}

double Coordinates::getY() const {
    return y;
}