/** @file Analyst.h
 *  @brief Contains the Analyst class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_ANALYST_H
#define PROJ2_DA_2022_2023_ANALYST_H

#include <chrono>
#include "../tour/Tour.h"
#include "Graph.h"

/** @brief Analyst class that provides functionality to analyze the results of different algorithms.
 *
 */
class Analyst {

    //! @brief Stores the graph for which the algorithms to analyze will run.
    std::shared_ptr<Graph> graph;

    //! @brief Stores the lower bound of the TSP, for the graph. It is -1 if it has not been calculated.
    double lowerBound = -1;

    //! @brief Stores the solution of the TSP, for the graph. It is -1 if it has not been calculated.
    double solution = -1;

    //! @brief Stores the start time of the analyses timer.
    std::chrono::time_point<std::chrono::system_clock> start;

    //! @brief Stores the end time of the analyses timer.
    std::chrono::time_point<std::chrono::system_clock> end;

public:

    /** @brief Creates a new Analyst.
     *
     */
    Analyst();

    /** @brief Creates a new Analyst.
     *
     * @param graph The graph for which the algorithms to analyze will run.
     */
    Analyst(std::shared_ptr<Graph> graph);

    /** @brief Determines the 1-Tree when excluding the given vertex.
     *
     * @param id The id of the vertex to exclude.
     *
     * @return The 1-Tree cost.
     */
    double oneTreeLB(unsigned int id);

    /** @brief Determines a random lower bound of the TSP.
     *
     * It uses a random vertex from the graph to determine the 1-Tree, by calling the oneTreeLB method.
     *
     * @return The random lower bound.
     */
    double randomLowerBound();

    /** @brief Determines the maximum lower bound of the TSP.
     *
     * It determines the 1-Tree for each vertex in the graph, by calling the oneTreeLB method.
     * It then returns the maximum of those 1-Tree costs.
     *
     * @return The lower bound.
     */
    double maximumLowerBound();

    /** @brief Determines an approximation of the lower bound of the TSP.
     *
     * It determines the 1-Tree for a random set of vertexes in the graph, by calling the oneTreeLB method.
     * It then returns the maximum of those 1-Tree costs.
     *
     * @return The lower bound.
     */
    double approximatedLowerBound();

    /** @brief Unsets the lower bound.
     *
     */
    void removeLowerBound();

    /** @brief Starts the timer.
     *
     *  It records the current time in the private member variable start.
     */
    void startTimer();

    /** @brief Stops the timer.
     *
     * It records the current time in the private member variable end.
     */
    void stopTimer();

    /** @brief Displays the analysis of the results of an approximation algorithm.
     *
     * It displays the elapsed time, the approximation ratio to the lower bound, the tour and its cost.
     *
     * @param tour The tour to analyze.
     */
    void analyzeApproximation(Tour tour);

    /** @brief Displays the analysis of the results for the backtracking algorithm.
     *
     * It displays the elapsed time, the approximation ratio to the solution, the tour and its cost.
     *
     * @param tour The tour to analyze.
     */
    void analyzeSolution(Tour tour);
};


#endif //PROJ2_DA_2022_2023_ANALYST_H
