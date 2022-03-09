/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: XML parser
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Thursday, 3rd March 2022 3:17:49 pm
 */

#include "../Simulation.h"

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_


#include <iostream>
#include <string>
#include "../lib/pugixml/pugixml.hpp"

class XMLParser {
    XMLParser* _init;
    
    void validateNode(const pugi::xml_node& node, const std::string nam) const;
    int parsePositiveInteger(const std::string& s, const std::string name) const;
public:
    // Constructors / destructors
    XMLParser() { _init = this; };

    // Regular methods
    void parse(Simulation& sim);

    // Safety specific
    const bool properlyInitialized() const { return _init == this; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_UTIL_XMLPARSER_H_