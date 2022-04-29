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
#include <fstream>
#include "util/XMLParser.h"
#include "Simulation.h"

int main() {

    XMLParser parser;
    Simulation sim1 = Simulation();
    Simulation sim2 = Simulation();

    parser.parse(sim1, "../input/testing/ValidSimulationTest10.xml");
    parser.parse(sim2, "../input/testing/ValidSimulationTest10.xml");

    // sim1.writeOn(std::cout, 50);

    std::ofstream f("out.json");
    sim2.writeToFile(f, 50);
    f.close();

    return 0;
}
