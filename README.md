
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

**Editor prompt after starting:**
![Editor start](screenshots/start.png)

**Appending lines:**
![Appending code](screenshots/append.png)

**Showing buffer:**
![Show buffer](screenshots/show.png)

**Running program output:**
![Program output](screenshots/run.png)

> Replace these placeholders with actual screenshots or GIFs.

---

## Notes

* Terminal-based, line editor only (not full-screen).
* Must save file before running.
* Works on macOS/Linux. Windows users may need small adjustments (`tmp_exec.exe`).
* Safe for learning and practicing C++ basics.

---


