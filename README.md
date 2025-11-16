
# Tiny C++ Terminal Editor

A minimal, terminal-based C++ editor.  
Supports basic line editing, saving, loading, and compiling/running C++ programs.

---

## Features
- Line-based editing: insert, append, replace, delete
- Open and save `.cpp` files
- Compile and run saved files using `g++` or `clang++`
- Show buffer with numbered lines
- Help and quit commands

---

## Build

Requires **C++17 compiler** (g++ or clang++).

### Using clang++
```bash
clang++ -std=c++17 main.cpp Editor.cpp FileIO.cpp Runner.cpp -o tinyeditor
````

### Using g++

```bash
g++ -std=c++17 main.cpp Editor.cpp FileIO.cpp Runner.cpp -o tinyeditor
```

---

## Run

```bash
./tinyeditor
```

---

## Commands

| Command             | Description                                         |
| ------------------- | --------------------------------------------------- |
| `open <path>`       | Load a file into buffer                             |
| `save [<path>]`     | Save buffer to file (current path if not specified) |
| `show`              | Show all lines with line numbers                    |
| `insert <line_no>`  | Insert a new line before the given line number      |
| `append`            | Add a new line at the end                           |
| `replace <line_no>` | Replace the specified line                          |
| `delete <line_no>`  | Delete the specified line                           |
| `run`               | Compile and run the current saved file              |
| `help`              | Show all commands                                   |
| `quit`              | Exit editor                                         |

---

## Getting Started

### 1. Start the editor

```bash
./tinyeditor
```

You will see the prompt:

```
Tiny C++ Terminal Editor — type 'help' for commands
editor>
```

### 2. Create a new program

```text
editor> append
Append text: #include <iostream>
editor> append
Append text: int main() { std::cout << "Hello Tiny Editor!\n"; return 0; }
editor> show
1: #include <iostream>
2: int main() { std::cout << "Hello Tiny Editor!\n"; return 0; }
```

### 3. Save your file

```text
editor> save hello.cpp
Saved 2 lines to hello.cpp
```

### 4. Run your program

```text
editor> run
=== Program output ===
Hello Tiny Editor!
```

### 5. Exit

```text
editor> quit
```

---

## Example Screenshots

<img width="587" height="376" alt="Screenshot 2025-11-16 at 3 13 00 PM" src="https://github.com/user-attachments/assets/31aad4e4-5643-413e-b7c5-6d67d812b4cc" />
<img width="582" height="371" alt="Screenshot 2025-11-16 at 3 13 24 PM" src="https://github.com/user-attachments/assets/55657f27-c3f7-46e7-bdcb-807642538044" />
<img width="581" height="376" alt="Screenshot 2025-11-16 at 3 14 55 PM" src="https://github.com/user-attachments/assets/8ee60677-26d8-44e7-8e8b-63524d949137" />
<img width="548" height="336" alt="Screenshot 2025-11-16 at 3 17 18 PM" src="https://github.com/user-attachments/assets/cbac5b27-a2b3-43bc-ac4e-de1bb80c32f4" />


## Notes

* Terminal-based, line editor only (not full-screen).
* Must save file before running.
* Works on macOS/Linux. Windows users may need small adjustments (`tmp_exec.exe`).
* Safe for learning and practicing C++ basics.

---


