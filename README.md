# C++ CLI Sudoku Game

A console-based Sudoku game built in C++ featuring game state persistence through file handling. This project represents my first milestone in software development, focusing on procedural programming and data management.

## 🚀 Features
* **Persistent Save System:** Create up to 3 different game slots. Your progress is saved to `.txt` files so you can resume later.
* **Dynamic Grid Generation:** Generates puzzles by shuffling a base valid Sudoku grid and masking cells.
* **Validation Logic:** Real-time checking for row, column, and 3x3 sub-grid rules.
* **Game Management:** Full Menu system allowing users to Create, Load, and Delete game states.

## 🛠️ Technical Implementation
* **Language:** C++
* **File Handling:** Uses `fstream` for reading and writing game arrays to disk.
* **Libraries:** `<iostream>`, `<windows.h>` (for CLI clearing), `<ctime>` (for randomization).

## 🎮 How to Play
1. Compile the `22L-6714-TermProject.cpp` file using any C++ compiler (e.g., MinGW or Visual Studio).
2. Run the executable.
3. Select "New Game" to generate a puzzle.
4. Input coordinates (Row/Column) and the number (1-9) to fill the grid.
5. Save and exit at any time to resume later via "Load Game."
