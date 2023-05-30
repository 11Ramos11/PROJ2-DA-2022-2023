//
// Created by Matilde on 29/05/2023.
//

#ifndef PROJ2_DA_2022_2023_BACKTRAKING_H
#define PROJ2_DA_2022_2023_BACKTRAKING_H


#include "Graph.h"

class Backtraking {

private:
    std::shared_ptr<Graph> graph;

public:
    Backtraking(std::shared_ptr<Graph> &graph);

    std::pair<double, std::vector<Vertex *>> tspBacktraking();
};


#endif //PROJ2_DA_2022_2023_BACKTRAKING_H
