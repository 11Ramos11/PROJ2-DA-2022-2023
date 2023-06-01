//
// Created by Ramos on 5/30/2023.
//

#include <cmath>
#include "OtherHeuristics.h"

OtherHeuristics::OtherHeuristics(std::shared_ptr<Graph> graph) : graph(graph) {}

int OtherHeuristics::nearestNeighbour(Tour &tour){

    if (graph->getNumVertex() == 0)
        return 1;

    for (Vertex* vertex: graph->getVertexSet()) {
        vertex->setVisited(false);
        for (Edge* edge: vertex->getAdj()){
            edge->setUsed(false);
        }
    }

    std::vector<Vertex*> vertexSet = graph->getVertexSet();

    std::vector<Edge*> tourEdges;

    Vertex* origin = vertexSet[0];

    Vertex* vertex = origin;

    while(true){

        Edge* minEdge = nullptr;

        for (Edge* edge: vertex->getAdj()){
            if (!edge->getDest()->isVisited()){
                if (minEdge == nullptr){
                    if (!edge->isUsed()) {
                        minEdge = edge;
                    }
                } else if (edge->getWeight() < minEdge->getWeight() && !edge->isUsed()){
                    minEdge = edge;
                }
            }
        }

        if (minEdge != nullptr){
            tourEdges.push_back(minEdge);
            minEdge->setUsed(true);
            vertex->setVisited(true);
            vertex = minEdge->getDest();
        } else {
            vertex->setVisited(false);
            for (Edge* edge: vertex->getAdj()){
                edge->setUsed(false);
            }
            if (tourEdges.size() == 0) {
                break;
            }
            vertex = tourEdges[tourEdges.size() - 1]->getOrig();
            tourEdges.pop_back();
            continue;
        }

        if (tourEdges.size() == vertexSet.size() - 1){
            Edge* lastEdge = nullptr;
            for (Edge* edge: vertex->getAdj()){
                if (edge->getDest() == origin){
                    lastEdge = edge;
                    break;
                }
            }
            if (lastEdge != nullptr){
                tourEdges.push_back(lastEdge);
                lastEdge->setUsed(true);
                break;
            } else {
                vertex->setVisited(false);
                for (Edge* edge: vertex->getAdj()){
                    edge->setUsed(false);
                }
                vertex = tourEdges[tourEdges.size() - 1]->getOrig();
                tourEdges.pop_back();
            }
        }
    }

    tour.setTour(tourEdges);

    return 0;
}

unsigned int calculateImprovements(unsigned int numEdges) {
    unsigned int maxImprovements = 50;

    if (numEdges < 100) {
        return maxImprovements;
    } else if (numEdges < 500) {
        double slope = -static_cast<double>(maxImprovements) / 800.0;
        double improvements = maxImprovements + (numEdges - 100) * slope;
        return static_cast<unsigned int>(improvements);
    } else {
        return maxImprovements / 10;
    }
}

Tour OtherHeuristics::twoOptSwap(Tour &tour, int i, int j){

    std::vector<Edge*> tourEdges = tour.getEdges();

    Tour newTour;
    std::vector<Edge*> newTourEdges;

    newTourEdges.reserve(tourEdges.size());

    for (int c = 0; c < i; c++){
        newTourEdges.push_back(tourEdges[c]);
    }

    Edge* e1 = graph->getEdge(tourEdges[i]->getOrig()->getId(), tourEdges[j]->getOrig()->getId());
    if (e1 == nullptr){
        return tour;
    }
    newTourEdges.push_back(e1);
    for (int c = j - 1; c > i; c--){
        Edge* edge = tourEdges[c];
        newTourEdges.push_back(edge->getReverse());
    }

    Edge* e2 = graph->getEdge(tourEdges[i]->getDest()->getId(), tourEdges[j]->getDest()->getId());
    newTourEdges.push_back(e2);

    if (e2 == nullptr){
        return tour;
    }

    for (int c = j + 1; c < tourEdges.size(); c++){
        newTourEdges.push_back(tourEdges[c]);
    }

    newTour.setTour(newTourEdges);

    return newTour;
}

Tour OtherHeuristics::twoOpt(Tour &tour){

    Tour finalTour = tour;

    unsigned int improvements = calculateImprovements(tour.getEdges().size());

    while (improvements--) {

        std::vector<Edge*> tourEdges = finalTour.getEdges();

        double bestCost = finalTour.getCost();

        for (int i = 0; i < tourEdges.size() - 1; i++){

            for (int j = i + 1; j < tourEdges.size(); j++){

                Tour newTour = twoOptSwap(finalTour,i,j);
                double newCost = round(newTour.getCost() * 1000);
                double oldCost = round(bestCost * 1000);
                if (newCost < oldCost){
                    finalTour = newTour;
                    bestCost = newTour.getCost();
                }
            }
        }
    }
    return finalTour;
}

bool OtherHeuristics::shouldAccept(unsigned int oldCost, unsigned int newCost, float temperature){

    if (newCost < oldCost)
        return true;

    if (newCost == oldCost)
        return false;

    double delta = (newCost - oldCost) / 1000;

    double probability = std::exp((-delta) / temperature);

    float random = (float) rand() / RAND_MAX;

    return random < probability;
}

Tour OtherHeuristics::simulatedAnnealing(Tour &tour){

    unsigned int maxImprovements = calculateImprovements(tour.getEdges().size());
    unsigned int improvements = maxImprovements;

    Tour finalTour = tour;

    unsigned long z = 0;

    while (improvements--){

        std::vector<Edge*> tourEdges = finalTour.getEdges();

        double bestCost = finalTour.getCost();

        for (int i = 0; i < tourEdges.size() - 1; i ++){

            for (int j = i + 1; j < tourEdges.size(); j ++){

                Tour newTour = twoOptSwap(finalTour,i,j);
                unsigned int newCost = round(newTour.getCost() * 1000);
                unsigned int oldCost = round(bestCost * 1000);

                float temperature = 100 * pow(0.99, z);

                if (shouldAccept(oldCost, newCost, temperature)){
                    finalTour = newTour;
                    bestCost = finalTour.getCost();
                    if (graph->getVertexSet().size() < 100)
                        improvements = maxImprovements;
                }
                z++;
            }
        }
    }
    return finalTour;
}