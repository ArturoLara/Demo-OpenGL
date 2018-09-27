#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace utils
{

// Reads a file and return a string with all the file in it
std::string readFileString(const std::string &filePath);

} // namespace utils
