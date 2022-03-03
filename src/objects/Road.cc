#include "Road.h"

const std::string &Road::getName() const {
    return name;
}

void Road::setName(const std::string &name) {
    Road::name = name;
}

int Road::getLength() const {
    return length;
}

void Road::setLength(int length) {
    Road::length = length;
}