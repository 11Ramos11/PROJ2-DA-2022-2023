//
// Created by Ramos on 5/30/2023.
//

#include "Tour.h"

void Tour::setTour(std::vector<Edge*> tourEdges){


    for (Edge* edge: tourEdges) {
        tour.push_back(edge->getOrig());
    }

    cost = 0;

    for (Edge* edge: tourEdges) {
        cost += edge->getWeight();
    }

    Edge* lastEdge = tourEdges[tourEdges.size() - 1];
    Vertex* lastVertex = lastEdge->getDest();

    for (Edge* edge: lastVertex->getAdj()) {
        if (edge->getDest() == tour[0]) {
            cost += edge->getWeight();
            break;
        }
    }
}

void Tour::print() {

    std::cout << "Tour: ";

    for (Vertex* vertex: tour) {
        std::cout << vertex->getId() << "->";
    }

    std::cout << tour[0]->getId() << std::endl;

    std::cout << std::endl;

    std::cout << "Cost: " << cost << std::endl;
}