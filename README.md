#  QtPhoneBookPro

A lightweight phonebook application built with **Qt 6.9** and **C++**.  
Designed for learning, testing, and managing contacts with a user-friendly interface and fast local execution.  
Includes a one-click installer for quick access.

---

##  Features

- Modern GUI built with Qt 6.9
- C++ backend for fast and clear logic
- Add, edit, and delete contacts easily
- Local data storage (no network required)
- Ready-to-use installer for Windows
- Simple structure — great for Qt/C++ beginners

---

##  Development Environment

- **Framework:** Qt 6.9
- **Language:** C++17
- **Build System:** CMake (or use Qt Creator)
- **Platform:** Windows (cross-platform capable)

---

##  How to Run

###  Option 1: Use Installer

Just run the provided installer (`QtPhoneBookInstaller.exe`) and follow the instructions. No Qt installation is required.

###  Option 2: Build from Source

```bash
git clone https://github.com/youjiang666/PhoneBookPro-with-ui.git
cd QtPhoneBookPro
mkdir build && cd build
cmake ..
cmake --build .
./QtPhoneBookPro
Make sure Qt 6.9 is installed and CMake can find it.

 Project Structure

QtPhoneBookPro/
├── CMakeLists.txt            # Build configuration
├── main.cpp                  # Entry point
├── mainwindow.*              # Main UI and logic
├── contact.*                 # Contact class
├── phonebook.*               # Phonebook logic
├── appicon.ico               # Application icon
├── QtPhoneBookInstaller.exe  # One-click installer
└── build/                    # Build directory (ignored)
