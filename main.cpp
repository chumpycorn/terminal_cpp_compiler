//
// Created by shu kang on 2025-11-16.
//

#include "Editor.h"
#include <iostream>

int main() {
    Editor editor;
    std::cout << "Tiny C++ Terminal Editor — type 'help' for commands\n";
    editor.commandLoop();
    return 0;
}
