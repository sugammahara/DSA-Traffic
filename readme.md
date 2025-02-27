Traffic Queue Simulation

A real-time traffic intersection simulation using queue data structures for effective traffic control. This project models various vehicle types, traffic lights, and priority-based queuing.



Requirements

To run the simulation, ensure you have:

- 🖥️ GCC/G++ compiler
- 🎮 SDL2 library
- 🏗️ MinGW (for Windows users)

### 🛠 Setting Up SDL2

#### Windows Installation:
1. 🔗 [Download SDL2](https://www.libsdl.org/download-2.0.php)
2. 📂 Extract the files into your project directory
3. 🏗 Organize the following folders if missing:
   - `include/` → For header files
   - `lib/` → For compiled libraries
   - `bin/` → For executable files

## 📂 Project Layout

```
DSA-Queue-Simulator/
├── include/          # Header files
├── lib/              # Library files
├── src/              # Source code
├── bin/              # Executable files
└── README.md
```

## 🏗️ Compiling the Project

1. Clone the repository:
```bash
git clone https://github.com/sugammahara/DSA-Traffic.git
cd DSA-Queue-Simulator
```

2. Compile the main application:
```bash
g++ -Iinclude -Llib -o bin/main.exe src/main.c src/traffic_simulation.c -lmingw32 -lSDL2main -lSDL2
```

3. Compile the vehicle generator:
```bash
g++ -o bin/generator src/generator.c src/traffic_simulation.c -lSDL2 -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2
```

## ▶️ Running the Simulation

1. Launch the vehicle generator:
```bash
./bin/generator
```
2. Open another terminal and run the main simulation:
```bash
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
```

Vehicle Movement States

    STATE_MOVING,
    STATE_STOPPING,
    STATE_STOPPED,
    STATE_TURNING

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

