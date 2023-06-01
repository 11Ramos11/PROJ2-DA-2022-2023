/** @file Heuristic.cpp
 *  @brief Contains the Heuristic Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Heuristic.h"
#include "../../functionalities/Tour.h"

Heuristic::Heuristic(std::shared_ptr<Graph> &graph) : graph(graph) {}

std::vector<std::tuple<int, int, double>> Heuristic::prim() {
    std::vector<std::tuple<int, int, double>> mst;

    for (auto vertex: graph->getVertexSet()) {
        vertex->setDist(std::numeric_limits<double>::max());
        vertex->setPath(nullptr);
        vertex->setVisited(false);
    }

    Vertex *firstVertex = graph->getVertexSet().front();
    firstVertex->setDist(0);

    MutablePriorityQueue<Vertex> q;
    q.insert(firstVertex);
    while (!q.empty()) {
        auto v = q.extractMin();
        v->setVisited(true);
        for (auto &edge: v->getAdj()) {
            Vertex *dest = edge->getDest();
            if (!dest->isVisited()) {
                auto oldDistance = dest->getDist();
                if (edge->getWeight() < oldDistance) {
                    dest->setDist(edge->getWeight());
                    dest->setPath(edge);
                    oldDistance == std::numeric_limits<double>::max() ? q.insert(dest) : q.decreaseKey(dest);
                }
            }
        }
    }

    for (auto vertex: graph->getVertexSet()) {
        if(vertex->getPath() != nullptr){
            mst.push_back(std::make_tuple(vertex->getId(),
                                          vertex->getPath()->getOrig()->getId(),
                                          vertex->getPath()->getWeight()));
        }
    }

    return mst;
}

Graph Heuristic::buildMst(){

    std::vector<std::tuple<int, int, double>> mst = prim();
    Graph subgraphMst;

    for(auto& i : graph->getVertexSet()){
        subgraphMst.addVertex(i->getId(), nullptr);
    }

    for(auto& i : mst){
        const int source = std::get<0>(i);
        const int destination = std::get<1>(i);
        double weight = std::get<2>(i);
        subgraphMst.addBidirectionalEdge(source, destination, weight);
    }

    return subgraphMst;
}

void Heuristic::dfsAuxiliary(Vertex *v, std::vector<int> & tour) {
    v->setVisited(true);
    tour.push_back(v->getId());

    for (auto & edge : v->getAdj()) {
        auto vertexDest = edge->getDest();
        if (!vertexDest->isVisited()) {
            dfsAuxiliary(vertexDest, tour);
        }
    }
}

Tour Heuristic::dfs(){
    std::vector<int> tourIds;
    std::pair<double, std::vector<int>> answer;

    Graph subgraph = buildMst();

    auto vertex = subgraph.findVertex(0);

    for (auto v : subgraph.getVertexSet()) {
        v->setVisited(false);
    }

    dfsAuxiliary(vertex, tourIds);

    std::vector<Edge*> tourEdges;

    Edge* connectionToOrigin = graph->getEdge(tourIds[tourIds.size() - 1], tourIds[0]);
    if (connectionToOrigin != nullptr){
        tourEdges.reserve(tourIds.size());
        for (int i = 0; i < tourIds.size() - 1; i++){
            tourEdges.push_back(graph->getEdge(tourIds[i], tourIds[i+1]));
        }
        tourEdges.push_back(connectionToOrigin);
    }

    Tour tour;
    tour.setTour(tourEdges);

    return tour;
}


