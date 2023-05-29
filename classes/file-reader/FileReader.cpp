/** @file FileReader.cpp
 *  @brief Contains the FileReader Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include "FileReader.h"

FileReader::FileReader()= default;

int FileReader::read(graphType type, std::string fileName) {

    switch (type) {
        case TOY_GRAPH: {
            if (readToyGraph(fileName))
                return 1;
            break;
        }
        case REAL_GRAPH: {
            if (readRealGraph(fileName))
                return 1;
            break;
        }
        case EXTRA_GRAPH: {
            if (readExtraGraph(fileName))
                return 1;
            break;
        }
    }
    return 0;
}

int FileReader::readToyGraph(std::string fileName){

    Graph graph;

    std::ifstream file(fileName);

    if (file.fail()) {
        std::cout << "Error opening file " << fileName << std::endl;
        return 1;
    }

    std::string line;

    std::getline(file, line);

    std::string origin, destination, distance;

    int id = 1;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, origin, ',');
        std::getline(ss, destination, ',');
        std::getline(ss, distance);

        graph.addVertex(origin);
        graph.addVertex(destination);
        graph.addEdge(origin, destination, std::stoi(distance));
    }
    return 0;
}

int FileReader::readRealGraph(std::string fileName){


}

int FileReader::readExtraGraph(std::string fileName){}
//int FileReader::readStations(std::unordered_map<std::string, std::shared_ptr<Station>> &stations, Graph &railwayNetwork) {
//
//    std::ifstream stationsFile(stationsFileName);
//
//    if (stationsFile.fail())
//        return -1;
//
//    std::string entry;
//
//    getline(stationsFile, entry);
//
//    std::string name, district, municipality, township, line;
//
//    int id = 1;
//
//    do {
//        getline(stationsFile, name, ',');
//        if (name.empty()) break;
//        getline(stationsFile, district, ',');
//        getline(stationsFile, municipality, ',');
//        getline(stationsFile, township, ',');
//        getline(stationsFile, line);
//
//        std::shared_ptr<Station> stationPTR = std::make_shared<Station>(id, name, district, municipality, township, line);
//        auto insertion = stations.insert(std::make_pair(name, stationPTR));
//        if(insertion.second) {
//            railwayNetwork.addVertex(id, stationPTR);
//            id++;
//        }
//
//    } while (true);
//
//    return 0;
//}
//
//int FileReader::readNetwork(std::unordered_map<std::string, std::shared_ptr<Station>>& stations, Graph &railwayNetwork) {
//
//    std::ifstream networkFile(networkFileName);
//
//    if (networkFile.fail())
//        return -1;
//
//    std::string entry;
//
//    getline(networkFile, entry);
//
//    std::string stationA, stationB, capacity, service;
//
//    do {
//        getline(networkFile, stationA, ',');
//        if (stationA.empty()) break;
//        getline(networkFile, stationB, ',');
//        getline(networkFile, capacity, ',');
//        getline(networkFile, service);
//
//        ServiceType serviceType;
//
//       if (service == "STANDARD")
//            serviceType = STANDARD;
//       else if (service == "ALFA PENDULAR")
//            serviceType = ALFA_PENDULAR;
//       else
//           continue;
//
//       double capacityDouble = stod(capacity);
//
//       railwayNetwork.addBidirectionalEdge(
//                stations.at(stationA)->getId(), stations.at(stationB)->getId(),
//                capacityDouble, serviceType);
//
//    } while (true);
//
//    return 0;
//}
//
//void FileReader::reset() {
//    stationsFileName = "../resources/stations.csv";
//    networkFileName = "../resources/network.csv";
//}
//
//void FileReader::setFiles(std::string stationsFileName, std::string networkFileName) {
//    this->stationsFileName = "../resources/" + stationsFileName;
//    this->networkFileName = "../resources/" + networkFileName;
//}
