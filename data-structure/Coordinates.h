/** @file Coordinates.h
 *  @brief Contains the Coordinates class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_COORDINATES_H
#define PROJ2_DA_2022_2023_COORDINATES_H

#include <map>
#include <string>

/** @brief Coordinates class that represents a pair of coordinates in a two-dimensional space.
 *
 */
class Coordinates {

    //! @brief The longitude of the coordinate.
    double longitude;

    //! @brief The latitude of the coordinate.
    double latitude;

public:

    /** @brief Construct a new Coordinates object with the given longitude and latitude coordinates.
     *
     * @param longitude of double type.
     * @param latitude of double type.
     */
    Coordinates(double longitude, double latitude);

    /** @brief Compute the distance from this coordinate to another coordinate.
     *
     * This method calculates the haversine distance from this coordinate to the given coordinate.
     * The haversine formula calculates the shortest distance over the earth's surface, giving the distance
     * between the points.
     *
     * @param coordinates The other coordinate to which the distance is to be calculated.
     * @return double The haversine distance to the other coordinate in kilometers.
     */
    double distanceTo(Coordinates coordinates);
};


#endif //PROJ2_DA_2022_2023_COORDINATES_H
