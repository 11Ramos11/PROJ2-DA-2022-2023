/** @file Heuristic.h
 *  @brief Contains the Heuristic class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_HEURISTIC_H
#define PROJ2_DA_2022_2023_HEURISTIC_H

#include "Graph.h"
#include "../tour/Tour.h"

/** @brief Heuristic class that contains the heuristic algorithmic approach to the TSP.
 *
 */
class Heuristic {

private:

    //! @brief Initialization of the graph.
    std::shared_ptr<Graph> graph;

public:

    /** @brief Creates a new Heuristic.
     *
     * @param graph A shared pointer to a Graph object.
     */
    Heuristic(std::shared_ptr<Graph> &graph);

    /** @brief Implements Prim's algorithm for minimum spanning tree (MST).
     *
     * This function creates a minimum spanning tree of the graph using
     * Prim's algorithm and returns it as a vector of tuples. Each tuple
     * represents an edge and contains the IDs of the source vertex,
     * destination vertex, and the weight of the edge.
     *
     * @return Vector of tuples representing the edges in the MST.
     */
    std::vector<std::tuple<int, int, double>> prim();

    /** @brief Builds a minimum spanning tree (MST) as a Graph object.
     *
     * This function calls the prim function to create an MST and
     * then builds a new Graph object using the edge information from
     * the MST.
     *
     * @return Graph object representing the MST.
     */
    Graph buildMst();

    /** @brief Auxiliary function for Depth-First Search (DFS) algorithm.
     *
     * This function is an auxiliary function for DFS. It recursively
     * visits all vertices reachable from the input vertex, and adds them
     * to the tour vector in the order they are visited.
     *
     * @param v Pointer to the Vertex object to start DFS from.
     * @param tour Vector of vertex IDs, representing the order of visitation.
     * @return Void.
     */
    void dfsAuxiliary(Vertex *v, std::vector<int> & tour);

    /** @brief Implements a Depth-First Search (DFS) on the MST.
     *
     * This function performs a DFS on the MST, starting from the vertex
     * with ID 0.
     *
     * @return Pair object containing the total distance of the tour and
     *         a vector with the order of the vertices visited.
     */
    Tour dfs();
};


#endif //PROJ2_DA_2022_2023_HEURISTIC_H
