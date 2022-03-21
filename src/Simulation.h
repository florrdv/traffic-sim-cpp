//TODO: add fancy header thing (like in other files)

// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef TRAFFICSIM_SIMULATION_H
#define TRAFFICSIM_SIMULATION_H

#include "objects/Road.h"

#include <string>
#include <vector>

class Simulation {
private:
    Simulation* _init; //!use pointer to myself to verify whether I am properly initialized

    std::vector<Road*> roads;

    void print(double time);
    void clear();
public:
/**
\n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
*/
    Simulation();;
    //TODO: Destructor preconditions
    ~Simulation();

    // Regular methods
    void addRoad(Road* r);
    Road* findRoad(const std::string& roadName);
    std::vector<Road*> getRoads() const;
    
    int countVehicles();

    void writeOn(std::ostream& onStream);

    void printForVisualizer();

    // Safety specific
    bool properlyInitialized() { return _init == this; }

};

// Closing of the ``header guard''.
#endif
