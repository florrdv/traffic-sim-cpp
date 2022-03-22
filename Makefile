# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/achraf/CLionProjects/pse-traffic-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/achraf/CLionProjects/pse-traffic-sim

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/clion-2021.2.3/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/opt/clion-2021.2.3/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/achraf/CLionProjects/pse-traffic-sim/CMakeFiles /home/achraf/CLionProjects/pse-traffic-sim//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/achraf/CLionProjects/pse-traffic-sim/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named TrafficSimTests

# Build rule for target.
TrafficSimTests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TrafficSimTests
.PHONY : TrafficSimTests

# fast build rule for target.
TrafficSimTests/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/build
.PHONY : TrafficSimTests/fast

#=============================================================================
# Target rules for targets named TrafficSim

# Build rule for target.
TrafficSim: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TrafficSim
.PHONY : TrafficSim

# fast build rule for target.
TrafficSim/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/build
.PHONY : TrafficSim/fast

src/Simulation.o: src/Simulation.cpp.o
.PHONY : src/Simulation.o

# target to build an object file
src/Simulation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/Simulation.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/Simulation.cpp.o
.PHONY : src/Simulation.cpp.o

src/Simulation.i: src/Simulation.cpp.i
.PHONY : src/Simulation.i

# target to preprocess a source file
src/Simulation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/Simulation.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/Simulation.cpp.i
.PHONY : src/Simulation.cpp.i

src/Simulation.s: src/Simulation.cpp.s
.PHONY : src/Simulation.s

# target to generate assembly for a file
src/Simulation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/Simulation.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/Simulation.cpp.s
.PHONY : src/Simulation.cpp.s

src/SimulationTests.o: src/SimulationTests.cc.o
.PHONY : src/SimulationTests.o

# target to build an object file
src/SimulationTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/SimulationTests.cc.o
.PHONY : src/SimulationTests.cc.o

src/SimulationTests.i: src/SimulationTests.cc.i
.PHONY : src/SimulationTests.i

# target to preprocess a source file
src/SimulationTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/SimulationTests.cc.i
.PHONY : src/SimulationTests.cc.i

src/SimulationTests.s: src/SimulationTests.cc.s
.PHONY : src/SimulationTests.s

# target to generate assembly for a file
src/SimulationTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/SimulationTests.cc.s
.PHONY : src/SimulationTests.cc.s

src/TrafficSim.o: src/TrafficSim.cc.o
.PHONY : src/TrafficSim.o

# target to build an object file
src/TrafficSim.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o
.PHONY : src/TrafficSim.cc.o

src/TrafficSim.i: src/TrafficSim.cc.i
.PHONY : src/TrafficSim.i

# target to preprocess a source file
src/TrafficSim.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.i
.PHONY : src/TrafficSim.cc.i

src/TrafficSim.s: src/TrafficSim.cc.s
.PHONY : src/TrafficSim.s

# target to generate assembly for a file
src/TrafficSim.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.s
.PHONY : src/TrafficSim.cc.s

src/TrafficSimTests.o: src/TrafficSimTests.cc.o
.PHONY : src/TrafficSimTests.o

# target to build an object file
src/TrafficSimTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/TrafficSimTests.cc.o
.PHONY : src/TrafficSimTests.cc.o

src/TrafficSimTests.i: src/TrafficSimTests.cc.i
.PHONY : src/TrafficSimTests.i

# target to preprocess a source file
src/TrafficSimTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/TrafficSimTests.cc.i
.PHONY : src/TrafficSimTests.cc.i

src/TrafficSimTests.s: src/TrafficSimTests.cc.s
.PHONY : src/TrafficSimTests.s

# target to generate assembly for a file
src/TrafficSimTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/TrafficSimTests.cc.s
.PHONY : src/TrafficSimTests.cc.s

src/data/Constants.o: src/data/Constants.cc.o
.PHONY : src/data/Constants.o

# target to build an object file
src/data/Constants.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/data/Constants.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/data/Constants.cc.o
.PHONY : src/data/Constants.cc.o

src/data/Constants.i: src/data/Constants.cc.i
.PHONY : src/data/Constants.i

# target to preprocess a source file
src/data/Constants.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/data/Constants.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/data/Constants.cc.i
.PHONY : src/data/Constants.cc.i

src/data/Constants.s: src/data/Constants.cc.s
.PHONY : src/data/Constants.s

# target to generate assembly for a file
src/data/Constants.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/data/Constants.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/data/Constants.cc.s
.PHONY : src/data/Constants.cc.s

src/lib/TestingHelpers.o: src/lib/TestingHelpers.cc.o
.PHONY : src/lib/TestingHelpers.o

# target to build an object file
src/lib/TestingHelpers.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/TestingHelpers.cc.o
.PHONY : src/lib/TestingHelpers.cc.o

src/lib/TestingHelpers.i: src/lib/TestingHelpers.cc.i
.PHONY : src/lib/TestingHelpers.i

# target to preprocess a source file
src/lib/TestingHelpers.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/TestingHelpers.cc.i
.PHONY : src/lib/TestingHelpers.cc.i

src/lib/TestingHelpers.s: src/lib/TestingHelpers.cc.s
.PHONY : src/lib/TestingHelpers.s

# target to generate assembly for a file
src/lib/TestingHelpers.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/TestingHelpers.cc.s
.PHONY : src/lib/TestingHelpers.cc.s

src/lib/pugixml/pugixml.o: src/lib/pugixml/pugixml.cpp.o
.PHONY : src/lib/pugixml/pugixml.o

# target to build an object file
src/lib/pugixml/pugixml.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/pugixml/pugixml.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/lib/pugixml/pugixml.cpp.o
.PHONY : src/lib/pugixml/pugixml.cpp.o

src/lib/pugixml/pugixml.i: src/lib/pugixml/pugixml.cpp.i
.PHONY : src/lib/pugixml/pugixml.i

# target to preprocess a source file
src/lib/pugixml/pugixml.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/pugixml/pugixml.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/lib/pugixml/pugixml.cpp.i
.PHONY : src/lib/pugixml/pugixml.cpp.i

src/lib/pugixml/pugixml.s: src/lib/pugixml/pugixml.cpp.s
.PHONY : src/lib/pugixml/pugixml.s

# target to generate assembly for a file
src/lib/pugixml/pugixml.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/lib/pugixml/pugixml.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/lib/pugixml/pugixml.cpp.s
.PHONY : src/lib/pugixml/pugixml.cpp.s

src/objects/Road.o: src/objects/Road.cc.o
.PHONY : src/objects/Road.o

# target to build an object file
src/objects/Road.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Road.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Road.cc.o
.PHONY : src/objects/Road.cc.o

src/objects/Road.i: src/objects/Road.cc.i
.PHONY : src/objects/Road.i

# target to preprocess a source file
src/objects/Road.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Road.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Road.cc.i
.PHONY : src/objects/Road.cc.i

src/objects/Road.s: src/objects/Road.cc.s
.PHONY : src/objects/Road.s

# target to generate assembly for a file
src/objects/Road.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Road.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Road.cc.s
.PHONY : src/objects/Road.cc.s

src/objects/RoadTests.o: src/objects/RoadTests.cc.o
.PHONY : src/objects/RoadTests.o

# target to build an object file
src/objects/RoadTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/RoadTests.cc.o
.PHONY : src/objects/RoadTests.cc.o

src/objects/RoadTests.i: src/objects/RoadTests.cc.i
.PHONY : src/objects/RoadTests.i

# target to preprocess a source file
src/objects/RoadTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/RoadTests.cc.i
.PHONY : src/objects/RoadTests.cc.i

src/objects/RoadTests.s: src/objects/RoadTests.cc.s
.PHONY : src/objects/RoadTests.s

# target to generate assembly for a file
src/objects/RoadTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/RoadTests.cc.s
.PHONY : src/objects/RoadTests.cc.s

src/objects/TrafficLight.o: src/objects/TrafficLight.cc.o
.PHONY : src/objects/TrafficLight.o

# target to build an object file
src/objects/TrafficLight.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLight.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/TrafficLight.cc.o
.PHONY : src/objects/TrafficLight.cc.o

src/objects/TrafficLight.i: src/objects/TrafficLight.cc.i
.PHONY : src/objects/TrafficLight.i

# target to preprocess a source file
src/objects/TrafficLight.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLight.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/TrafficLight.cc.i
.PHONY : src/objects/TrafficLight.cc.i

src/objects/TrafficLight.s: src/objects/TrafficLight.cc.s
.PHONY : src/objects/TrafficLight.s

# target to generate assembly for a file
src/objects/TrafficLight.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLight.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/TrafficLight.cc.s
.PHONY : src/objects/TrafficLight.cc.s

src/objects/TrafficLightTests.o: src/objects/TrafficLightTests.cc.o
.PHONY : src/objects/TrafficLightTests.o

# target to build an object file
src/objects/TrafficLightTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLightTests.cc.o
.PHONY : src/objects/TrafficLightTests.cc.o

src/objects/TrafficLightTests.i: src/objects/TrafficLightTests.cc.i
.PHONY : src/objects/TrafficLightTests.i

# target to preprocess a source file
src/objects/TrafficLightTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLightTests.cc.i
.PHONY : src/objects/TrafficLightTests.cc.i

src/objects/TrafficLightTests.s: src/objects/TrafficLightTests.cc.s
.PHONY : src/objects/TrafficLightTests.s

# target to generate assembly for a file
src/objects/TrafficLightTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/TrafficLightTests.cc.s
.PHONY : src/objects/TrafficLightTests.cc.s

src/objects/Vehicle.o: src/objects/Vehicle.cc.o
.PHONY : src/objects/Vehicle.o

# target to build an object file
src/objects/Vehicle.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Vehicle.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Vehicle.cc.o
.PHONY : src/objects/Vehicle.cc.o

src/objects/Vehicle.i: src/objects/Vehicle.cc.i
.PHONY : src/objects/Vehicle.i

# target to preprocess a source file
src/objects/Vehicle.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Vehicle.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Vehicle.cc.i
.PHONY : src/objects/Vehicle.cc.i

src/objects/Vehicle.s: src/objects/Vehicle.cc.s
.PHONY : src/objects/Vehicle.s

# target to generate assembly for a file
src/objects/Vehicle.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/Vehicle.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/Vehicle.cc.s
.PHONY : src/objects/Vehicle.cc.s

src/objects/VehicleGenerator.o: src/objects/VehicleGenerator.cc.o
.PHONY : src/objects/VehicleGenerator.o

# target to build an object file
src/objects/VehicleGenerator.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGenerator.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/VehicleGenerator.cc.o
.PHONY : src/objects/VehicleGenerator.cc.o

src/objects/VehicleGenerator.i: src/objects/VehicleGenerator.cc.i
.PHONY : src/objects/VehicleGenerator.i

# target to preprocess a source file
src/objects/VehicleGenerator.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGenerator.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/VehicleGenerator.cc.i
.PHONY : src/objects/VehicleGenerator.cc.i

src/objects/VehicleGenerator.s: src/objects/VehicleGenerator.cc.s
.PHONY : src/objects/VehicleGenerator.s

# target to generate assembly for a file
src/objects/VehicleGenerator.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGenerator.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/objects/VehicleGenerator.cc.s
.PHONY : src/objects/VehicleGenerator.cc.s

src/objects/VehicleGeneratorTests.o: src/objects/VehicleGeneratorTests.cc.o
.PHONY : src/objects/VehicleGeneratorTests.o

# target to build an object file
src/objects/VehicleGeneratorTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGeneratorTests.cc.o
.PHONY : src/objects/VehicleGeneratorTests.cc.o

src/objects/VehicleGeneratorTests.i: src/objects/VehicleGeneratorTests.cc.i
.PHONY : src/objects/VehicleGeneratorTests.i

# target to preprocess a source file
src/objects/VehicleGeneratorTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGeneratorTests.cc.i
.PHONY : src/objects/VehicleGeneratorTests.cc.i

src/objects/VehicleGeneratorTests.s: src/objects/VehicleGeneratorTests.cc.s
.PHONY : src/objects/VehicleGeneratorTests.s

# target to generate assembly for a file
src/objects/VehicleGeneratorTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleGeneratorTests.cc.s
.PHONY : src/objects/VehicleGeneratorTests.cc.s

src/objects/VehicleTests.o: src/objects/VehicleTests.cc.o
.PHONY : src/objects/VehicleTests.o

# target to build an object file
src/objects/VehicleTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleTests.cc.o
.PHONY : src/objects/VehicleTests.cc.o

src/objects/VehicleTests.i: src/objects/VehicleTests.cc.i
.PHONY : src/objects/VehicleTests.i

# target to preprocess a source file
src/objects/VehicleTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleTests.cc.i
.PHONY : src/objects/VehicleTests.cc.i

src/objects/VehicleTests.s: src/objects/VehicleTests.cc.s
.PHONY : src/objects/VehicleTests.s

# target to generate assembly for a file
src/objects/VehicleTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/objects/VehicleTests.cc.s
.PHONY : src/objects/VehicleTests.cc.s

src/util/XMLParser.o: src/util/XMLParser.cc.o
.PHONY : src/util/XMLParser.o

# target to build an object file
src/util/XMLParser.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParser.cc.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o
.PHONY : src/util/XMLParser.cc.o

src/util/XMLParser.i: src/util/XMLParser.cc.i
.PHONY : src/util/XMLParser.i

# target to preprocess a source file
src/util/XMLParser.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParser.cc.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.i
.PHONY : src/util/XMLParser.cc.i

src/util/XMLParser.s: src/util/XMLParser.cc.s
.PHONY : src/util/XMLParser.s

# target to generate assembly for a file
src/util/XMLParser.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParser.cc.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSim.dir/build.make CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.s
.PHONY : src/util/XMLParser.cc.s

src/util/XMLParserTests.o: src/util/XMLParserTests.cc.o
.PHONY : src/util/XMLParserTests.o

# target to build an object file
src/util/XMLParserTests.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParserTests.cc.o
.PHONY : src/util/XMLParserTests.cc.o

src/util/XMLParserTests.i: src/util/XMLParserTests.cc.i
.PHONY : src/util/XMLParserTests.i

# target to preprocess a source file
src/util/XMLParserTests.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParserTests.cc.i
.PHONY : src/util/XMLParserTests.cc.i

src/util/XMLParserTests.s: src/util/XMLParserTests.cc.s
.PHONY : src/util/XMLParserTests.s

# target to generate assembly for a file
src/util/XMLParserTests.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TrafficSimTests.dir/build.make CMakeFiles/TrafficSimTests.dir/src/util/XMLParserTests.cc.s
.PHONY : src/util/XMLParserTests.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... TrafficSim"
	@echo "... TrafficSimTests"
	@echo "... src/Simulation.o"
	@echo "... src/Simulation.i"
	@echo "... src/Simulation.s"
	@echo "... src/SimulationTests.o"
	@echo "... src/SimulationTests.i"
	@echo "... src/SimulationTests.s"
	@echo "... src/TrafficSim.o"
	@echo "... src/TrafficSim.i"
	@echo "... src/TrafficSim.s"
	@echo "... src/TrafficSimTests.o"
	@echo "... src/TrafficSimTests.i"
	@echo "... src/TrafficSimTests.s"
	@echo "... src/data/Constants.o"
	@echo "... src/data/Constants.i"
	@echo "... src/data/Constants.s"
	@echo "... src/lib/TestingHelpers.o"
	@echo "... src/lib/TestingHelpers.i"
	@echo "... src/lib/TestingHelpers.s"
	@echo "... src/lib/pugixml/pugixml.o"
	@echo "... src/lib/pugixml/pugixml.i"
	@echo "... src/lib/pugixml/pugixml.s"
	@echo "... src/objects/Road.o"
	@echo "... src/objects/Road.i"
	@echo "... src/objects/Road.s"
	@echo "... src/objects/RoadTests.o"
	@echo "... src/objects/RoadTests.i"
	@echo "... src/objects/RoadTests.s"
	@echo "... src/objects/TrafficLight.o"
	@echo "... src/objects/TrafficLight.i"
	@echo "... src/objects/TrafficLight.s"
	@echo "... src/objects/TrafficLightTests.o"
	@echo "... src/objects/TrafficLightTests.i"
	@echo "... src/objects/TrafficLightTests.s"
	@echo "... src/objects/Vehicle.o"
	@echo "... src/objects/Vehicle.i"
	@echo "... src/objects/Vehicle.s"
	@echo "... src/objects/VehicleGenerator.o"
	@echo "... src/objects/VehicleGenerator.i"
	@echo "... src/objects/VehicleGenerator.s"
	@echo "... src/objects/VehicleGeneratorTests.o"
	@echo "... src/objects/VehicleGeneratorTests.i"
	@echo "... src/objects/VehicleGeneratorTests.s"
	@echo "... src/objects/VehicleTests.o"
	@echo "... src/objects/VehicleTests.i"
	@echo "... src/objects/VehicleTests.s"
	@echo "... src/util/XMLParser.o"
	@echo "... src/util/XMLParser.i"
	@echo "... src/util/XMLParser.s"
	@echo "... src/util/XMLParserTests.o"
	@echo "... src/util/XMLParserTests.i"
	@echo "... src/util/XMLParserTests.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

