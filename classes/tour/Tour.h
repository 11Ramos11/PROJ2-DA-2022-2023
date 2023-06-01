/** @file Tour.h
 *  @brief Contains the Tour class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_TOUR_H
#define PROJ2_DA_2022_2023_TOUR_H

#include "VertexEdge.h"

/** @brief Tour class that represents a tour, consisting of edges and vertices, in a graph.
 *
 */
class Tour {

    //! @brief Flag indicating if the tour has been set.
    bool isSet = false;

    //! @brief Vector containing the edges of the tour.
    std::vector<Edge*> tourEdges;

    //! @brief Vector containing the vertices of the tour.
    std::vector<Vertex*> tourVertexes;

    //! @brief The total cost of the tour.
    double cost;

public:

    /** @brief Sets the tour with the given edges.
     *
     * It also calculates and stores the cost of the tour based on the edges' weights.
     *
     * @param tourEdges A vector containing pointers to the edges of the tour.
     * @return Void.
     */
    void setTour(std::vector<Edge*> tourEdges);

    /** @brief Checks if the tour has been set.
     *
     * @return bool True if the tour is set, False otherwise.
     */
    bool isSetted() const;

    /** @brief Retrieves the vertices of the tour.
     *
     * @return std::vector<Vertex*> A vector containing pointers to the vertices of the tour.
     */
    std::vector<Vertex*> getVertexes();

    /** @brief Retrieves the edges of the tour.
     *
     * @return std::vector<Edge*> A vector containing pointers to the edges of the tour.
     */
    std::vector<Edge*> getEdges();

    /** @brief Retrieves the cost of the tour.
     *
     * @return double The cost of the tour.
     */
    double getCost() const;

    /** @brief Prints the tour.
     *
     * It outputs the IDs of the vertices, connected by "->", and ends with the ID of the first vertex.
     */
    void print();

    /** @brief Checks if the tour is valid.
     *
     * @return bool True if the tour contains at least one edge, False otherwise.
     */
    bool isValid();
};


#endif //PROJ2_DA_2022_2023_TOUR_H
