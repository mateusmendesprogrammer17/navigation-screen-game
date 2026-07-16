# Navigation Screen Game
[🇺🇸 English](README.md) | [🇧🇷 Português-Brasil](README.pt-BR.md)
A lightweight **C++20 screen navigation library** for games using a stack-based system.

## About

Many C++ developers create games without using a complete game engine. Libraries such as **Raylib**, **Allegro**, and other multimedia frameworks provide excellent tools for rendering, audio, input, and other game features.

However, these libraries usually do not provide a complete screen/state navigation system.

As projects grow, developers often end up creating large `switch` statements and complex state management systems to control:

- Main menu
- Gameplay
- Pause menu
- Options
- Game over screens
- Loading screens

**Navigation Screen Game** was created to solve this problem.

The library uses a **stack-based navigation system** to manage game screens, providing a cleaner and more organized way to control different states of a game.

---
# Runtime of library
This library is currently built using the static Microsoft Visual C++ Runtime:

| Configuration | Runtime |
|---|---|
| Debug | `/MTd` |
| Release | `/MTd` |

Projects using this library should use the same runtime configuration.

Using different runtime libraries may cause linker errors.
/MT with /MD
/MTd with /MDd aren't recommended.

___ 

# Features

- Simple screen navigation system.
- Stack-based screen management.
- Object-oriented design.
- Easy integration with existing C++ projects.
- Compatible with:
  - Raylib
  - Allegro
  - SDL
  - Custom rendering systems.
- Designed for C++20.

---

# Project Structure

Current project structure:

```
NavigationPage/
        
├── CMakeLists.txt
├── Navigator.cpp
├── Navigator.h
├── Screen.cpp
├── Screen.h
├── NavigationPage.vcxproj
├── NavigationPage.slnx

└── x64/
    ├── Debug/
    └── Release/
```

---

# How It Works

## Screen

`Screen` is the base class that should be inherited by your game screens.

Every screen in your game can inherit from this class.

Example:

```cpp
#include "Screen.h"

class MenuScreen : public Screen
{
public:

    void Update() override;
    void Draw() override;

};
```

A screen can represent:

- Main menu
- Gameplay
- Pause menu
- Settings
- Credits
- Loading screen

The rendering system is controlled by your own project.

You can use any graphics library:

- Raylib drawing functions.
- Allegro rendering.
- SDL.
- OpenGL.
- Any custom renderer.

---

# Navigator

`Navigator` is responsible for controlling the screen stack.

It does not inherit from any class.

The developer creates their own screens and uses `Navigator` to manage navigation between them.

Example concept:

```
Screen Stack

+----------------+
|   Game Screen  |
+----------------+
| Pause Screen   |
+----------------+
| Menu Screen    |
+----------------+

        |
        v

     Navigator
```

The stack system allows:

- Adding new screens.
- Removing screens.
- Returning to previous screens.
- Changing game states without large conditional structures.

---

# What Navigation Screen Game DOES NOT DO

This library only handles screen navigation.

It does **not** provide:

- Rendering system.
- Physics engine.
- Collision detection.
- Audio system.
- Input management.
- Asset management.
- Game engine features.

These systems must be implemented by your project or another library.

Example:

```
Raylib / Allegro / SDL

          |
          |
          v

Navigation Screen Game

          |
          |
          v

Your Game Screens
```

---

# Requirements

## Build Requirements

- CMake 3.16 or newer
- C++20 compatible compiler
 
## Supported compilers:

- Microsoft Visual C++ (Visual Studio 2022+)
- GCC
- Clang

## Operating Systems

Supported:

- Windows
- Linux
- MacOS

---

# Installation

## Windows - Visual Studio

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/NavigationPage.git
```

Open:

```
NavigationPage.slnx
```

with Visual Studio.

Build the project:

```
Build > Build Solution
```

The static library will be generated:

Debug:

```
x64/Debug/NavigationPage.lib
```

Release:

```
x64/Release/NavigationPage.lib
```

---

# Windows - Visual Studio Code

Requirements:

- Visual Studio Code
- C++ extension
- CMake
- MSVC or MinGW compiler

Build:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

---

# Linux - Visual Studio Code

Install dependencies:

Ubuntu example:

```bash
sudo apt update

sudo apt install build-essential cmake
```

Clone:

```bash
git clone https://github.com/YOUR_USERNAME/NavigationPage.git
```

Build:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

---

# Linux - CLion

1. Open CLion.
2. Select:

```
File > Open
```

3. Choose the project directory.

CLion will automatically detect the CMake project.

Build:

```
Build > Build Project
```

---

# Usage

A game project can organize screens like:

```
Screens/

├── MenuScreen.cpp
├── MenuScreen.h

├── GameScreen.cpp
├── GameScreen.h

├── PauseScreen.cpp
└── PauseScreen.h
```

Each screen inherits from:

```cpp
Screen
```

The `Navigator` controls which screen is active.

---

# Why Navigation Screen Game Exists

Many independent developers use frameworks like:

- Raylib
- Allegro
- SDL

These libraries are powerful and flexible, but screen management is usually left to the developer.

Without a navigation system, projects often become:

```cpp
switch(gameState)
{
    case MENU:
        break;

    case GAME:
        break;

    case PAUSE:
        break;

    case OPTIONS:
        break;
}
```

As the project grows, this approach becomes difficult to maintain.

Navigation Screen Game provides a cleaner solution using:

- Object-oriented programming.
- Screen inheritance.
- Stack-based navigation.

---

# Future Examples

Example projects will be available soon:

- Pong
- Space Invaders

---

# Author

**Mateus Mendes de Freitas**

---

# License

This project is licensed under:

**GNU General Public License v3.0**

See the LICENSE file for more information.