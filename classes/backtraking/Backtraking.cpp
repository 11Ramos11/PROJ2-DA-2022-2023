//
// Created by Matilde on 29/05/2023.
//

#include "Backtraking.h"
#include "VertexEdge.h"

Backtraking::Backtraking(std::shared_ptr<Graph> &graph) : graph(graph) {}

double getEdgeWeightBetween(Vertex *vertex1, Vertex *vertex2) {
    for (Edge *edge: vertex1->getAdj()) {
        if (edge->getDest()->getId() == vertex2->getId()) {
            return edge->getWeight();
        }
    }
    return std::numeric_limits<double>::max();
}

bool exitsPath(Vertex *vertex1, Vertex *vertex2) {
    for (Edge *edge: vertex1->getAdj()) {
        if (edge->getDest()->getId() == vertex2->getId()) {
            return true;
        }
    }
    return false;
}

void Backtraking::tspCicles(std::vector<Vertex *> &vertices, unsigned int n, unsigned int curIndex, double curDist,
               std::vector<unsigned int> &curPath, double &minDist, std::vector<unsigned int> &path) {
    bool exitsPathbetweenVertex;
    if (curIndex == n) {
        exitsPathbetweenVertex = exitsPath(vertices[graph->findVertex(curPath[n - 1])->getId()], vertices[graph->findVertex(curPath[0])->getId()]);
        if (exitsPathbetweenVertex) {
            curDist += getEdgeWeightBetween(vertices[graph->findVertex(curPath[n - 1])->getId()], vertices[curPath[0]]);
            if (curDist < minDist) {
                minDist = curDist;
                path = curPath;
            }
            return;
        }
    }

    for (unsigned int i = 1; i < n; i++) {
        exitsPathbetweenVertex = exitsPath(vertices[curPath[curIndex - 1]], vertices[i]);
        if (exitsPathbetweenVertex)
            if (curDist + getEdgeWeightBetween(vertices[graph->findVertex(curPath[curIndex - 1])->getId()], vertices[graph->findVertex(i)->getId()]) < minDist) {
                bool isNewVertex = true;
                for (unsigned int j = 1; j < curIndex; j++) {
                    if (curPath[j] == i) {
                        isNewVertex = false;
                        break;
                    }
                }
                if (isNewVertex) {
                    curPath[curIndex] = i;
                    double result = getEdgeWeightBetween(vertices[graph->findVertex(curPath[curIndex - 1])->getId()], vertices[graph->findVertex(curPath[curIndex])->getId()]);
                    tspCicles(vertices, n, curIndex + 1, curDist + result, curPath, minDist, path);
                }
            }
    }
}


std::pair<double, std::vector<Vertex *>> Backtraking::tspBacktraking() {
    std::vector<Vertex *> bestCicle;
    double minDist = std::numeric_limits<double>::max();

    std::vector<Vertex *> vertices = graph->getVertexSet();
    unsigned int n = vertices.size();
    std::vector<unsigned int> curPath(n);
    curPath[0] = vertices[0]->getId();

    std::vector<unsigned int> path(n);

    tspCicles(vertices, n, 1, 0, curPath, minDist, path);

    for (unsigned int id: path) {
        for (Vertex *v: vertices) {
            if (v->getId() == id) {
                bestCicle.push_back(v);
                break;
            }
        }
    }

    return {minDist, bestCicle};
}
