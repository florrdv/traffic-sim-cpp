<h1 align="center">traffic-sim-cpp</h1>

<p style="text-align: center;"><em>A project by Achraf Yandouzi and Flor Ronsmans De Vry for the Project Software Engineering course at the University of Antwerp.</em></p>

___

## Project description
A traffic simulation program in C++ with a focus on clean, maintainable, well-tested code.

## Testing
All functionality in this respository is covered by over 150 unit and integration tests written using the GoogleTest framework.

## Technologies used
- C++ programming language
- GoogleTest
- Pugixml
- nlohmann/json
- PixiJS

## Conventions followed
- Hollywood principle
- Iterative design
- Well-designed contracts
- Input testing / domain testing / output testing
- Well-documented code

## Usage

### Input

Taking an `xml` file as an input, the project reads the initial state of traffic.

In this `xml` file all roads, vehicles, vehicle generators, traffic lights, bus stops and crossroads initial
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

- Car
- Bus
- Priority vehicles:
    - Fire truck
    - Ambulance
    - Police car

These vehicles all have different characteristics, including but not limited to speed, brake distance and traffic priority. This means that priority vehicles are allowed to run red lights.

In addition to that, busses also stop at their designated bus stops.

### Output

We currently support two output formats, explained below.

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

The project also supports a GUI in the browser. The program will generate an `out.hmtl` file which can be opened in your desired browser for a visual representation of the simulation.

<div><img src="demo/visualizer.gif" /></div>

## Behind the scenes

### Calculations

Using the following fixed values:

| variable name        | value  |
| -------------------- | ------ |
| simulationTime       | 0.0166 |
| decelerationDistance | 50     |
| brakeDistance        | 15     |
| decelerationFactor   | 0.4    |

All other values are calculated using their respective physics formulas.

e.g.
a vehicle that needs to stop has its acceleration decreased in the following manner:

![equation1](images/equation.svg)

## License

Distributed under the _Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License_.
See `License.md` for more information.
