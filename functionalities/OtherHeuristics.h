//
// Created by Ramos on 5/30/2023.
//

#ifndef PROJ2_DA_2022_2023_OTHERHEURISTICS_H
#define PROJ2_DA_2022_2023_OTHERHEURISTICS_H


#include "Graph.h"
#include "Tour.h"

class OtherHeuristics {

    std::shared_ptr<Graph> graph;
public:

    OtherHeuristics(std::shared_ptr<Graph> graph);

    int nearestNeighbours(Tour &tour);

    int twoOpt(Tour &tour);

    Tour twoOptSwap(Tour &tour, int i, int j);
};


#endif //PROJ2_DA_2022_2023_OTHERHEURISTICS_H
