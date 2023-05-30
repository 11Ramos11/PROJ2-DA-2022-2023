/** @file FileReader.h
 *  @brief Contains the FileReader class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ1_DA_2022_2023_FILEREADER_H
#define PROJ1_DA_2022_2023_FILEREADER_H

#include <map>
#include <unordered_map>
#include "../../data-structure/Graph.h"

enum graphType {
    TOY_GRAPH,
    REAL_GRAPH,
    EXTRA_GRAPH
};

/** @brief FileReader class to deal with data set files.
 *
 */
class FileReader {

    std::shared_ptr<Graph> graph;

public:

    /**@brief Creates a new FileReader.
     *
     */
    FileReader();

    int read(graphType type, const std::string &name, std::shared_ptr<Graph> &graph);

    int readToyGraph(const std::string &fileName);

    int readRealGraph(const std::string &folderName);

    int readExtraGraph(const std::string &fileName);
};

#endif //PROJ1_DA_2022_2023_FILEREADER_H
