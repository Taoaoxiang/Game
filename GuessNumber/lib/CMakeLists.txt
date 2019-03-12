# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0.2)

project(GuessNumberLib)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

# Set bin, include, source folders
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Game_SOURCE_DIR}/GuessNumber/lib)
SET(INCLUDE_DIR ${Game_SOURCE_DIR}/GuessNumber/include)
SET(SOURCE_DIR ${Game_SOURCE_DIR}/GuessNumber/src)

# Include header files
include_directories(${INCLUDE_DIR})

# Create shared library
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
#link_directories(${SOURCE_DIR})
add_library(${PROJECT_NAME} SHARED ${SOURCES} )

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

# Add source to this project's executable.
#add_executable (GuessNumber "main.cpp" ${SOURCES})

# TODO: Add tests and install targets if needed.
