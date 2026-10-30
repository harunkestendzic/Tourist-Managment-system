# Tourist Management System

A Qt desktop app for registering tourists and travel packages.

## Features

- Separate windows to register a tourist, add a package, and find a tourist or a package
- A small SQLite database with two tables: `Tourist` (name, passport number, contact, address, package) and `Package` (name, description, amount)
- Screens designed in Qt Designer (`.ui` files) and built with CMake

## Tech

C++, Qt 6 (Widgets, SQL), SQLite, CMake.

## Structure

```
Harunov_projekat/   source code, .ui forms, CMakeLists.txt
database/           MyTouristManager.db (SQLite)
```

## Build and run

1. Install Qt 6 with the Qt SQL module and Qt Creator.
2. Open `Harunov_projekat/CMakeLists.txt` in Qt Creator and configure a kit.
3. **Set the database path.** The code opens the database by the absolute path `S:/database/MyTouristManager.db` from the original machine; edit it in the files that open it (`registertourist.cpp`, `addpackage.cpp`, `findtourist.cpp`, `findpackage.cpp`; search for `S:/database`) so it points to `database/MyTouristManager.db` on your computer.
4. Build and run.

## Status

A university project. Possible improvements: load the database path from one place (or a relative path), and add input validation.

## Author

Harun Kestendžić — [GitHub](https://github.com/harunkestendzic)
