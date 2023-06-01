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

void Backtracking::tspCicle(std::vector<Vertex *> &vertices, int size, int index, double actualDistance,
                             std::vector<int> &actualPath, double &minDistance, std::vector<int> &tour) {
    bool exitsPathBetweenVertex;
    if (index == size) {
        exitsPathBetweenVertex = exitsPath(vertices[graph->findVertex(actualPath[size - 1])->getId()],
                                           vertices[graph->findVertex(actualPath[0])->getId()]);
        if (exitsPathBetweenVertex) {
            actualDistance += graph->getEdgeWeightBetween(
                    vertices[graph->findVertex(actualPath[size - 1])->getId()],
                    vertices[actualPath[0]]);
            if (actualDistance < minDistance) {
                minDistance = actualDistance;
                tour = actualPath;
            }
            return;
        }
    }

    for (unsigned int v = 1; v < size; v++) {
        exitsPathBetweenVertex = exitsPath(vertices[actualPath[index - 1]], vertices[v]);
        if (exitsPathBetweenVertex)
            if (actualDistance + graph->getEdgeWeightBetween(
                    vertices[graph->findVertex(actualPath[index - 1])->getId()],
                    vertices[graph->findVertex(v)->getId()]) < minDistance) {
                bool visited = false;
                for (unsigned int j = 1; j < index; j++) {
                    if (actualPath[j] == v) {
                        visited = true;
                        break;
                    }
                }
                if (!visited) {
                    actualPath[index] = v;
                    double dist = graph->getEdgeWeightBetween(
                            vertices[graph->findVertex(actualPath[index - 1])->getId()],
                            vertices[graph->findVertex(actualPath[index])->getId()]);
                    tspCicle(vertices, size, index + 1,
                              actualDistance + dist, actualPath, minDistance, tour);
                }
            }
    }
}

Tour Backtracking::tspBacktracking() {

    double minDistance = std::numeric_limits<double>::max();

    std::vector<Vertex *> vertices = graph->getVertexSet();
    int size = vertices.size();
    std::vector<int> actualPath(size);
    actualPath[0] = vertices[0]->getId();
    std::vector<int> tourIds(size);

    tspCicle(vertices, size, 1, 0, actualPath, minDistance, tourIds);

    std::vector<Edge*> tourEdges;

    for (int i = 0; i < tourIds.size() - 1; i++){
        tourEdges.push_back(graph->getEdge(tourIds[i], tourIds[i+1]));
    }

    tourEdges.push_back(graph->getEdge(tourIds[tourIds.size() - 1], tourIds[0]));

    Tour tour;
    tour.setTour(tourEdges);

    return tour;
}