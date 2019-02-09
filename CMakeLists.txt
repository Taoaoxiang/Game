# CMakeList.txt : CMake project for Game, include source and define
cmake_minimum_required (VERSION 3.0.2)

project(game)
set(CMAKE_BUILD_TYPE Release)

# Output bin
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create shared library
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES} )

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/lib/)


# Add source to this project's executable.
#add_subdirectory(GuessNumber)
add_executable (GuessNumber "GuessNumber/main.cpp")
target_link_libraries(GuessNumber ${CMAKE_SOURCE_DIR}/lib/libgame.so)


