#include "FileIO.h"
#include <fstream>

std::pair<bool, std::vector<std::string>> FileIO::loadFile(const std::string &path) {
    std::ifstream in(path);
    if (!in.is_open()) return {false, {}};
    std::vector<std::string> out;
    std::string line;
    while (std::getline(in, line)) out.push_back(line);
    return {true, out};
}

bool FileIO::saveFile(const std::string &path, const std::vector<std::string> &lines) {
    std::ofstream out(path);
    if (!out.is_open()) return false;
    for (size_t i = 0; i < lines.size(); ++i) {
        out << lines[i];
        if (i + 1 < lines.size()) out << "\n";
    }
    return true;
}
