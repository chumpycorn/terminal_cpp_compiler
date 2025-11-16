#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <vector>

class Editor {
public:
    Editor();
    void commandLoop();

private:
    std::vector<std::string> lines;
    std::string currentPath;

    void cmdOpen(const std::string &path);
    void cmdSave(const std::string &path = "");
    void cmdShow() const;
    void cmdInsert(int lineNo);
    void cmdAppend();
    void cmdReplace(int lineNo);
    void cmdDelete(int lineNo);
    void cmdRun() const;
    void cmdHelp() const;

    // helpers
    static std::vector<std::string> splitArgs(const std::string &input);
    static std::string promptForLine(const std::string &label);
};

#endif // EDITOR_H
