#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>
#include <utility>

struct FileIO {
    // returns {success, lines}
    static std::pair<bool, std::vector<std::string>> loadFile(const std::string &path);
    static bool saveFile(const std::string &path, const std::vector<std::string> &lines);
};

#endif // FILEIO_H
