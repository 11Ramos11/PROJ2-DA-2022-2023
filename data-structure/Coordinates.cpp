/** @file Coordinates.cpp
 *  @brief Contains the Coordinates Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

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