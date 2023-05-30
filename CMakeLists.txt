cmake_minimum_required(VERSION 3.25)
project(PROJ2_DA_2022_2023)

set(CMAKE_CXX_STANDARD 14)

include_directories(application)
include_directories(classes/file-reader)
include_directories(data-structure)

add_executable(PROJ2_DA_2022_2023
        application/Application.cpp
        application/Application.h
        classes/file-reader/FileReader.cpp
        classes/file-reader/FileReader.h
        data-structure/Graph.cpp
        data-structure/Graph.h
        data-structure/MutablePriorityQueue.h
        data-structure/VertexEdge.cpp
        data-structure/VertexEdge.h
        main.cpp data-structure/Coordinates.cpp data-structure/Coordinates.h classes/timer/Timer.cpp classes/timer/Timer.h functionalities/OtherHeuristics.cpp functionalities/OtherHeuristics.h)
