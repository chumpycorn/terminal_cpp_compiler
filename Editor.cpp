#include "Editor.h"
#include "FileIO.h"
#include "Runner.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

Editor::Editor() = default;

void Editor::commandLoop() {
    std::string input;
    while (true) {
        std::cout << "editor> ";
        if (!std::getline(std::cin, input)) break;
        if (input.empty()) continue;

        auto parts = splitArgs(input);
        std::string cmd = parts.empty() ? "" : parts[0];

        if (cmd == "quit" || cmd == "q") break;
        else if (cmd == "help") cmdHelp();
        else if (cmd == "open") {
            if (parts.size() < 2) {
                std::cout << "Usage: open <path>\n";
            } else cmdOpen(parts[1]);
        }
        else if (cmd == "save") {
            if (parts.size() >= 2) cmdSave(parts[1]);
            else cmdSave();
        }
        else if (cmd == "show") cmdShow();
        else if (cmd == "insert") {
            if (parts.size() < 2) std::cout << "Usage: insert <line_no>\n";
            else cmdInsert(std::stoi(parts[1]));
        }
        else if (cmd == "append") cmdAppend();
        else if (cmd == "replace") {
            if (parts.size() < 2) std::cout << "Usage: replace <line_no>\n";
            else cmdReplace(std::stoi(parts[1]));
        }
        else if (cmd == "delete") {
            if (parts.size() < 2) std::cout << "Usage: delete <line_no>\n";
            else cmdDelete(std::stoi(parts[1]));
        }
        else if (cmd == "run") cmdRun();
        else {
            std::cout << "Unknown command: " << cmd << " (type 'help')\n";
        }
    }
}

void Editor::cmdOpen(const std::string &path) {
    auto loaded = FileIO::loadFile(path);
    if (loaded.first) {
        lines = loaded.second;
        currentPath = path;
        std::cout << "Loaded " << lines.size() << " lines from " << path << "\n";
    } else {
        std::cout << "Failed to open '" << path << "'\n";
    }
}

void Editor::cmdSave(const std::string &path) {
    std::string outPath = path.empty() ? currentPath : path;
    if (outPath.empty()) {
        std::cout << "No file path set. Use: save <path>\n";
        return;
    }
    if (FileIO::saveFile(outPath, lines)) {
        currentPath = outPath;
        std::cout << "Saved " << lines.size() << " lines to " << outPath << "\n";
    } else {
        std::cout << "Failed to save to '" << outPath << "'\n";
    }
}

void Editor::cmdShow() const {
    if (lines.empty()) {
        std::cout << "(buffer empty)\n";
        return;
    }
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << (i + 1) << ": " << lines[i] << "\n";
    }
}

void Editor::cmdInsert(int lineNo) {
    if (lineNo < 1) lineNo = 1;
    size_t idx = static_cast<size_t>(lineNo - 1);
    if (idx > lines.size()) idx = lines.size();
    std::string text = promptForLine("Insert text");
    lines.insert(lines.begin() + idx, text);
    std::cout << "Inserted at line " << (idx + 1) << "\n";
}

void Editor::cmdAppend() {
    std::string text = promptForLine("Append text");
    lines.push_back(text);
    std::cout << "Appended (now " << lines.size() << " lines)\n";
}

void Editor::cmdReplace(int lineNo) {
    if (lineNo < 1 || static_cast<size_t>(lineNo) > lines.size()) {
        std::cout << "Invalid line number\n";
        return;
    }
    std::string text = promptForLine("Replace text");
    lines[lineNo - 1] = text;
    std::cout << "Replaced line " << lineNo << "\n";
}

void Editor::cmdDelete(int lineNo) {
    if (lineNo < 1 || static_cast<size_t>(lineNo) > lines.size()) {
        std::cout << "Invalid line number\n";
        return;
    }
    lines.erase(lines.begin() + (lineNo - 1));
    std::cout << "Deleted line " << lineNo << "\n";
}

void Editor::cmdRun() const {
    if (currentPath.empty()) {
        std::cout << "You must save to a file first (save <path>), then run that file.\n";
        return;
    }
    auto [ok, output] = Runner::compileAndRun(currentPath);
    if (!ok) {
        std::cout << "=== Compiler errors ===\n" << output << "\n";
    } else {
        std::cout << "=== Program output ===\n" << output << "\n";
    }
}

void Editor::cmdHelp() const {
    std::cout <<
    "Commands:\n"
    "  open <path>       - open a file into buffer\n"
    "  save [<path>]     - save buffer (to current path or given path)\n"
    "  show              - show buffer with line numbers\n"
    "  insert <line_no>  - insert a line before line_no (1-based)\n"
    "  append            - append a line at end\n"
    "  replace <line_no> - replace that line\n"
    "  delete <line_no>  - delete that line\n"
    "  run               - compile and run current file (must be saved)\n"
    "  help              - show this help\n"
    "  quit              - exit editor\n";
}

std::vector<std::string> Editor::splitArgs(const std::string &input) {
    std::istringstream iss(input);
    std::vector<std::string> parts;
    std::string t;
    while (iss >> t) parts.push_back(t);
    return parts;
}

std::string Editor::promptForLine(const std::string &label) {
    std::cout << label << ": ";
    std::string line;
    std::getline(std::cin, line);
    // If the previous extraction left '\n', get a fresh line
    if (line.size() == 0 && !std::cin.eof()) {
        // works in typical cases, but if we came from a previous >> extraction,
        // we already used getline above which will read empty if newline remained.
    }
    return line;
}
