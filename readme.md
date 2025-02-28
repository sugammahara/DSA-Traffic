Traffic Queue Simulation

A real-time traffic intersection simulation using queue data structures for effective traffic control. This project models various vehicle types, traffic lights, and priority-based queuing.



Requirements

To run the simulation, ensure you have:

- 🖥️ GCC/G++ compiler
- 🎮 SDL2 library
- 🏗️ MinGW (for Windows users)

### 🛠 Setting Up SDL2

Windows Installation:
Download SDL2
Extract the files into your project directory

Compiling the Project

Clone the repository:

git clone https://github.com/sugammahara/DSA-Traffic.git
cd DSA-Queue-Simulator

 Compile the main application:

g++ -Iinclude -Llib -o bin/main.exe src/main.c src/traffic_simulation.c -lmingw32 -lSDL2main -lSDL2


Compile the vehicle generator:

g++ -o bin/generator src/generator.c src/traffic_simulation.c -lSDL2 -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2


## ▶️ Running the Simulation

Launch the vehicle generator:

./bin/generator

Open another terminal and run the main simulation:

./bin/main

## 🚙 Vehicle Categories
- 🚗 Standard cars
- 🚑 Ambulances
- 🚔 Police vehicles
- 🚒 Fire trucks

## 🏁 Traffic Control Mechanism

- 🚦 **Queue Management:** Each lane maintains a queue.
- 🚨 **Priority System:** Emergency vehicles receive higher priority.
- 🔄 **Traffic Light Sequences:** Automatic red-green transitions.
- 🔁 **Directional Movements:** Vehicles can turn left, right, or go straight.


Queue Implementation

typedef struct Node {
    Vehicle vehicle;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;


Vehicle Movement States

typedef enum{
    STATE_MOVING,
    STATE_STOPPING,
    STATE_STOPPED,
    STATE_TURNING
    } VehicleState;

Key Features

- 🏎️ Simulated 4-way intersection with moving vehicles
- 🚑🚓🚒 Priority-based handling for emergency vehicles
- 🚦 Automated traffic light system
- 🔄 Vehicles can move straight, turn left, or right
- 🎯 Queue-based traffic flow management

## 📚 Resources
- 📖 [SDL2 Official Docs](https://wiki.libsdl.org/)
- 📘 CLRS: Introduction to Algorithms (Queue Data Structures)
- 🚦 Traffic Flow Theory: Highway Capacity Manual

