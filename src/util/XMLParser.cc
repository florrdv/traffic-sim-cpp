#include "XMLParser.h"

void XMLParser::parse() {
    TiXmlDocument doc;
    // open file
    if (!doc.LoadFile("input/example.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return;
    }
    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Could not load XML file: No root element found." << std::endl;
        doc.Clear();
        return;
    }
    for (TiXmlElement *a = doc.FirstChildElement(); a != NULL; a = a->NextSiblingElement()) {
        std::cout << a->Value() << std::endl;
    }

}
