*This project has been created as part of the 42 curriculum by asato, chagen.*

# cub3D

A simple 3D raycasting engine in C using MiniLibX that renders a navigable maze from a 2D map.

---

## 📚 Description

cub3D is a 42 graphics project inspired by *Wolfenstein 3D*.
It parses a `.cub` file, validates the map, and renders a real-time first-person view using raycasting.

---

## 🚀 Features

* Raycasting-based rendering
* Textured walls (N/S/E/W)
* Movement (W/A/S/D) + rotation (←/→)
* Floor and ceiling colors
* Map parsing and validation
* Clean error handling

---

## 🏗️ Architecture

**Architecture:** The project follows a modular, layered architecture with clear separation of concerns.
**Unit Testing:** Core logic is decoupled from MiniLibX to enable unit testing.
**Includes:** Each file includes only the headers it directly depends on to keep dependencies explicit.
**Ownership:** Modules manage their own resources via dedicated init/cleanup functions, ensuring clear memory ownership. **Cleanup is handled locally:** allocating functions return errors, and callers free partial state.

---

## 🛠️ Instructions 

```bash
make
./cub3D maps/example.cub
```

---

## 🎮 Controls

* **W/A/S/D** → Move
* **←/→** → Rotate
* **ESC** → Exit

---

## 📚 Resources
- Ai was used to help writing this readme file.
- Ressource about LeakSanatizer [MaskRay][https://maskray.me/blog/2023-02-12-all-about-leak-sanitizer].



