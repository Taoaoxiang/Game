# CMakeList.txt : CMake project for Game, include source and define
cmake_minimum_required (VERSION 3.0.2)

project(Game)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")


add_subdirectory(GuessNumber)
add_subdirectory(Blackjack)
#add_executable (GuessNumber "GuessNumber/main.cpp")



