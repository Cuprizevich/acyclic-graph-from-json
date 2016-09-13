cmake_minimum_required(VERSION 3.6)
project(acyclic_graph_from_json)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp node.h)
add_executable(acyclic_graph_from_json ${SOURCE_FILES})