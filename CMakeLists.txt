# CMakeList.txt : CMake project for Game, include source and define
cmake_minimum_required (VERSION 3.0.2)

project(Game)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

# Generate shared library
add_subdirectory(GuessNumber/lib)

add_subdirectory(GuessNumber)
add_subdirectory(Blackjack)
add_subdirectory(Monopoly)

#add_subdirectory(SFML_Test)
# After I tried multiple times with multiple version of SFML
# It turned out it doesn't work on this Linux
# I cannot figure out why
# So maybe just move on to others?
# Any suggestions?



