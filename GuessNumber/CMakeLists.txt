# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0.2)

project(GuessNumber)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

# Set bin, include, source folders
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Game_SOURCE_DIR}/GuessNumber/bin)
#SET(INCLUDE_DIR ${Game_SOURCE_DIR}/GuessNumber/include)
SET(SOURCE_DIR ${Game_SOURCE_DIR}/GuessNumber/src)

# Include header files
#include_directories(${INCLUDE_DIR})

# Create shared library
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
#add_library(${PROJECT_NAME} SHARED ${SOURCES} )

# Add source to this project's executable.
#add_executable (GuessNumber ${source}"main.cpp" "GuessNumber.cpp")
add_executable (GuessNumber "main.cpp" ${SOURCES})

# TODO: Add tests and install targets if needed.
