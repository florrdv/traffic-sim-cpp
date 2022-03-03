#ifndef TRAFFICSIM_VEHICLE_H
#define TRAFFICSIM_VEHICLE_H

#include <string>

class Vehicle {
public:
    const std::string &getRoad() const;

    void setRoad(const std::string &road);

    int getPosition() const;

    void setPosition(int position);

private:
    std::string road;
    int position;
};


#endif //TRAFFICSIM_VEHICLE_H
