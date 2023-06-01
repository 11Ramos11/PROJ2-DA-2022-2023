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

    //! @brief The x coordinate.
    double x;

    //! @brief The y coordinate.
    double y;

public:

    /** @brief Construct a new Coordinates object with the given x and y coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    Coordinates(double x, double y);

    /** @brief Get the x-coordinate.
     *
     * @return double The x-coordinate.
     */
    double getX() const;

    /** @brief Get the y-coordinate.
     *
     * @return double The y-coordinate.
     */
    double getY() const;
};


#endif //PROJ2_DA_2022_2023_COORDINATES_H
