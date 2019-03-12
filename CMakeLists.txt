# CMakeList.txt : CMake project for Game, include source and define
cmake_minimum_required (VERSION 3.0.2)

project(Game)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

# Generate shared library
add_subdirectory(GuessNumber/lib)

add_subdirectory(GuessNumber)
add_subdirectory(Blackjack)
add_subdirectory(Monopoly)




