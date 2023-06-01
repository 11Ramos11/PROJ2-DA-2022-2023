/** @file Graph.cpp
 *  @brief Contains the Graph Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Graph.h"


Graph::Graph() {}
template<class T1, class T2>
std::size_t pair_hash::operator()(const std::pair<T1, T2> &p) const  {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    std::size_t seed = 0;
    seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);

    return seed;
}


Graph::Graph(Graph *graph) {

    for (Vertex *vertex: graph->getVertexSet())
        this->addVertex(vertex->getId(), vertex->getCoordinates());

    for (Vertex *vertex: graph->getVertexSet()) {
        for (Edge *edge: vertex->getAdj()) {
            Vertex *origin = findVertex(edge->getOrig()->getId());
            Vertex *dest = findVertex(edge->getDest()->getId());
            origin->addEdge(dest, edge->getWeight());
        }
    }
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

Vertex *Graph::findVertex(int id) const {

    auto it = indexMap.find(id);

    if (it == indexMap.end())
        return nullptr;

    unsigned int index = it->second;

    if (index < vertexSet.size() && vertexSet[index]->getId() == id)
        return vertexSet[index];

    for (Vertex *vertex: vertexSet) {
        if (vertex->getId() == id)
            return vertex;
    }

    return nullptr;
}

void Graph::dfs(int source) {

    Vertex *vertex = findVertex(source);
    vertex->setVisited(true);

    for (Edge *edge: vertex->getAdj()) {
        if (!edge->getDest()->isVisited())
            dfs(edge->getDest()->getId());
    }
}

bool Graph::addVertex(const int &id, std::shared_ptr<Coordinates> coordinates) {
    if (findVertex(id) != nullptr)
        return false;
    indexMap.insert(std::pair<int, int>(id, vertexSet.size()));
    vertexSet.push_back(new Vertex(id, coordinates));
    return true;
}

bool Graph::addEdge(const int &source, const int &dest, double w)  {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    edges.emplace(std::make_pair(source, dest), e1);
    return true;
}

bool Graph::addBidirectionalEdge(const int &source, const int &dest, double w) {
    auto v1 = findVertex(source);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    edges.emplace(std::make_pair(source, dest), e1);
    edges.emplace(std::make_pair(dest, source), e2);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

double Graph::getEdgeWeightBetween(Vertex *vertex1, Vertex *vertex2) {
    for (Edge *edge: vertex1->getAdj()) {
        if (edge->getDest()->getId() == vertex2->getId()) {
            return edge->getWeight();
        }
    }
    return std::numeric_limits<double>::max();
}

void Graph::removeVertex(int id) {
    auto it = vertexSet.begin();

    while (it != vertexSet.end()) {

        if ((*it)->getId() == id) {
            vertexSet.erase(it);
            break;
        }
        it++;
    }

    for (Vertex* vertex: vertexSet)
        vertex->removeEdge(id);

    indexMap.erase(id);

    for (auto it = indexMap.begin(); it != indexMap.end(); it++){
        if (it->second > indexMap.find(id)->second)
            it->second--;
    }
}

Edge *Graph::getEdge(int source, int dest) const {

    auto it = edges.find(std::make_pair(source, dest));

    if (it == edges.end())
        return nullptr;

    return it->second;
}
