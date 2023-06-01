/** @file Coordinates.cpp
 *  @brief Contains the Coordinates Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <cmath>
#include "Coordinates.h"

Coordinates::Coordinates(double longitude, double latitude) : longitude(longitude) , latitude(latitude) {}

double Coordinates::distanceTo(Coordinates coordinates) {

    double long1 = longitude;
    double lat1 = latitude;

    double long2 = coordinates.longitude;
    double lat2 = coordinates.latitude;

    double dlong = (long2 - long1) * M_PI / 180;

    double dlat = (lat2 - lat1) * M_PI / 180;

    double a = pow(sin(dlat / 2), 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * pow(sin(dlong / 2), 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double d = 6373 * c;

    return d;
}
