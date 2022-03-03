#ifndef TRAFFICSIM_TRAFFICLIGHT_H
#define TRAFFICSIM_TRAFFICLIGHT_H

#include <string>

class TrafficLight {
public:
    const std::string &getRoad() const;

    void setRoad(const std::string &road);

    int getPosition() const;

    void setPosition(int position);

    int getCycles() const;

    void setCycles(int cycles);

private:
    std::string road;
    int position;
    int cycles;
};


#endif //TRAFFICSIM_TRAFFICLIGHT_H
