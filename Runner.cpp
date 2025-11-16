#include "Runner.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h> // for unlink

std::pair<bool, std::string> Runner::compileAndRun(const std::string &path) {
    const std::string exeName = "tmp_exec";
    const std::string errFile = "tmp_compile_errors.txt";

    // Build compile command: g++ "path" -o tmp_exec 2> tmp_compile_errors.txt
    std::ostringstream cmd;
    cmd << "g++ \"" << path << "\" -o " << exeName << " 2> " << errFile;
    int rc = std::system(cmd.str().c_str());
    // read error file
    std::ifstream err(errFile);
    std::string errs;
    if (err.is_open()) {
        std::ostringstream ss;
        ss << err.rdbuf();
        errs = ss.str();
        err.close();
    }

    // remove compile errors file
    unlink(errFile.c_str());

    if (!errs.empty()) {
        // compiler errors present
        return {false, errs};
    }

    // If compile returned non-zero but no stderr (rare), treat as failure
    if (rc != 0) {
        return {false, "Compiler returned non-zero exit status."};
    }

    // Run program and capture output using popen
    std::string runCmd = std::string("./") + exeName;
    FILE *pipe = popen(runCmd.c_str(), "r");
    if (!pipe) {
        unlink(exeName.c_str());
        return {false, "Failed to run program."};
    }
    char buffer[256];
    std::ostringstream out;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        out << buffer;
    }
    int status = pclose(pipe);

    // cleanup
    unlink(exeName.c_str());

    return {true, out.str()};
}
