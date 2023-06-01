/** @file Application.h
 *  @brief Contains the Application class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ1_DA_2022_2023_APPLICATION_H
#define PROJ1_DA_2022_2023_APPLICATION_H

#include <unordered_map>
#include <string>
#include <stack>
#include "../file-reader/FileReader.h"
#include "../classes/backtraking/Backtracking.h"
#include "../classes/heuristic/Heuristic.h"
#include "../classes/analyst/Analyst.h"


/** @brief Initializes and manages all the components of the application.
 *
 * Intended to be instanced once.
 * Manages the interaction between the user and the application.
 */
class Application {

    //! @brief Initialization of the graph.
    std::shared_ptr<Graph> graph;

    //! @brief Initialization of the fileReader.
    FileReader fileReader = FileReader();

    //! @brief Initialization of the heuristic.
    Heuristic heuristic = Heuristic(graph);

    //! @brief Initialization of the analyst.
    Analyst analyst;

    //! @brief Initialization of the currentTour.
    Tour currentTour;

    //! @brief Creates the initial menu options.
    enum State {
        WELCOME_MENU,
        READ_MENU,
        TOY_MENU,
        EXTRA_MENU,
        REAL_MENU,
        FUNC_MENU,
        LOWER_BOUND_MENU,
        OTHER_HEURISTICS_MENU,
    };

    //! @brief Initialization of the user choice.
    int choice;

    //! @brief Initialization of the string type user choice.
    std::string stringChoice;

    //! @brief Initialization of the stack that contains the application states.
    std::stack<State> state;

public:

    /** @brief Starts the project.
     *
     * @return Void.
     */
    void start();

    /** @brief Controls the application states.
     *
     * @return Void.
     */
    void getMenu();

    /** @brief Displays the welcome menu.
     *
     * @return Void.
     */
    void welcomeMenu();

    /** @brief Displays the read files menu with the different categories of graphs.
     *
     * @return Void.
     */
    void readMenu();

    /** @brief Displays the graphs of toy-graphs category.
     *
     * @return Void.
     */
    void toyMenu();

    /** @brief Displays the graphs of extra-fully-connected-graphs category.
     *
     * @return Void.
     */
    void extraMenu();

    /** @brief Displays the graphs of real-world-graphs category.
     *
     * @return Void.
     */
    void realMenu();

    /** @brief Displays the main algorithms.
     *
     * @return Void.
     */
    void functionalitiesMenu();

    /** @brief Displays the various ways of comparison of the values.
     *
     * @return Void.
     */
    void lowerBoundMenu();

    /** @brief Displays the categories of others heuristics.
     *
     * @return Void.
     */
    void otherHeuristicsMenu();
};

#endif //PROJ1_DA_2022_2023_APPLICATION_H
