/** @file OtherHeuristics.h
 *  @brief Contains the OtherHeuristics class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_OTHERHEURISTICS_H
#define PROJ2_DA_2022_2023_OTHERHEURISTICS_H


#include "Graph.h"
#include "../tour/Tour.h"

/** @brief OtherHeuristics class that runs a set of other heuristics.
 *
 * Within this class, the nearest neighbour heuristic, the 2-opt heuristic and
 * the simulated annelaing heuristic are implemented.
 */
class OtherHeuristics {

    //! @brief The graph to which the heuristics are applied.
    std::shared_ptr<Graph> graph;
public:

    /**@brief Creates a new OtherHeuristics.
     *
     * @param graph The graph to which the heuristics are applied.
     */
    OtherHeuristics(std::shared_ptr<Graph> graph);

    /**@brief Runs the nearest neighbour heuristic.
     *
     * Time Complexity: O(|V|^2)
     *
     * @param tour The tour in which the determined approximation is stored.
     *
     * @return 0 if successful, 1 otherwise.
     */
    int nearestNeighbour(Tour &tour);

    /**@brief Runs the 2-opt heuristic.
     *
     * Time Complexity: O(|E|^3)
     *
     * @param tour The tour to which the 2-opt heuristic is applied.
     *
     * @return Improved tour after the 2-opt heuristic.
     */
    Tour twoOpt(Tour &tour);

    /**@brief Swaps two edges in a tour.
     *
     * Time Complexity: O(|E|)
     *
     * @param tour The tour to which the swap is applied.
     * @param i The index of the first edge.
     * @param j The index of the second edge.
     *
     * @return The tour after the swap.
     */
    Tour twoOptSwap(Tour &tour, int i, int j);

    /**@bried Determines if a new tour should be accepted, within the simulated annealing.
     *
     * The new tour is accepted if the new cost is lower than the old cost, or if the
     * new cost is higher than the old cost but the probability of accepting it checks out.
     *
     * @param oldCost The cost of the old tour.
     * @param newCost The cost of the new tour.
     * @param temperature The temperature of the simulated annealing.
     *
     * @return True if the new tour should be accepted, false otherwise.
     */
    bool shouldAccept(unsigned int oldCost, unsigned int newCost, double temperature);

    /**@brief Runs the simulated annealing heuristic.
     *
     * Time Complexity: O(|E|^3)
     *
     * @param tour The tour to which the simulated annealing heuristic is applied.
     *
     * @return Improved tour after the simulated annealing heuristic.
     */
    Tour simulatedAnnealing(Tour &tour);
};


#endif //PROJ2_DA_2022_2023_OTHERHEURISTICS_H
