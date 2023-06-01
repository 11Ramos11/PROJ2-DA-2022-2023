//
// Created by Ramos on 5/30/2023.
//

#include "Tour.h"

void Tour::setTour(std::vector<Edge*> tourEdges){

    this->tourEdges = tourEdges;
    this->tourVertexes.clear();

    for (Edge* edge: tourEdges) {
        tourVertexes.push_back(edge->getOrig());
    }

    cost = 0;

    for (Edge* edge: tourEdges) {
        cost += edge->getWeight();
    }
}

void Tour::print() {

    std::cout << "Tour: ";

    for (Vertex* vertex: tourVertexes) {
        std::cout << vertex->getId() << "->";
    }

    std::cout << tourVertexes[0]->getId() << std::endl;

    std::cout << std::endl;

    std::cout << "Cost: " << cost << std::endl;
}

std::vector<Vertex *> Tour::getVertexes() {
    return tourVertexes;
}

std::vector<Edge *> Tour::getEdges() {
    return tourEdges;
}

double Tour::getCost() {
    return cost;
}
