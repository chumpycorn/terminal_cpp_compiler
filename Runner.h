#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include <utility>

// Returns {compiled_successfully, output_or_errors}
struct Runner {
    static std::pair<bool, std::string> compileAndRun(const std::string &path);
};

#endif // RUNNER_H
