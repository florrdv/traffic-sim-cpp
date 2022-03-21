/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: simulation entrypoint
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:43:06 pm
 */

#include <iostream>
#include "util/XMLParser.h"
#include "Simulation.h"

// put this on false if you want to use the CLI visualizer, put on true for pygame visualizer
bool VISUALIZE = false;
// In order to use the pygame visualizer, make sure you execute the following command from cmake-build-debug:
// $ ./TrafficSim | python3 ../src/pse-traffic-simulation-visualizer/visualize.py

int main() {
    if (!VISUALIZE) std::cout << "Hello, simulation!" << std::endl;

    Simulation sim = Simulation();

    XMLParser parser;
    parser.parse(sim, "../input/example.xml");

    if (!VISUALIZE) std::cout << "Parsing succesful!" << std::endl;

    if (!VISUALIZE) sim.writeOn(std::cout);

    if (VISUALIZE) sim.printForVisualizer();
    return 0;
}
