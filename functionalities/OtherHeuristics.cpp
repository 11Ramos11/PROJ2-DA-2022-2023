//
// Created by Ramos on 5/30/2023.
//

#include "OtherHeuristics.h"

int OtherHeuristics::nearestNeighbour(std::shared_ptr<Graph> graph, Tour &tour){

    if (graph->getNumVertex() == 0)
        return 1;

    std::vector<Vertex*> vertexSet = graph->getVertexSet();

    std::vector<Edge*> tourEdges;

    Vertex* origin = vertexSet[0];

    Vertex* currentVertex = origin;

    while (true){

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

        if (minEdge == nullptr) {
            break;
        }
        tourEdges.push_back(minEdge);

        currentVertex = minEdge->getDest();
    }

    tour.setTour(tourEdges);

    return 0;
}