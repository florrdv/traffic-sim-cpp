#ifndef TRAFFICSIM_TRAFFICLIGHT_H
#define TRAFFICSIM_TRAFFICLIGHT_H

#include <string>

class TrafficLight {
public:
    const std::string &getRoad() const;

    int getPosition() const;

    void setPosition(int position);

    int getCycles() const;

    void setCycles(int cycles);

private:
    int position;
    int cycles;
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
