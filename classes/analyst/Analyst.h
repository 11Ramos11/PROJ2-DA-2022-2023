//
// Created by Ramos on 5/31/2023.
//

#ifndef PROJ2_DA_2022_2023_ANALYST_H
#define PROJ2_DA_2022_2023_ANALYST_H

#include <chrono>
#include "../tour/Tour.h"
#include "Graph.h"

class Analyst {

    std::shared_ptr<Graph> graph;

    double lowerBound = -1;

    double solution = -1;

    std::chrono::time_point<std::chrono::system_clock> start, end;

public:

    Analyst();

    Analyst(std::shared_ptr<Graph> graph);

    double oneTreeLB(unsigned int id);

    double randomLowerBound();

    double maximumLowerBound();

    double approximatedLowerBound();

    void removeLowerBound();

    void startTimer();

    void stopTimer();

    void analyzeApproximation(Tour tour);

    void analyzeSolution(Tour tour);
};


#endif //PROJ2_DA_2022_2023_ANALYST_H
