#include "XMLParser.h"

#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("input/example.xml");

    if (!result) throw std::runtime_error("XML: invalid file");

    for (pugi::xml_node tool : doc) {
        std::string name = tool.name();
        if (name == "BAAN") {
            std::cout << "Found road" << std::endl;
        } else if (name == "VERKEERSLICHT") {
            std::cout << "Found traffic light" << std::endl;
        } else if (name == "VOERTUIG") {
            std::cout << "Found vehicle" << std::endl;
        } else {
            throw std::runtime_error("XML: Unknown tag '" + name + "'");
        }
    }

    
}
