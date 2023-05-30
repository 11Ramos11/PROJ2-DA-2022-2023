//
// Created by Ramos on 5/30/2023.
//

#ifndef PROJ2_DA_2022_2023_OTHERHEURISTICS_H
#define PROJ2_DA_2022_2023_OTHERHEURISTICS_H


#include "Graph.h"
#include "Tour.h"

class OtherHeuristics {

public:
    int nearestNeighbour(std::shared_ptr<Graph> graph, Tour &tour);
};


#endif //PROJ2_DA_2022_2023_OTHERHEURISTICS_H
