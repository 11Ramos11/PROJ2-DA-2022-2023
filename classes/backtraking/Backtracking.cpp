/** @file Backtracking.cpp
 *  @brief Contains the Backtracking Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Backtracking.h"
#include "VertexEdge.h"
#include "../../functionalities/Tour.h"

Backtracking::Backtracking(std::shared_ptr<Graph> &graph) : graph(graph) {}

bool Backtracking::exitsPath(Vertex *vertex1, Vertex *vertex2) {
    for (Edge *edge: vertex1->getAdj()) {
        if (edge->getDest()->getId() == vertex2->getId()) {
            return true;
        }
    }
    return false;
}

void Backtracking::tspCicle(int index, double actualDistance, std::vector<int> &actualPath, double &minDistance, std::vector<int> &tour) {
    bool exitsPathBetweenVertex;
    if (index == graph->getNumVertex()) {
        exitsPathBetweenVertex = exitsPath(graph->findVertex(actualPath[graph->getNumVertex() - 1]),
                                           graph->findVertex(actualPath[0]));
        if (exitsPathBetweenVertex) {
            actualDistance += graph->getEdgeWeightBetween(
                    graph->findVertex(actualPath[graph->getNumVertex() - 1]),
                    graph->findVertex(actualPath[0]));
            if (actualDistance < minDistance) {
                minDistance = actualDistance;
                tour = actualPath;
            }
            return;
        }
    }

    for (unsigned int v = 1; v < graph->getNumVertex(); v++) {
        exitsPathBetweenVertex = exitsPath(graph->findVertex(actualPath[index - 1]), graph->findVertex(v));
        if (exitsPathBetweenVertex)
            if (actualDistance + graph->getEdgeWeightBetween(
                    graph->findVertex(actualPath[index - 1]),
                    graph->findVertex(v)) < minDistance) {
                bool visited = false;
                for (unsigned int j = 1; j < index; j++) {
                    if (actualPath[j] == graph->findVertex(v)->getId()) {
                        visited = true;
                        break;
                    }
                }
                if (!visited) {
                    actualPath[index] = graph->findVertex(v)->getId();
                    double dist = graph->getEdgeWeightBetween(
                            graph->findVertex(actualPath[index - 1]),
                            graph->findVertex(actualPath[index]));
                    tspCicle( index + 1,actualDistance + dist, actualPath, minDistance, tour);
                }
            }
    }
}

Tour Backtracking::tspBacktracking() {
    std::vector<Vertex *> bestCicle;
    double minDistance = std::numeric_limits<double>::max();

    std::vector<int> actualPath(graph->getVertexSet().size());
    actualPath[0] = 0;
    std::vector<int> tour(graph->getVertexSet().size());

    tspCicle(1, 0, actualPath, minDistance, tour);

    for (int id: tour) {
        bestCicle.push_back(graph->findVertex(id));
    }

    /*tourEdges.push_back(graph->getEdge(tourIds[tourIds.size() - 1], tourIds[0]));

    Tour tour;
    tour.setTour(tourEdges);*/

    return tour;
}