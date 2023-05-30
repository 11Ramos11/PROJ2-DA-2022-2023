//
// Created by Ramos on 5/30/2023.
//

#ifndef PROJ2_DA_2022_2023_TOUR_H
#define PROJ2_DA_2022_2023_TOUR_H


#include "VertexEdge.h"

class Tour {


    std::vector<Vertex*> tour;

    double cost;

public:

    void setTour(std::vector<Edge*> tourEdges);

    void print();
};


#endif //PROJ2_DA_2022_2023_TOUR_H
