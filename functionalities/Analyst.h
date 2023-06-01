//
// Created by Ramos on 5/31/2023.
//

#ifndef PROJ2_DA_2022_2023_ANALYST_H
#define PROJ2_DA_2022_2023_ANALYST_H

#include "Tour.h"
#include "Graph.h"

class Analyst {

    std::shared_ptr<Graph> graph;

public:

    Analyst(std::shared_ptr<Graph> graph);

    void analyze(Tour tour, unsigned int time);

    double oneTreeLB(unsigned int id);

    double randomLowerBound();

    double MaximumLowerBound();
};


#endif //PROJ2_DA_2022_2023_ANALYST_H
