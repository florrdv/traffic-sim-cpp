//============================================================================
// Name        : XMLParser.cc
// Author      : Achraf Yandouzi, Flor Ronsmans De Vry
// Description : XML Parser
//============================================================================

#include "../Simulation.h"

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_

/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:17:49 pm
 */


#include <iostream>
#include <string>

class XMLParser {
public:
    void parse(Simulation& sim);
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_