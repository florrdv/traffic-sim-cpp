#include "XMLParser.h"

void XMLParser::parse() {
    TiXmlDocument doc;
    // open file
    if (!doc.LoadFile("test.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return;
    }
}
