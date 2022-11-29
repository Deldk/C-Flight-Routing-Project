cmake_minimum_required(VERSION 3.22)
project(C___Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(C___Project
        airlines.cpp
        airlines.h
        airports.cpp
        airports.h
        routes.cpp
        routes.h
        main.cpp graph.cpp graph.h vertex.cpp vertex.h edge.cpp edge.h)

