#include "XMLParser.h"

void XMLParser::parse() {
    TiXmlDocument doc;
    // open file
    if (!doc.LoadFile("test.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return;
    }
    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Could not load XML file: No root element found." << std::endl;
        doc.Clear();
        return;
    }
    

}
