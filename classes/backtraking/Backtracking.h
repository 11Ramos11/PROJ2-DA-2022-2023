/** @file Backtracking.h
 *  @brief Contains the Backtracking class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_BACKTRACKING_H
#define PROJ2_DA_2022_2023_BACKTRACKING_H

#include "Graph.h"
#include "../../functionalities/Tour.h"

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
    * @param vertex2 ID to the destination Vertex object.
    * @return true if a path exists between source and dest, false otherwise.
    */
    bool existsPath(unsigned int source, unsigned int dest);

    /** @brief Performs the TSP backtracking algorithm.
     *
     * This function initiates and performs the backtracking algorithm
     * to solve the Travelling Salesperson Problem (TSP).
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
    * @param vertices A vector of Vertex pointers representing the vertices of the graph.
    * @param size The size of the vertices vector.
    * @param index The current index of the vertex in the vertices vector.
    * @param actualDistance The distance of the current path.
    * @param actualPath The current path being traversed.
    * @param minDistance The minimum distance found so far.
    * @param tour The best tour found so far.
    * @return Void.
    */
    void tspCicle(int index, double actualDistance,
                   std::vector<int> &actualPath, double &minDistance, std::vector<int> &tour);
};


#endif //PROJ2_DA_2022_2023_BACKTRACKING_H
