# SquareLine_Project

A Qt/QML application developed using C++ with a UI designed in SquareLine Studio and based on the LVGL framework.

---

## 🛠️ Technology Stack

- **Language:** C++
- **Framework:** Qt 6 (Qt Quick / QML)
- **UI Designer:** SquareLine Studio
- **Graphics Library:** LVGL
- **IDE:** Visual Studio Code
- **Build System:** CMake
- **Operating System:** Ubuntu (WSL) / Windows
- **Version Control:** Git

---

## 📂 Project Structure

```
SquareLine_Project/
├── main.cpp
├── main.qml
├── CMakeLists.txt
├── src/
├── assets/
├── images/
└── README.md
```

---

## 🖼️ Application Preview

<img width="497" height="501" alt="image" src="https://github.com/user-attachments/assets/79641c5d-dd61-479d-b676-976abdcce535" />
<img width="492" height="521" alt="image" src="https://github.com/user-attachments/assets/10aba1ab-84fd-46b5-9b47-89a14f294638" />

---

## ⚙️ Setup

### Install Required Packages (Ubuntu/WSL)

```bash
sudo apt update

sudo apt install -y \
build-essential \
cmake \
git \
ninja-build \
qt6-base-dev \
qt6-declarative-dev \
qt6-tools-dev \
qt6-tools-dev-tools
```

---

## 🚀 Build

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

---

## ▶️ Run

From the project root:

```bash
./build/SquareLine_Project
```

Or, if you are already inside the `build` directory:

```bash
./SquareLine_Project
```

---

## 🧰 Development Tools

- Qt Creator (optional)
- Visual Studio Code
- CMake
- Git
- GDB (Debugger)
- WSL (Ubuntu)

---

## 📌 Notes

- Keep the project inside the WSL filesystem (`~/workspace`) for better build performance.
- Windows 11 with WSLg supports running the Qt GUI directly.
- Images used in this README are stored in the `images/` folder.
