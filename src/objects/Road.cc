//============================================================================
// Name        : Road.cc
// Author      : Achraf Yandouzi, Flor Ronsmans De Vry
// Description : Road
//============================================================================

#include "Road.h"

const std::string &Road::getName() const {
    return name;
}

void Road::setName(const std::string &n) {
    Road::name = n;
}

int Road::getLength() const {
    return length;
}

void Road::setLength(int l) {
    Road::length = l;
}