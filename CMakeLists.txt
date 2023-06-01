cmake_minimum_required(VERSION 3.24)
project(PROJ2_DA_2022_2023)

set(CMAKE_CXX_STANDARD 14)

include_directories(application)
include_directories(classes/file-reader)
include_directories(classes/backtraking)
include_directories(classes/heuristic)
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
        main.cpp
        data-structure/Coordinates.cpp
        data-structure/Coordinates.h
        classes/timer/Timer.cpp
        classes/timer/Timer.h
        classes/otherHeuristics/OtherHeuristics.cpp
        classes/otherHeuristics/OtherHeuristics.h
        classes/backtraking/Backtracking.cpp
        classes/backtraking/Backtracking.h
        classes/heuristic/Heuristic.cpp
        classes/heuristic/Heuristic.h
        classes/tour/Tour.cpp
        classes/tour/Tour.h
        classes/analyst/Analyst.cpp
        classes/analyst/Analyst.h)
