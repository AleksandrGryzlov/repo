cmake_minimum_required(VERSION 3.4)

#set the project name
project(BoostGraphDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executable

find_package(Boost 1.40 COMPONENTS graph REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(adjlist source/adjlist.cpp)
target_link_libraries(adjlist Boost::graph)

add_executable(adjvertex source/adjvertex.cpp)
target_link_libraries(adjvertex Boost::graph)

add_executable(initialize source/initialize.cpp)
target_link_libraries(initialize Boost::graph)

add_executable(othertype source/othertype.cpp)
target_link_libraries(othertype Boost::graph)

add_executable(undirected source/undirected.cpp)
target_link_libraries(undirected Boost::graph)

add_executable(visitor source/visitor.cpp)
target_link_libraries(visitor Boost::graph)

add_executable(weighted source/weighted.cpp)
target_link_libraries(weighted Boost::graph)

add_executable(adjmatrix source/adjmatrix.cpp)
target_link_libraries(adjmatrix Boost::graph)
