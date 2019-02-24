# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0.2)

project(Blackjack)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

# Set bin, include, source folders
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Game_SOURCE_DIR}/Blackjack/bin)
SET(INCLUDE_DIR ${Game_SOURCE_DIR}/Blackjack/include)
SET(SOURCE_DIR ${Game_SOURCE_DIR}/Blackjack/src)

# Include header files
include_directories(${INCLUDE_DIR})

# Source files
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
# Create shared library
#add_library(${PROJECT_NAME} SHARED ${SOURCES} )
# Install library
#install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/lib/)

# Add source to this project's executable.
add_executable (Blackjack "Blackjack.cpp" ${SOURCES})
#target_link_libraries(GuessNumber ${CMAKE_SOURCE_DIR}/lib/*.so)

# TODO: Add tests and install targets if needed.
