/** @file Graph.cpp
 *  @brief Contains the Graph Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Graph.h"

Graph::Graph(){}

Graph::Graph(Graph *graph){

    for (Vertex* vertex: graph->getVertexSet())
        this->addVertex(vertex->getId(), vertex->getCoordinates());

    for (Vertex* vertex: graph->getVertexSet()){
        for (Edge* edge: vertex->getAdj()){
            Vertex* origin = findVertex(edge->getOrig()->getId());
            Vertex* dest = findVertex(edge->getDest()->getId());
            origin->addEdge(dest, edge->getWeight());
        }
    }
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}

Vertex * Graph::findVertex(int id) const {

    if (id >= vertexSet.size())
        return nullptr;

    if (vertexSet[id]->getId() == id)
        return vertexSet[id];

    for (Vertex* vertex: vertexSet){
        if (vertex->getId() == id)
            return vertex;  
    }
    return nullptr;
}

void Graph::dfs(int source){

    Vertex* vertex = findVertex(source);
    vertex->setVisited(true);

    for (Edge* edge: vertex->getAdj()){
        if (!edge->getDest()->isVisited())
            dfs(edge->getDest()->getId());
    }
}

bool Graph::addVertex(const int &id, std::shared_ptr<Coordinates> coordinates) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id, coordinates));
    return true;
}

bool Graph::addEdge(const int &source, const int &dest, double w) const {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &source, const int &dest, double w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void Graph::removeVertex(int id) {
    auto it = vertexSet.begin();

    while (it != vertexSet.end()){

        if ((*it)->getId() == id) {
            vertexSet.erase(it);
            break;
        }
        it++;
    }
}
