//
// Created by Ramos on 5/30/2023.
//

#ifndef PROJ2_DA_2022_2023_TOUR_H
#define PROJ2_DA_2022_2023_TOUR_H


#include "VertexEdge.h"

class Tour {

    std::vector<Edge*> tourEdges;

    std::vector<Vertex*> tourVertexes;

    double cost;

public:

    void setTour(std::vector<Edge*> tourEdges);

    std::vector<Vertex*> getVertexes();

    std::vector<Edge*> getEdges();

    double getCost();

    void print();
};


#endif //PROJ2_DA_2022_2023_TOUR_H
