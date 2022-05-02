cmake_minimum_required(VERSION 3.6)
project(pse_traffic_sim)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

if(APPLE)
    # Set Apple Silicon library dir
    link_directories(gtest/lib_apple_silicon)
else()
    # Set general library dir (unix)
    link_directories(gtest/lib)
endif()

set(RELEASE_SOURCE_FILES
        src/data/Constants.h
        src/data/Constants.cc

        src/lib/pugixml/pugiconfig.hpp
        src/lib/pugixml/pugixml.cpp
        src/lib/pugixml/pugixml.hpp

        src/lib/json.hpp

        src/lib/NullBuffer.h

        src/lib/DesignByContract.h

        src/objects/Entity.cc
        src/objects/Entity.h

        src/objects/Road.cc
        src/objects/Road.h

        src/objects/TrafficLight.cc
        src/objects/TrafficLight.h

        src/objects/Vehicle.cc
        src/objects/Vehicle.h

        src/objects/VehicleGenerator.cc
        src/objects/VehicleGenerator.h

        src/util/XMLParser.cc
        src/util/XMLParser.h

        src/Simulation.cc
        src/Simulation.h

        src/objects/BusStop.cc
        src/objects/BusStop.h
        
        src/objects/Crossroad.cc
        src/objects/Crossroad.h
        
        src/TrafficSim.cc
)

set(DEBUG_SOURCE_FILES
        src/data/Constants.h
        src/data/Constants.cc

        src/lib/pugixml/pugiconfig.hpp
        src/lib/pugixml/pugixml.cpp
        src/lib/pugixml/pugixml.hpp

        src/lib/json.hpp

        src/lib/NullBuffer.h

        src/lib/TestingHelpers.h
        src/lib/TestingHelpers.cc

        src/lib/DesignByContract.h

        src/objects/Entity.cc
        src/objects/Entity.h
        src/objects/EntityTests.cc

        src/objects/Road.cc
        src/objects/Road.h
        src/objects/RoadTests.cc

        src/objects/TrafficLight.cc
        src/objects/TrafficLight.h
        src/objects/TrafficLightTests.cc

        src/objects/Vehicle.cc
        src/objects/Vehicle.h
        src/objects/VehicleTests.cc

        src/objects/VehicleGenerator.cc
        src/objects/VehicleGenerator.h
        src/objects/VehicleGeneratorTests.cc

        src/util/XMLParser.cc
        src/util/XMLParser.h
        src/util/XMLParserTests.cc

        src/Simulation.cc
        src/Simulation.h
        src/SimulationTests.cc
        
        src/objects/BusStop.cc
        src/objects/BusStop.h
        src/objects/BusStopTests.cc
        
        src/objects/Crossroad.cc
        src/objects/Crossroad.h
        src/objects/CrossroadTests.cc

        src/TrafficSimTests.cc
)

# Create RELEASE target
add_executable(TrafficSim ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(TrafficSimTests ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(TrafficSimTests gtest)
