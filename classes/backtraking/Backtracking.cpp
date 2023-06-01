/** @file Backtracking.cpp
 *  @brief Contains the Backtracking Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Backtracking.h"
#include "VertexEdge.h"
#include "../../functionalities/Tour.h"

Backtracking::Backtracking(std::shared_ptr<Graph> &graph) : graph(graph) {}

bool Backtracking::existsPath(unsigned int source, unsigned int dest) {

    if (graph->getEdge(source, dest) != nullptr) {
        return true;
    }
    return false;
}

void Backtracking::tspCicle(int index, double actualDistance, std::vector<int> &actualPath, double &minDistance, std::vector<int> &tour) {
    bool exitsPathBetweenVertex;
    if (index == graph->getNumVertex()) {
        exitsPathBetweenVertex = existsPath(actualPath[graph->getNumVertex() - 1],actualPath[0]);
        if (exitsPathBetweenVertex) {
            actualDistance += graph->getEdge(actualPath[graph->getNumVertex() - 1], actualPath[0])->getWeight();
            if (actualDistance < minDistance) {
                minDistance = actualDistance;
                tour = actualPath;
            }
            return;
        }
    }

    for (unsigned int v = 1; v < graph->getNumVertex(); v++) {
        exitsPathBetweenVertex = existsPath(actualPath[index - 1], v);
        if (exitsPathBetweenVertex) {
            if (actualDistance + graph->getEdge(actualPath[index - 1], v)->getWeight() < minDistance) {
                if (!graph->findVertex(v)->isVisited()) {
                    actualPath[index] = v;
                    double dist = graph->getEdge(actualPath[index - 1], actualPath[index])->getWeight();
                    graph->findVertex(v)->setVisited(true);
                    tspCicle(index + 1, actualDistance + dist, actualPath, minDistance, tour);
                    graph->findVertex(v)->setVisited(false);
                }
            }
        }
    }
}

Tour Backtracking::tspBacktracking() {
    std::vector<Vertex *> bestCicle;
    double minDistance = std::numeric_limits<double>::max();

    std::vector<int> actualPath(graph->getVertexSet().size());
    actualPath[0] = 0;
    std::vector<int> tourIds(graph->getVertexSet().size());

    tspCicle(1, 0, actualPath, minDistance, tourIds);

    std::vector<Edge *> tourEdges;

    for (int i = 0; i < tourIds.size() - 1; i++) {

        tourEdges.push_back(graph->getEdge(tourIds[i], tourIds[i + 1]));
    }
    tourEdges.push_back(graph->getEdge(tourIds[tourIds.size() - 1], tourIds[0]));

    Tour tour;
    tour.setTour(tourEdges);

    return tour;
}