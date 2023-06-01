/** @file OtherHeuristics.h
 *  @brief Contains the OtherHeuristics class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

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
