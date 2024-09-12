
# **Project Name**: Bifurcate, a 2D platformer

## **Table of Contents**
1. [Introduction](#introduction)
2. [Features](#features)
3. [Getting Started](#getting-started)
4. [Controls](#controls)
5. [Dependencies](#dependencies)
6. [Building and Running](#building-and-running)
7. [Project Structure](#project-structure)
8. [Known Issues](#known-issues)
9. [Future Improvements](#future-improvements)
10. [License](#license)

## **Introduction**

This is a simple 2D platformer game developed using [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/). My reason for creating and working on this game is to improve my programming skills, and to learn more about game development outside of academia.

The game uses a custom physics engine, along with a custom GUI system. The player can move around, jump, and shoot projectiles. The game features a simple options menu and basic collision detection, along with basic enemy generation.

## **Features**
- 2D character movement (walking, jumping)
- Basic projectile shooting
- Simple physics (gravity, velocity, acceleration, etc)
- Menu system 
- Key and mouse input handling
- Score, timing, player position, mouse position display

## **Getting Started**

Follow the instructions below to get the game up and running on your machine.

### **Prerequisites**
Before you try to build and run the game, make sure you have the following installed:
- C++ Compiler (GCC or Clang)
- SFML Library (version 2.5.1 or later)
- CMake (optional, for cross-platform builds)
- A text editor or IDE (e.g., Visual Studio Code, CLion)
- A linux system may be preferable (e.g., WSL, Ubuntu)
### **Cloning the Repository**
```bash
git clone https://github.com/kza59/Bifurcate.git
cd Bifurcate
```

## **Controls**

- **W**: Move up (Currently does nothing)
- **A**: Move left
- **S**: Move down (Currently does nothing)
- **D**: Move right
- **Space**: Jump
- **Left Mouse Button**: Shoot projectile
- **Escape**: Open options menu (if the game has started)
- **Alt + F4**: Close the game

## **Dependencies**

- **[SFML](https://www.sfml-dev.org/)**: Simple and Fast Multimedia Library for handling graphics, windowing, and audio.
  - Install it via your package manager or from the official website:
    - On Debian/Ubuntu: `sudo apt-get install libsfml-dev`
    - On Windows: Download from the [official SFML site](https://www.sfml-dev.org/download.php)
  
- **Compiler**: A C++ compiler that supports C++11 or higher.

## **Building and Running**

### **Using Makefile**
1. Ensure you have SFML installed on your system.
2. Build the project using the provided `Makefile`:
   ```bash
   make
   ```
3. Run the executable:
   ```bash
   ./main
   ```

### **Using CMake**
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
2. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
3. Build the project:
   ```bash
   cmake --build .
   ```
4. Run the game:
   ```bash
   ./main
   ```

## **Project Structure**

```bash
sfml-2d-platformer/
├── assets/             # Game assets (nothing here yet)
├── src/                # Source files
│   ├── Game.cpp        # Main game function definitions
│   ├── main.cpp        # Main game logic
│   ├── config.cpp      # Config files
├── include/            # Header files
│   ├── Game.h          # Prototype game function declarations
│   ├── GUI.h           # GUI logic
│   ├── Physics.h       # Physics engine
│   ├── config.h        # Game configuration
├── Makefile            # Makefile for building the project
├── README.md           # Readme file
└── LICENSE             # License file
```

## **Known Issues**

- The game seems to experience performance issues at higher resolutions. Still trying to optimize this.
- Collision detection is basic and is currently only between the window border and the game entities.

## **Future Improvements**

- Add sound effects/background music.
- Improve collision detection between player/enemy and player/terrain
- Implement level progression and multiple stages.
- Add enemy AI and health/damage systems.
- Optimize performance for higher resolutions and larger levels.

## **License**

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.
