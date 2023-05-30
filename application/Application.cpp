/** @file Application.cpp
 *  @brief Contains the Application Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"

void Application::start() {

//    fileReader.read(TOY_GRAPH, "shipping.csv", graph);
    timer.start();
    fileReader.read(TOY_GRAPH, "stadiums.csv", graph);

//    std::cout << "Time to read the graph: " << timer.stop() << " ms" << std::endl;


    for (Vertex* vertex: graph->getVertexSet()){
        std::cout << "Id: " << vertex->getId() << std::endl;
    }

    std::cout << "Time to read the graph: " << timer.stop() << " ms" << std::endl;

//    fileReader.read(EXTRA_GRAPH, "edges_900.csv", graph);
    std::cout << "---------------------------------------------------------------" << std::endl;
    backtraking = Backtraking(graph);
    auto res = backtraking.tspBacktraking();
    std::cout << res.first << std::endl;
    //std::cout << res.first << std::endl;
//    state.push(WELCOME_MENU);
//    getMenu();
}

/*void Application::welcomeMenu(){

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
            state.push(SERVICES_MENU);
            break;
        case 2:
            state.push(COST_MENU);
            break;
        case 3: {
            state.push(FAILURE_MENU);
            break;
        }
        case 9: {
            state.push(READ_MENU);
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::readFileMenu(){
    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "    Analysis Tool for Railway Network Management" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "1. Read Toy Graphs" << std::endl;
        std::cout << "2. Read Real Word Graphs" << std::endl;
        std::cout << "3. Read Extra Fully Connected Graphs" << std::endl;
        std::cout << "0. Quit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" ||stringChoice=="0")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice=="1" ||stringChoice=="2" || stringChoice=="3" ||stringChoice=="0"));
}

void Application::initialMenu(){
    do{
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "    Analysis Tool for Railway Network Management" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "1. Basic Service Metrics" << std::endl;
        std::cout << "2. Operation Cost Optimization" << std::endl;
        std::cout << "3. Reliability and Sensitivity to Line Failures" << std::endl;
        std::cout << "9. Go back" << std::endl;
        std::cout << "0. Quit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" || stringChoice=="9" ||stringChoice=="0")){
            std::cout << "Invalid option number!";
        }
    }
    while(!(stringChoice=="1" ||stringChoice=="2" ||stringChoice=="3" || stringChoice=="9" ||stringChoice=="0"));

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1:
            state.push(SERVICES_MENU);
            break;
        case 2:
            state.push(COST_MENU);
            break;
        case 3: {
            state.push(FAILURE_MENU);
            break;
        }
        case 9: {
            state.push(READ_MENU);
            break;
        }
        case 0:
            exit(0);
    }
    getMenu();
}

void Application::servicesMenu(){
    do{
       std::cout << std::endl << std::endl << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "              Basic Services Metrics" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "1. Maximum number of trains between two specific stations" << std::endl;
        std::cout << "2. Pairs of stations that require the most amount of trains" << std::endl;
        std::cout << "3. Top-k municipalities" << std::endl;
        std::cout << "4. Top-k districts" << std::endl;
        std::cout << "5. Maximum number of trains that arrive at a given station" << std::endl;
        std::cout << "9. Go Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> stringChoice;
        std::cin.ignore(1000,'\n');

        if(stringChoice < "0" || stringChoice == "6" || stringChoice =="7" || stringChoice == "8" || stringChoice >"9"){
            std::cout << "Invalid option number!";
        }
    }
    while(stringChoice < "0" || stringChoice == "6" || stringChoice =="7" || stringChoice == "8" || stringChoice >"9");

    choice = std::stoi(stringChoice);

    switch(choice){
        case 1: {
            std::string source;
            std::string target;

            std::cout << "Name of the source station: ";
            getline(std::cin, source);
            std::cout << "Name of the target station: ";
            getline(std::cin, target);

            auto sourceID = stations[source];
            auto targetID = stations[target];
            if(sourceID== nullptr || targetID== nullptr){
                std::cout<< "Invalid station names!";
                break;
            }
            double maxFlow = basicServices.maxFlow(sourceID->getId(), targetID->getId());
            if(maxFlow == -1){
                std::cout << "Inaccessible stations!";
            }
            else{
                std::cout << "The maximum amount of trains: " << maxFlow;
            }

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
        States states = state.top();
        switch(states){
            case WELCOME_MENU:
                welcomeMenu();
                break;
            case READ_MENU:
                readMenu();
                break;
            case READ_FILE_MENU:
                readFileMenu();
                break;
            case INITIAL_MENU:
                initialMenu();
                break;
        }
    }
}
*/