/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description:
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Tuesday, 1st March 2022 1:54:22 pm
 */


#include "Simulation.h"
#include "data/Constants.h"
#include "lib/DesignByContract.h"
#include "lib/json.hpp"
#include "lib/NullBuffer.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>


Simulation::Simulation() {
    _init = this;
    ENSURE(this->properlyInitialized(), "constructor must end in properlyInitialized state");
}

Simulation::~Simulation() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling destructor");
    for (Road* road : roads) delete road;
}

std::vector<Road*> Simulation::getRoads() const {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling writeOn");
    return roads;
}

void Simulation::addRoad(Road* r) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling addRoad");
    roads.push_back(r);
    ENSURE(find(roads.begin(), roads.end(), r) != roads.end(), "Road wasn't added to roads vector");
}

Road* Simulation::findRoad(const std::string& roadName) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling findRoad");
    for (Road* r : roads) {
        if (r->getName() == roadName) {
            return r;
        }
    }
    return nullptr;
}

int Simulation::countVehicles() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized when calling countVehicles");
    int amount = 0;
    for (Road* road : roads) amount += road->getVehicles().size();
    ENSURE(amount >= 0, "Cannot have a negative amount of vehicles");
    return amount;
}

void Simulation::writeOn(std::ostream& onStream, const double stopAt, int speedup) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    // Loop while there are still vehicles
    // in the simulation
    while (countVehicles() > 0) {
        // Compute the current time and check if we should still
        // be running the simulation. We have a stopAt parameter for tests
        // using the Vehicle Generator feature.
        double currentTime = timestamp * gSimTime;
        if (stopAt != 0 && currentTime > stopAt) return;

        // Print the log entry header
        onStream << "-------------------------------------------" << std::endl;
        onStream << "Time: T+ " << currentTime << "s" << std::endl;

        // Loop over all roads
        for (Road* road : roads) {
            // Tick all entities on the road
            // we have these methods on the Simulation class as they control 
            // the general flow of the simulation, not the road itself.
            road->tick(onStream);
        }

        // Increment relative 
        timestamp++;

        // Sleep until the next simulation tick
         std::this_thread::sleep_for(std::chrono::milliseconds((int)(gSimTime * 1000 / (speedup*10000))));
    }
}

nlohmann::json Simulation::dumpState() {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    nlohmann::json j;

    std::vector<nlohmann::json> vehiclesSerialized;
    for (Road* road : roads) {
        for (Vehicle* vehicle : road->getVehicles()) {
            nlohmann::json v;
            v["road"] = road->getName();
            v["type"] = vehicle->getType();
            v["position"] = vehicle->getPosition();

            vehiclesSerialized.push_back(v);
        }
    }

    std::vector<nlohmann::json> trafficLightsSerialized;
    for (Road* road : roads) {
        for (TrafficLight* trafficLight : road->getTrafficLights()) {
            nlohmann::json t;
            t["road"] = road->getName();
            t["position"] = trafficLight->getPosition();
            t["isGreen"] = trafficLight->isGreen();

            trafficLightsSerialized.push_back(t);
        }
    }

    j["vehicles"] = vehiclesSerialized;
    j["trafficLights"] = trafficLightsSerialized;

    return j;
}

void Simulation::writeToFile(std::ofstream& fileStream, const double stopAt) {
    REQUIRE(this->properlyInitialized(), "Simulation wasn't initialized properly");

    nlohmann::json j;
    
    std::vector<nlohmann::json> roadsSerialized;
    for (Road* road : roads) {
        nlohmann::json r;
        r["name"] = road->getName();
        r["length"] = road->getLength();

        roadsSerialized.push_back(r);
    }

    std::vector<nlohmann::json> busStopsSerialized;
    for (Road* road : roads) {
       for (BusStop* busStop : road->getBusStops()) {
           nlohmann::json b;
           b["road"] = road->getName();
           b["position"] = busStop->getPosition();

            busStopsSerialized.push_back(b);
       }
    }

    j["roads"] = roadsSerialized;
    j["busStops"] = busStopsSerialized;
    j["simTime"] = gSimTime;

    NullBuffer null_buffer;
    std::ostream null_stream(&null_buffer);

    std::vector<nlohmann::json> logs;

    // Loop while there are still vehicles
    // in the simulation
    while (countVehicles() > 0) {
        // Compute the current time and check if we should still
        // be running the simulation. We have a stopAt parameter for tests
        // using the Vehicle Generator feature.
        double currentTime = timestamp * gSimTime;
        if (stopAt != 0 && currentTime > stopAt) break;

        logs.push_back(dumpState());

        // Loop over all roads
        for (Road* road : roads) {
            // Tick all entities on the road
            // we have these methods on the Simulation class as they control 
            // the general flow of the simulation, not the road itself.
            road->tick(null_stream);
        }


        // Increment relative 
        timestamp++;
    }

    j["logs"] = logs;

    const char *header = R"###(  
    <!DOCTYPE html>
    <html>
        <head>
            <script src="https://pixijs.download/release/pixi.min.js"></script>
            <script src="https://github.com/davidfig/pixi-viewport/releases/download/4.34.4/viewport.min.min.js"></script>
        </head>
        <body style="margin: 0">
        <script>
            async function main() {
                const data =   
    )###";

    const char *footer = R"###(  
    const roadElementTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/roadh.png', { mipmap: true })
                const roadElementTextureVertical = await PIXI.Texture.fromURL('https://img.fuserobotics.io/roadv.png', { mipmap: true })
                const crossRoadTexture = await PIXI.Texture.fromURL("https://img.fuserobotics.io/crossroad.png", { mipmap: true })
                const roadElementLength = 25

                const personalVehicleTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/personalh.png', { mipmap: true })
                const personalVehicleTextureVertical = await PIXI.Texture.fromURL('https://img.fuserobotics.io/personalv.png', { mipmap: true })

                const busVehicleTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/bush.png', { mipmap: true })
                const busVehicleTextureVertical = await PIXI.Texture.fromURL('https://img.fuserobotics.io/busv.png', { mipmap: true })

                const fireTruckVehicleTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/fireh.png', { mipmap: true })
                const fireTruckVehicleTextureVertical = await PIXI.Texture.fromURL('https://img.fuserobotics.io/firev.png', { mipmap: true })

                const ambulanceVehicleTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/ambulanceh.png', { mipmap: true })
                const ambulanceVehicleTextureVertical = await PIXI.Texture.fromURL('https://img.fuserobotics.io/ambulancev.png', { mipmap: true })

                const policeVehicleTextureHorizontal = await PIXI.Texture.fromURL('https://img.fuserobotics.io/policeh.png', { mipmap: true })
                const policeVehicleTextureVertical   = await PIXI.Texture.fromURL('https://img.fuserobotics.io/policev.png', { mipmap: true })

                const busStopTexture = await PIXI.Texture.fromURL('https://img.fuserobotics.io/busstop.png', { mipmap: true })

                const vehicleTypes = {
                    0: [personalVehicleTextureHorizontal, personalVehicleTextureVertical],
                    1: [busVehicleTextureHorizontal, busVehicleTextureVertical],
                    2: [fireTruckVehicleTextureHorizontal, fireTruckVehicleTextureVertical],
                    3: [ambulanceVehicleTextureHorizontal, ambulanceVehicleTextureVertical],
                    4: [policeVehicleTextureHorizontal, policeVehicleTextureVertical],
                }

                const app = new PIXI.Application({
                    width: window.innerWidth,
                    height: window.innerHeight,
                    resolution: window.devicePixelRatio || 1,
                    antialias: true,
                    autoResize: true
                })
                document.body.appendChild(app.view)

                const viewport = new pixi_viewport.Viewport({
                    screenWidth: window.innerWidth,
                    screenHeight: window.innerHeight,
                    worldWidth: 10_000_000,
                    worldHeight: 10_000_000,

                    interaction: app.renderer.plugins.interaction, // the interaction module is important for wheel to work properly when renderer.view is placed or scaled
                })

                app.stage.addChild(viewport)
                viewport.drag().pinch().wheel().decelerate()

                viewport.sortableChildren = true

                const createCircle = (color, x, y) => {
                    const circle = new PIXI.Graphics()
                    circle.beginFill(color)
                    circle.lineStyle(5, 0xffffff)
                    circle.arc(0, 0, 50, 0, Math.PI * 2)
                    circle.position = { x: x, y: y }
                    return circle
                }

                const getMaxY = () => {
                    let maxY = 0
                    for (const child of viewport.children) {
                        let y = child.y + Math.max(child.width, child.height)
                        if (y > maxY) maxY = y
                    }

                    return maxY
                }

                // Create a new texture
                let undrawnRoads = data.roads.filter((road) => !road.drawn)
                while (undrawnRoads.length > 0) {
                    placeRoad(data.roads.indexOf(undrawnRoads[0]), { x: 0, y: getMaxY() + 100 }, false)
                    undrawnRoads = data.roads.filter((road) => !road.drawn)
                }

                let vehicles = new PIXI.Container();
                let trafficLights = new PIXI.Container();
                viewport.addChild(vehicles)
                viewport.addChild(trafficLights)

                for (const log of data.logs) {
                    clearVehicles()
                    clearTrafficLights()
                    
                    for (const vehicle of log.vehicles) drawVehicle(vehicle)
                    for (const trafficLight of log.trafficLights) drawTrafficLight(trafficLight)

                    await new Promise((r) => setTimeout(r), parseFloat(data.simTime) * 1000)
                }

                function clearVehicles() {
                    viewport.removeChild(vehicles)
                    vehicles = new PIXI.Container()
                    viewport.addChild(vehicles)
                }

                function clearTrafficLights() {
                    viewport.removeChild(trafficLights)
                    trafficLights = new PIXI.Container()
                    viewport.addChild(trafficLights)
                }

                function drawVehicle(vehicle) {
                    const roadName = vehicle.road
                    const road = data.roads.find(road => road.name === roadName)
                    const start = road.start

                    const texture = !road.invert ? vehicleTypes[vehicle.type][0] : vehicleTypes[vehicle.type][1]
                    const sprite = new PIXI.Sprite(texture)
                    sprite.scale.set(2, 2)

                    let x, y
                    if (road.invert) {
                        y = start.y + (vehicle.position / roadElementLength) * roadElementTextureVertical.height - sprite.height / 2
                        x = start.x - sprite.width / 2
                    } else {
                        y = start.y - sprite.height / 2
                        x = start.x + (vehicle.position / roadElementLength) * roadElementTextureHorizontal.width - sprite.width / 2
                    }

                    sprite.x = x
                    sprite.y = y
                    vehicles.addChild(sprite)
                }

                function drawTrafficLight(trafficLight) {
                    const roadName = trafficLight.road
                    const road = data.roads.find(road => road.name === roadName)
                    const start = road.start


                    let x, y
                    if (road.invert) {
                        y = start.y + (trafficLight.position / roadElementLength) * roadElementTextureVertical.height
                        x = start.x - roadElementTextureVertical.width / 2
                    } else {
                        y = start.y + roadElementTextureHorizontal.height / 2
                        x = start.x + (trafficLight.position / roadElementLength) * roadElementTextureHorizontal.width
                    }

                    const c = createCircle(trafficLight.isGreen ? 0x00ff00 : 0xff0000, x, y)
                    trafficLights.addChild(c)
                }

                function drawBusStop(busStop) {
                    const roadName = busStop.road
                    const road = data.roads.find(road => road.name === roadName)
                    const start = road.start

                    const sprite = new PIXI.Sprite(busStopTexture)
                    sprite.zIndex = 10
                    sprite.scale.set(0.75, 0.75)

                    let x, y
                    if (road.invert) {
                        y = start.y + (busStop.position / roadElementLength) * roadElementTextureVertical.height - sprite.height / 2
                        x = start.x - sprite.width / 2 + 180
                    } else {
                        y = start.y - sprite.height / 2 + 80
                        x = start.x + (busStop.position / roadElementLength) * roadElementTextureHorizontal.width - sprite.width / 2
                    }

                    sprite.x = x
                    sprite.y = y
                    viewport.addChild(sprite)
                }

                function placeRoad(roadIndex, start, invert) {
                    const road = data.roads[roadIndex]
                    if (road.drawn) return
                    
                    // Create label
                    const text = new PIXI.Text(road.name, {
                        fontFamily: 'Arial',
                        fontSize: 48,
                        fill: 0x000000,
                        align: 'left',
                    })

                    if (invert) {
                        text.x = start.x - 70
                        text.y = start.y + 50
                        text.rotation = Math.PI / 2
                    } else {
                        text.x = start.x + 50
                        text.y = start.y + 70
                    }
                    viewport.addChild(text);
                    
                    // Draw road itself
                    [...Array(road.length / roadElementLength).keys()].forEach((i) => {
                        let roadElement
                        if (invert) {
                            roadElement = new PIXI.Sprite(roadElementTextureVertical)

                            roadElement.y = start.y + i * roadElementTextureVertical.height
                            roadElement.x = start.x - roadElementTextureVertical.width / 2
                            roadElement.zIndex = -1
                        } else {
                            roadElement = new PIXI.Sprite(roadElementTextureHorizontal)

                            roadElement.y = start.y - roadElementTextureHorizontal.height / 2
                            roadElement.x = start.x + i * roadElementTextureHorizontal.width
                            roadElement.zIndex = -1
                        }
                        viewport.addChild(roadElement)
                    })
                    // Update road metadata
                    data.roads[roadIndex].drawn = true
                    data.roads[roadIndex].start = start
                    data.roads[roadIndex].invert = invert

                    // Fetch all busstops
                    const relevantBusStops = (data.busStops || []).filter(busStop => busStop.road === road.name)
                    relevantBusStops.forEach(busStop => drawBusStop(busStop))
                    
                    // Fetch all crossroads
                    const relevantCrossRoads = (data.crossRoads || []).filter((crossRoad) => crossRoad.find((r) => road.name === r.name))

                    for (const [road1, road2] of relevantCrossRoads) {
                        const crossRoadOther = road1.name === road.name ? road2 : road1
                        const crossRoadCurrent = road1.name === road.name ? road1 : road2

                        const otherRoad = data.roads.find((r) => r.name === crossRoadOther.name)
                        if (otherRoad.drawn) continue

                        if (invert) { 
                            const crossRoadX = start.x
                            const crossRoadY = start.y + (crossRoadCurrent.position / roadElementLength) * roadElementTextureVertical.height;

                            const c = new PIXI.Sprite(crossRoadTexture)
                            c.x = crossRoadX - crossRoadTexture.width / 2 + 1
                            c.y = crossRoadY - crossRoadTexture.height / 2 - 2

                            viewport.addChild(c)
                            
                            const offsetX = ((otherRoad.length / roadElementLength) * roadElementTextureHorizontal.width * crossRoadOther.position) / otherRoad.length
                            const offsetY = ((road.length / roadElementLength) * roadElementTextureVertical.height * crossRoadCurrent.position) / road.length
                            placeRoad(data.roads.indexOf(otherRoad), { x: start.x - offsetX, y: start.y + offsetY }, !invert)
                        } else {
                            const crossRoadX = start.x + (crossRoadCurrent.position / roadElementLength) * roadElementTextureHorizontal.width
                            const crossRoadY = start.y;

                            const c = new PIXI.Sprite(crossRoadTexture)
                            c.x = crossRoadX - crossRoadTexture.width / 2 + 1
                            c.y = crossRoadY - crossRoadTexture.height / 2 - 2

                            viewport.addChild(c)

                            const offsetX = ((road.length / roadElementLength) * roadElementTextureHorizontal.width * crossRoadCurrent.position) / road.length
                            const offsetY = ((otherRoad.length / roadElementLength) * roadElementTextureVertical.height * crossRoadOther.position) / otherRoad.length
                            placeRoad(data.roads.indexOf(otherRoad), { x: start.x + offsetX, y: start.y - offsetY }, !invert)
                        }
                    }
                }
            }

            main().catch(console.log)
        </script>
    </body>
</html>

    )###";

    fileStream << header << std::setw(4) << j << std::endl;
}