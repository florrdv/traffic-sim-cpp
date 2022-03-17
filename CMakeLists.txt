cmake_minimum_required(VERSION 3.6)
project(pse_traffic_sim)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

set(RELEASE_SOURCE_FILES
        src/data/Constants.cc
        src/lib/pugixml/pugiconfig.hpp
        src/lib/pugixml/pugixml.cpp
        src/lib/pugixml/pugixml.hpp
        src/lib/DesignByContract.h
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
        src/Simulation.cpp
        src/Simulation.h
        src/TrafficSim.cc)

set(DEBUG_SOURCE_FILES
        gtest/include/gtest/internal/gtest-death-test-internal.h
        gtest/include/gtest/internal/gtest-filepath.h
        gtest/include/gtest/internal/gtest-internal.h
        gtest/include/gtest/internal/gtest-linked_ptr.h
        gtest/include/gtest/internal/gtest-param-util-generated.h
        gtest/include/gtest/internal/gtest-param-util.h
        gtest/include/gtest/internal/gtest-port.h
        gtest/include/gtest/internal/gtest-string.h
        gtest/include/gtest/internal/gtest-tuple.h
        gtest/include/gtest/internal/gtest-type-util.h
        gtest/include/gtest/gtest-death-test.h
        gtest/include/gtest/gtest-message.h
        gtest/include/gtest/gtest-param-test.h
        gtest/include/gtest/gtest-printers.h
        gtest/include/gtest/gtest-spi.h
        gtest/include/gtest/gtest-test-part.h
        gtest/include/gtest/gtest-typed-test.h
        gtest/include/gtest/gtest.h
        gtest/include/gtest/gtest_pred_impl.h
        gtest/include/gtest/gtest_prod.h
        src/data/Constants.cc
        src/lib/pugixml/pugiconfig.hpp
        src/lib/pugixml/pugixml.cpp
        src/lib/pugixml/pugixml.hpp
        src/lib/DesignByContract.h
        src/objects/Road.cc
        src/objects/Road.h
        src/objects/RoadTests.cc
        src/objects/TrafficLight.cc
        src/objects/TrafficLight.h
        src/objects/TrafficLightTests.cc
        src/objects/Vehicle.cc
        src/objects/Vehicle.h
        src/objects/VehicleGenerator.cc
        src/objects/VehicleGenerator.h
        src/objects/VehicleTests.cc
        src/util/XMLParser.cc
        src/util/XMLParser.h
        src/util/XMLParserTests.cc
        src/Simulation.cpp
        src/Simulation.h
        src/SimulationTests.cc
        src/TrafficSim.cc
        src/TrafficSimTests.cc)

# Create RELEASE target
add_executable(TrafficSim ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(TrafficSimTests ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(TrafficSimTests gtest)