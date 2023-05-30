//
// Created by Ramos on 5/30/2023.
//

#include "OtherHeuristics.h"

void OtherHeuristics::NearestNeighbour(std::shared_ptr<Graph> graph){

    if (graph->getNumVertex() == 0)
        return;

    std::vector<Vertex*> vertexSet = graph->getVertexSet();

    Vertex* currentVertex = vertexSet[0];

    std::vector<Vertex*> tour;

    while (true){

        tour.push_back(currentVertex);

        currentVertex->setVisited(true);

        Edge *minEdge = nullptr;

        for (Edge *edge: currentVertex->getAdj()) {
            if (!edge->getDest()->isVisited()) {
                if (minEdge == nullptr) {
                    minEdge = edge;
                } else if (edge->getWeight() < minEdge->getWeight()) {
                    minEdge = edge;
                }
                continue;
            }
        }

        if (minEdge == nullptr)
            break;

        currentVertex = minEdge->getDest();
    }


}