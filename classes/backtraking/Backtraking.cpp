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

void tspCicles(std::vector<Vertex *> &vertices, unsigned int n, unsigned int curIndex, double curDist,
               std::vector<unsigned int> &curPath, double &minDist, std::vector<unsigned int> &path) {
    bool exitsPathbetweenVertex;
    if (curIndex == n) {
        exitsPathbetweenVertex = exitsPath(vertices[curPath[n - 1]], vertices[curPath[0]]);
        if (curDist >= 82.6 && curDist <= 82.8)
            std::cout << vertices[curPath[n-1]]->getId() << " - " << vertices[curPath[0]] << std::endl;
        if (exitsPathbetweenVertex) {
            curDist += getEdgeWeightBetween(vertices[curPath[n - 1]], vertices[curPath[0]]);
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
            if (curDist + getEdgeWeightBetween(vertices[curPath[curIndex - 1]], vertices[i]) < minDist) {
                bool isNewVertex = true;
                for (unsigned int j = 1; j < curIndex; j++) {
                    if (curPath[j] == i) {
                        isNewVertex = false;
                        break;
                    }
                }
                if (isNewVertex) {
                    curPath[curIndex] = i;
                    double result = getEdgeWeightBetween(vertices[curPath[curIndex - 1]], vertices[curPath[curIndex]]);
                    tspCicles(vertices, n, curIndex + 1, curDist + result, curPath, minDist, path);
                }
            }
    }
}

bool sort(Vertex* v1, Vertex *v2) {
    return v1->getId() < v2->getId();
}


std::pair<double, std::vector<Vertex *>> Backtraking::tspBacktraking() {
    std::vector<Vertex *> bestCicle;
    double minDist = std::numeric_limits<double>::max();

    std::vector<Vertex *> vertices = graph->getVertexSet();
    std::sort(vertices.begin(), vertices.end(), sort);
    vertices.pop_back();
    for (auto v : vertices)
        std::cout << v->getId() << std::endl;
    unsigned int n = vertices.size();
    std::vector<unsigned int> curPath(n-1);
    curPath[0] = vertices[0]->getId();

    std::vector<unsigned int> path(n-1);

    tspCicles(vertices, 13, 1, 0, curPath, minDist, path);

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
