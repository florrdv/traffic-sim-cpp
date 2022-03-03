#include "XMLParser.h"
#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("xgconsole.xml");

}
