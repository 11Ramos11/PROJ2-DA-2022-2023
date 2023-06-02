/** @file Backtracking.h
 *  @brief Contains the Backtracking class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_BACKTRACKING_H
#define PROJ2_DA_2022_2023_BACKTRACKING_H

#include "Graph.h"
#include "../tour/Tour.h"

/** @brief Backtracking class that contains the backtracking algorithmic approach to the TSP.
 *
 */
class Backtracking {

private:

    //! @brief Initialization of the graph.
    std::shared_ptr<Graph> graph;

public:

    /** @brief Backtracking constructor.
     *
     * @param graph Shared pointer to a Graph object.
     */
    Backtracking(std::shared_ptr<Graph> &graph);

    /** @brief Check existence of a path between two vertices.
    *
    * This function checks whether there is a path between the two given
    * vertices in the graph.
    *
    * @param source ID of the source Vertex object.
    * @param dest ID to the destination Vertex object.
    * @return true if a path exists between source and dest, false otherwise.
    */
    bool existsPath(unsigned int source, unsigned int dest);

    /** @brief Performs the TSP backtracking algorithm.
     *
     * This function initiates and performs the backtracking algorithm
     * to solve the Travelling Salesperson Problem (TSP).
     *
     * Temporal Complexity -> O(V!)
     *
     * @return A pair where the first element is the minimum distance of the best cycle found,
     * and the second element is a vector of Vertex pointers that represents the best cycle.
     */
    Tour tspBacktracking();

    /** @brief Finds a path that traverses all vertices in the graph once and returns to the starting vertex.
     *
     * This function implements a recursive approach to find the Travelling Salesperson Problem (TSP)
     * cycle using backtracking. It updates the minimum distance and the tour if a better path is found.
     *
     * @param index of int type.
     * @param actualDistance of double type.
     * @param actualPath of std::vector<int> type, by reference.
     * @param minDistance of double type, by reference.
     * @param tour of std::vector<int> type, by reference.
     * @return Void.
     */
    void tspCicle(int index, double actualDistance,
                   std::vector<int> &actualPath, double &minDistance, std::vector<int> &tour);
};


#endif //PROJ2_DA_2022_2023_BACKTRACKING_H
