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

//! @brief Initialization of the type of the graph.
enum graphType {
    TOY_GRAPH,
    REAL_GRAPH,
    EXTRA_GRAPH
};

/** @brief FileReader class to deal with data set files.
 *
 */
class FileReader {

    //! @brief Initialization of the graph.
    std::shared_ptr<Graph> graph;

public:

    /**@brief Creates a new FileReader.
     *
     */
    FileReader();

    /**@brief Reads a graph from a file.
     *
     * @param type Type of the graph to be read (TOY_GRAPH, REAL_GRAPH, or EXTRA_GRAPH).
     * @param name Name of the file or directory.
     * @param graph Shared pointer to the Graph object to be populated.
     *
     * @return 0 if the reading operation was successful, 1 otherwise.
     */
    int read(graphType type, const std::string &name, std::shared_ptr<Graph> &graph);

    /**@brief Reads a toy graph from a .csv file.
     *
     * @param fileName Name of the .csv file.
     *
     * @return 0 if the reading operation was successful, 1 otherwise.
     */
    int readToyGraph(const std::string &fileName);

    /**@brief Reads a real-world graph from a directory.
     *
     * The directory should contain nodes.csv and edges.csv files.
     *
     * @param folderName Name of the directory.
     *
     * @return 0 if the reading operation was successful, 1 otherwise.
     */
    int readRealGraph(const std::string &folderName);

    /**@brief Reads an extra fully connected graph from a .csv file.
     *
     * @param fileName Name of the .csv file.
     *
     * @return 0 if the reading operation was successful, 1 otherwise.
     */
    int readExtraGraph(const std::string &fileName);
};

#endif //PROJ1_DA_2022_2023_FILEREADER_H
