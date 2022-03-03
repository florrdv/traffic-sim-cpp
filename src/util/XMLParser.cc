#include "XMLParser.h"

#include "../lib/pugixml/pugixml.hpp"

void XMLParser::parse() {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file("input/example.xml");

  if (!result) throw "Bro";

  for (pugi::xml_node tool : doc) {
    std::cout << tool.name() << std::endl;
  }
}
