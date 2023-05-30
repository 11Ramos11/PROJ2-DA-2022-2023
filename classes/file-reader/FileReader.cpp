/** @file FileReader.cpp
 *  @brief Contains the FileReader Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include "FileReader.h"

FileReader::FileReader() = default;

int FileReader::read(graphType type, const std::string& name, std::shared_ptr<Graph>& graph) {

    this->graph.reset(new Graph());

    switch (type) {
        case TOY_GRAPH: {
            if (readToyGraph(name))
                return 1;
            break;
        }
        case REAL_GRAPH: {
            if (readRealGraph(name))
                return 1;
            break;
        }
        case EXTRA_GRAPH: {
            if (readExtraGraph(name))
                return 1;
            break;
        }
    }

    graph = this->graph;

    return 0;
}

int FileReader::readToyGraph(const std::string& fileName){

    std::string path = "../data/toy-graphs/" + fileName;

    std::ifstream file(path);

    if (file.fail()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return 1;
    }

    std::string line;

    std::getline(file, line);

    std::string originID, destinationID, distance;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, originID, ',');
        std::getline(ss, destinationID, ',');
        std::getline(ss, distance);

        graph->addVertex(std::stoi(originID), nullptr);
        graph->addVertex(std::stoi(destinationID), nullptr);
        graph->addBidirectionalEdge(std::stoi(originID), std::stoi(destinationID), std::stod(distance));
    }
    return 0;
}


int FileReader::readRealGraph(const std::string& folderName){

    std::string path = "../data/real-world-graphs/" + folderName;

    std::string nodesPath = path + "/nodes.csv";
    std::string edgesPath = path + "/edges.csv";

    std::ifstream nodesFile(nodesPath);

    if (nodesFile.fail()) {
        std::cout << "Error opening file " << nodesPath << std::endl;
        return 1;
    }

    std::string line;

    std::getline(nodesFile, line);

    std::string id, longitude, latitude;

    while (std::getline(nodesFile, line)) {
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, longitude, ',');
        std::getline(ss, latitude);

        Coordinates coordinates = Coordinates(std::stod(longitude), std::stod(latitude));

        std::shared_ptr<Coordinates> coordinatesPTR = std::make_shared<Coordinates>(coordinates);
        graph->addVertex(std::stoi(id), coordinatesPTR);
    }

    std::ifstream edgesFile(edgesPath);

    if (edgesFile.fail()) {
        std::cout << "Error opening file " << edgesPath << std::endl;
        return 1;
    }

    std::getline(edgesFile, line);

    std::string originID, destinationID, distance;

    while (std::getline(edgesFile, line)) {
        std::stringstream ss(line);
        std::getline(ss, originID, ',');
        std::getline(ss, destinationID, ',');
        std::getline(ss, distance);

        graph->addBidirectionalEdge(
            std::stoi(originID),
            std::stoi(destinationID),
            std::stod(distance)
        );
    }

    return 0;
}

int FileReader::readExtraGraph(const std::string& fileName){

    std::string path = "../data/extra-fully-connected-graphs/" + fileName;

    std::ifstream file(path);

    if (file.fail()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return 1;
    }

    std::string line;

    std::getline(file, line);

    std::string originID, destinationID, distance;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, originID, ',');
        std::getline(ss, destinationID, ',');
        std::getline(ss, distance);

        graph->addVertex(std::stoi(originID), nullptr);
        graph->addVertex(std::stoi(destinationID), nullptr);
        graph->addBidirectionalEdge(std::stoi(originID), std::stoi(destinationID), std::stod(distance));
    }
    return 0;
}

