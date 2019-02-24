# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0.2)

project(BlackjackLib)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

SET(INCLUDE_DIR ${Game_SOURCE_DIR}/Blackjack/include)
SET(SOURCE_DIR ${Game_SOURCE_DIR}/Blackjack/src)

# Include header files
include_directories(${INCLUDE_DIR})
file(GLOB ALLCPP *.cpp)
add_library(BlackjackLib ${ALLCPP})


# TODO: Add tests and install targets if needed.
