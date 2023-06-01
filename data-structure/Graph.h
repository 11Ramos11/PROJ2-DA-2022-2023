/** @file Graph.h
 *  @brief Contains the Graph class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include "MutablePriorityQueue.h"

#include "VertexEdge.h"

// hash function for unordered_map<std::pair<int, int>, Edge*>

/** @brief Hash function for unordered_map<std::pair<int, int>, Edge*>.
 *
 * @param p of std::pair<int, int> type.
 * @return Hash value.
 */
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const;
};

/** @brief Graph class to represent implementations that uses a graph directly.
 *
 */
class Graph {

public:

    /** @brief Creates a new Graph.
     *
     */
    Graph();

    /** @brief Creates a new Graph.
     *
     * @param graph of Graph * type.
     */
    Graph(Graph *graph);

    /** @brief Auxiliary function to find a vertex with a given ID.
     *
     * @param id of int type.
     * @return Corresponding vertex.
     */
    Vertex *findVertex(int id) const;

    /** @brief Adds a vertex with a given content to a graph.
     *
     * @param id of const int type, by reference.
     * @param coordinates of std::shared_ptr<Coordinates> type.
     * @return True if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const int &id, std::shared_ptr<Coordinates> coordinates);

    /** @brief Adds an edge to a graph, given the contents of the source and
     * destination vertices and the edge weight.
     *
     * @param source of const int type, by reference.
     * @param dest of const int type, by reference.
     * @param w of double type.
     * @return True if successful, and false if the source or destination vertex does not exist
     */
    bool addEdge(const int &source, const int &dest, double w);

    /** @brief Adds a bidirectional edge to a graph, given the contents of the source and
     * destination vertices and the edge weight.
     *
     * @param source of const int type, by reference.
     * @param dest of const int type, by reference.
     * @param w of double type.
     * @return True if successful, and false if the source or destination vertex does not exist
     */
    bool addBidirectionalEdge(const int &source, const int &dest, double w);

    Edge* getEdge(int source, int dest) const;

    /** @brief Represents the number of vertex of a graph.
     *
     * @return Number of vertex.
     */
    int getNumVertex() const;

    /** @brief Represents the VertexSet.
     *
     * @return All vertex.
     */
    std::vector<Vertex *> getVertexSet() const;

    /** @brief Represents the Depth First Search algorithm.
     *
     * @param source of int type.
     * @return Void.
     */
    void dfs(int source);

    /** @brief Obtains the edge weight between two specific vertex.
     *
     * @param vertex1 of Vertex* type.
     * @param vertex2 of Vertex* type.
     * @return The edge weight.
     */
    double getEdgeWeightBetween(Vertex *vertex1, Vertex *vertex2);

    /** @brief Remove the vertex from the graph.
     *
     * @param id of int type.
     * @return Void.
     */
    void removeVertex(int id);

protected:

    //! @brief Holds the vertexSet.
    std::vector<Vertex *> vertexSet;

    //! @brief Maps the index of vertex, in the vertexSet, to its id.
    std::unordered_map<unsigned int, unsigned int> indexMap;

    std::unordered_map<std::pair<unsigned int, unsigned int>, Edge*, pair_hash> edges;
};

#endif /* DA_TP_CLASSES_GRAPH */