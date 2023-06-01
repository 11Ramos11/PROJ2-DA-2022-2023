//
// Created by Ramos on 5/30/2023.
//

#ifndef PROJ2_DA_2022_2023_OTHERHEURISTICS_H
#define PROJ2_DA_2022_2023_OTHERHEURISTICS_H


#include "Graph.h"
#include "../tour/Tour.h"

class OtherHeuristics {

    std::shared_ptr<Graph> graph;
public:

    OtherHeuristics(std::shared_ptr<Graph> graph);

    int nearestNeighbour(Tour &tour);

    Tour twoOpt(Tour &tour);

    Tour twoOptSwap(Tour &tour, int i, int j);

    bool shouldAccept(unsigned int oldCost, unsigned int newCost, float temperature);

    Tour simulatedAnnealing(Tour &tour);
};


#endif //PROJ2_DA_2022_2023_OTHERHEURISTICS_H
