# PSE Traffic Simulator

## Description

### A basic traffic simulation made as a project for a course at the University of Antwerp.

![html visualizer](images/htmlVisualizer.gif)

The main goal of the course was to teach proper coding conventions. That's why all functionality has been properly
tested using the Google Test framework.

Some of the other conventions are using the prefix `g` for constants, using proper inheritance etc.

## Usage

### Input

Taking an `xml` file as an input, the project reads the initial state of traffic.

In this `xml` file, all roads, vehicles, vehicle generators, traffic lights, bus stops and crossroads initial
specifications are specified.

e.g.

```xml
<Road>
    <name>Broadway</name>
    <length>200</length>
</Road>
```

### Vehicle types

We currently support the following vehicle types:

- car
- bus
- priority vehicle types:
    - fire truck
    - ambulance
    - police car

The main differences between these vehicle types is that they all have different characteristics, that is - max speed,
brake distance etc. <br/>
Other than that, busses stop at bus stops and priority vehicle types can go through red lights.

### Output

There's two output formats supported.

#### Terminal

A simple `std::cout` which writes the information to the console.

e.g.

```cpp
Time: T+ 95.0848s
Vehicle 0
-> Road: Broadway
-> Position: 142.212
-> Speed: 7.00959
Vehicle 1
-> Road: Broadway
-> Position: 124.365
-> Speed: 4.02228
Vehicle 2
-> Road: Broadway
-> Position: 112.393
-> Speed: 1.66277
Vehicle 3
-> Road: Broadway
-> Position: 104.435
-> Speed: 0.0877223
```

#### Visualizer

The project also supports a GUI in the browser. The `html` file will be found in `./cmake-build-debug/out.html` after running.
Open the `out.html` file in the browser for a visual overview.

## Behind the screens

### Calculations

Using the fixed values ...

| variable name        | value  |
| -------------------- | ------ |
| simulationTime       | 0.0166 |
| decelerationDistance | 50     |
| brakeDistance        | 15     |
| decelerationFactor   | 0.4    |

... all the other variables needed are calculated using physics formulas.

e.g.
a vehicle that needs to stop has its acceleration decreased in the following manner:

![equation1](images/equation.svg)

## Tools used

- C++ <img src="images/icons/CPP.svg" width="15">
- GoogleTest <img src="images/icons/gtest.svg" width="15">
- HTML <img src="images/icons/HTML.svg" width="15">
- PixiJS <img src="images/icons/pixijs.svg" width="30">
- Vanilla JavaScript <img src="images/icons/JavaScript.svg" width="15">
- JSON  <img src="images/icons/json.png" width="15">
- XML <img src="images/icons/XML.svg" width="15">
- PhotoShop <img src="images/icons/Photoshop.svg" width="15">

## Course

Project Software Engineering
University of Antwerp

## Credits

Professor [Serge Demeyer](https://github.com/sergedemeyer) and assistant Brent van Bladel

[vehicle and road tiles used in visualization]

## License

Distributed under the _Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License_.
See `License.md` for more information.
