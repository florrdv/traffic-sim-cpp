cmake_minimum_required(VERSION 3.6)
project(TrafficSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c++98")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set src dir
set(CMAKE_SOURCE_DIR src)

# Set include dir
include_directories(lib/gtest/include)

# Set Library dir
link_directories(lib/gtest/lib)

# Set source files for RELEASE target
set(FILES src/util/XMLParser.cc src/util/XMLParser.h src/lib/TinyXML/tinystr.cpp src/lib/TinyXML/tinystr.h src/lib/TinyXML/tinyxml.cpp src/lib/TinyXML/tinyxml.h src/lib/TinyXML/tinyxmlerror.cpp src/lib/TinyXML/tinyxmlparser.cpp src/objects/Vehicle.h src/objects/Vehicle.cc src/objects/Road.h src/objects/Road.cc src/objects/TrafficLight.h src/objects/TrafficLight.cc)
set(RELEASE_SOURCE_FILES src/TrafficSim.cc ${FILES})

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES src/TrafficSimTests.cc ${FILES})

# Create RELEASE target
add_executable(TrafficSim ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(TrafficSimTests ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(TrafficSimTests gtest)
