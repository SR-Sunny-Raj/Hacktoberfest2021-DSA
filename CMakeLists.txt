cmake_minimum_required(VERSION 3.14)
project(STL)

set(CMAKE_CXX_STANDARD 14)

add_executable(tree_diameter_1 graphs/tree_diameter_1.cpp)
add_executable(kruskals_algo graphs/kruskals_algo.cpp)
add_executable(prims_algo graphs/prims_algo.cpp)

add_executable(CHFM "July Challenge/CHFM.cpp")
add_executable(MMAX "July Challenge/MMAX.cpp")
add_executable(PRTAGN "July Challenge/PRTAGN.cpp")
add_executable(CIRMERGE "July Challenge/CIRMERGE.cpp")
add_executable(A2 "codeforces/helvetic contest/A2.cpp")