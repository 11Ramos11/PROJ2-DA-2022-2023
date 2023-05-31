//
// Created by Ramos on 5/31/2023.
//

#include "Analyst.h"

#include <utility>

Analyst::Analyst(std::shared_ptr<Graph> graph) : graph(std::move(graph)) {}

struct CompareEdges {
    bool operator()(const Edge* e1, const Edge* e2) const {
        return e1->getWeight() > e2->getWeight();
    }
};


double Analyst::oneTreeLB(unsigned int id){

    Vertex* excluded = graph->findVertex(id);

    for (Vertex* vertex: graph->getVertexSet()){
        vertex->setVisited(false);
    }

    excluded->setVisited(true);

    std::vector<Edge*> mst;
    std::priority_queue<Edge*, std::vector<Edge*>, CompareEdges> edges;

    for(Vertex* vertex: graph->getVertexSet()){
        if (vertex != excluded){
            vertex->setVisited(true);
            for (Edge* edge: vertex->getAdj()){
                if (edge->getDest()->getId() != excluded->getId())
                    edges.push(edge);
            }
            break;
        }
    }

    while (mst.size() < graph->getNumVertex() - 2){

        Edge* minEdge = edges.top();
        edges.pop();

        if (minEdge->getDest()->isVisited())
            continue;

        mst.push_back(minEdge);
        minEdge->getDest()->setVisited(true);
        for (Edge* edge: minEdge->getDest()->getAdj()){
            if (!edge->getDest()->isVisited())
                edges.push(edge);
        }
    }

    Edge* lowestEdge1 = nullptr;
    Edge* lowestEdge2 = nullptr;

    for (Edge* edge: excluded->getAdj()){

        if (lowestEdge1 == nullptr || edge->getWeight() < lowestEdge1->getWeight())
            lowestEdge2 = lowestEdge1,
            lowestEdge1 = edge;

        else if (lowestEdge2 == nullptr || edge->getWeight() < lowestEdge2->getWeight())
            lowestEdge2 = edge;
    }

    mst.push_back(lowestEdge1);
    mst.push_back(lowestEdge2);

    double lowerBound = 0;

    for (Edge* edge: mst)
        lowerBound += edge->getWeight();

    return lowerBound;
}

double Analyst::randomLowerBound(){

    if (graph->getNumVertex() == 0)
        return 0;

    unsigned int randId = rand() % graph->getNumVertex();

    return oneTreeLB(randId);
}

double::Analyst::MaximumLowerBound(){

    double maxLowerBound = 0;

    for (Vertex* vertex: graph->getVertexSet()){
        double oneTreeBound = oneTreeLB(vertex->getId());

        if (oneTreeBound > maxLowerBound)
            maxLowerBound = oneTreeBound;
    }

    return maxLowerBound;
}

void Analyst::analyze(Tour tour, unsigned int time) {

    for (Vertex* vertex: graph->getVertexSet()){


    }
}
