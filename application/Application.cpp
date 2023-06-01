/** @file Application.cpp
 *  @brief Contains the Application Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"
#include "../functionalities/OtherHeuristics.h"

void Application::start() {

//    fileReader.read(TOY_GRAPH, "shipping", graph);
    /*timer.start();
    fileReader.read(TOY_GRAPH, "stadiums", graph);*/

//    std::cout << "Time to read the graph: " << timer.stop() << " ms" << std::endl;

    /*heuristic = Heuristic(graph);
    std::vector<std::tuple<int, int, double>> res = heuristic.prim();
    for(const auto& t : res){
        int source = std::get<0>(t);
        int destination = std::get<1>(t);
        double weight = std::get<2>(t);
        std::cout << "(" << source << ", " << destination << ", " << weight << ")-";
    }*/

    /*std::pair<double, std::vector<int>> tour = heuristic.dfs();
    std::cout << tour.first << std::endl;
    for(auto k : tour.second){
        std::cout << k << " ";
    }*/


    /*for (Vertex* vertex: graph->getVertexSet()){
        std::cout << "Id: " << vertex->getId() << std::endl;
    }
    backtraking = Backtracking(graph);
    auto res = backtraking.tspBacktracking();
    std::cout << res.first << std::endl;

    //std::cout << "Time to read the graph: " << timer.stop() << " ms" << std::endl;

//    fileReader.read(EXTRA_GRAPH, "edges_900", graph);
    std::cout << "---------------------------------------------------------------" << std::endl;*/

    //std::cout << res.first << std::endl;
    state.push(WELCOME_MENU);
    getMenu();
}

void Application::welcomeMenu(){

    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << " Welcome to the Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Click ENTER for the options";
    std::cin.ignore(1000,'\n');

    state.push(READ_MENU);
    getMenu();
}

void Application::readMenu(){

    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Read Toy Graphs" << std::endl;
        std::cout << "2. Read Extra Fully Connected Graphs" << std::endl;
        std::cout << "3. Read Real Word Graphs" << std::endl;
        std::cout << "0. Quit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" ||stringChoice=="0")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice=="1" ||stringChoice=="2" || stringChoice=="3" ||stringChoice=="0"));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1:
            state.push(TOY_MENU);
            break;
        case 2:
            state.push(EXTRA_MENU);
            break;
        case 3: {
            state.push(REAL_MENU);
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::toyMenu(){
    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Shipping" << std::endl;
        std::cout << "2. Stadiums" << std::endl;
        std::cout << "3. Tourism" << std::endl;
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" ||stringChoice=="0" ||stringChoice=="9")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice=="1" ||stringChoice=="2" || stringChoice=="3" ||stringChoice=="0" ||stringChoice=="9"));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1:
            fileReader.read(TOY_GRAPH, "shipping", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        case 2:
            fileReader.read(TOY_GRAPH, "stadiums", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        case 3: {
            fileReader.read(TOY_GRAPH, "tourism", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 9: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::extraMenu(){
    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Edges_25" << std::endl;
        std::cout << "2. Edges_50" << std::endl;
        std::cout << "3. Edges_75" << std::endl;
        std::cout << "4. Edges_100" << std::endl;
        std::cout << "5. Edges_200" << std::endl;
        std::cout << "6. Edges_300" << std::endl;
        std::cout << "7. Edges_400" << std::endl;
        std::cout << "8. Edges_500" << std::endl;
        std::cout << "9. Edges_600" << std::endl;
        std::cout << "10. Edges_700" << std::endl;
        std::cout << "11. Edges_800" << std::endl;
        std::cout << "12. Edges_900" << std::endl;
        std::cout << "13. Go back" << std::endl;
        std::cout << "0. Quit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" || stringChoice=="9" ||stringChoice=="0" ||
            stringChoice=="4" ||stringChoice=="5" ||stringChoice=="6" || stringChoice=="7" ||stringChoice=="8" ||
            stringChoice=="10" ||stringChoice=="11" ||stringChoice=="12" || stringChoice=="13")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" || stringChoice=="9" ||stringChoice=="0" ||
            stringChoice=="4" ||stringChoice=="5" ||stringChoice=="6" || stringChoice=="7" ||stringChoice=="8" ||
            stringChoice=="10" ||stringChoice=="11" ||stringChoice=="12" || stringChoice=="13"));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1:
            fileReader.read(EXTRA_GRAPH, "edges_25", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        case 2:
            fileReader.read(EXTRA_GRAPH, "edges_50", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        case 3: {
            fileReader.read(EXTRA_GRAPH, "edges_75", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 4: {
            fileReader.read(EXTRA_GRAPH, "edges_100", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 5: {
            fileReader.read(EXTRA_GRAPH, "edges_200", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 6: {
            fileReader.read(EXTRA_GRAPH, "edges_300", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 7: {
            fileReader.read(EXTRA_GRAPH, "edges_400", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 8: {
            fileReader.read(EXTRA_GRAPH, "edges_500", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 9: {
            fileReader.read(EXTRA_GRAPH, "edges_600", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 10: {
            fileReader.read(EXTRA_GRAPH, "edges_700", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 11: {
            fileReader.read(EXTRA_GRAPH, "edges_800", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 12: {
            fileReader.read(EXTRA_GRAPH, "edges_900", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 13: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::realMenu(){
    do{
       std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Graph1" << std::endl;
        std::cout << "2. Graph2" << std::endl;
        std::cout << "3. Graph3" << std::endl;
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice =="9")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice =="9"));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1: {
            fileReader.read(REAL_GRAPH, "graph1", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 2: {
            fileReader.read(REAL_GRAPH, "graph2", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 3: {
            fileReader.read(REAL_GRAPH, "graph3", graph);
            analyst = Analyst(graph);
            state.push(FUNC_MENU);
            break;
        }
        case 9: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }

    getMenu();
}

void Application::functionalitiesMenu(){

    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Backtracking Algorithm" << std::endl;
        std::cout << "2. Triangular Approximation Heuristic" << std::endl;
        std::cout << "3. Other Heuristics" << std::endl;
        std::cout << "8. Generate Lower Bound For Comparison" << std::endl;
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice == "8" || stringChoice =="9")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice == "8" || stringChoice =="9"));

    choice = std::stoi(
            stringChoice);

    switch(choice){
        case 1: {
            analyst.startTimer();
            currentTour = Backtracking(graph).tspBacktracking();
            analyst.analyze(currentTour);
            break;
        }
        case 2: {
            analyst.startTimer();
            currentTour = Heuristic(graph).dfs();
            analyst.analyze(currentTour);
            break;
        }
        case 3: {
            this->currentTour = Tour();
            state.push(OTHER_HEURISTICS_MENU);
            break;
        }
        case 8: {
            state.push(LOWER_BOUND_MENU);
            break;
        }
        case 9: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::lowerBoundMenu(){

    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!    " << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Generate Random 1-Tree LowerBound" << std::endl;
        std::cout << "2. Generate Approximated 1-Tree LowerBound" << std::endl;
        std::cout << "3. Generate Maximum 1-Tree LowerBound" << std::endl;
        std::cout << "4. Remove 1-Tree LowerBound" << std::endl;
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice == "4" || stringChoice =="9")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="2" || stringChoice == "3" || stringChoice == "4" || stringChoice =="9"));

    choice = std::stoi(
            stringChoice);

    double lowerBound;

    switch(choice){
        case 1: {
            lowerBound = analyst.randomLowerBound();
            std::cout << "Lower Bound Generated: " << lowerBound << std::endl;
            break;
        }
        case 2: {
            lowerBound = analyst.approximatedLowerBound();
            std::cout << "Lower Bound Generated: " << lowerBound << std::endl;
            break;
        }
        case 3: {
            lowerBound = analyst.maximumLowerBound();
            std::cout << "Lower Bound Generated: " << lowerBound << std::endl;
            break;
        }
        case 4: {
            analyst.removeLowerBound();
            break;
        }
        case 9: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::otherHeuristicsMenu(){

    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "    Routing Algorithm for Ocean Shipping and Urban Deliveries!    " << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "1. Generate Nearest Neighbour Approximation" << std::endl;
        if (currentTour.isSetted()){
            std::cout << "2. Improve Approximation with 2-Opt" << std::endl;
            std::cout << "3. Improve Approximation with Simulated Annealing" << std::endl;
        }
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="9") &&
           ((stringChoice == "2" || stringChoice == "3") && !currentTour.isSetted())){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice == "0" || stringChoice == "1" || stringChoice =="9") &&
            ((stringChoice == "2" || stringChoice == "3") && !currentTour.isSetted()));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1: {
            analyst.startTimer();
            OtherHeuristics(graph).nearestNeighbour(currentTour);
            analyst.analyze(currentTour);
            break;
        }
        case 2: {
            analyst.startTimer();
            currentTour = OtherHeuristics(graph).twoOpt(currentTour);
            analyst.analyze(currentTour);
            break;
        }
        case 3: {
            analyst.startTimer();
            currentTour = OtherHeuristics(graph).simulatedAnnealing(currentTour);
            analyst.analyze(currentTour);
            break;
        }
        case 9: {
            state.pop();
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::getMenu(){
    if(!state.empty()){
        State states = state.top();
        switch(states){
            case WELCOME_MENU:
                welcomeMenu();
                break;
            case READ_MENU:
                readMenu();
                break;
            case TOY_MENU:
                toyMenu();
                break;
            case EXTRA_MENU:
                extraMenu();
                break;
            case REAL_MENU:
                realMenu();
                break;
            case FUNC_MENU:
                functionalitiesMenu();
                break;
            case LOWER_BOUND_MENU:
                lowerBoundMenu();
                break;
            case OTHER_HEURISTICS_MENU:
                otherHeuristicsMenu();
                break;
        }
    }
}
