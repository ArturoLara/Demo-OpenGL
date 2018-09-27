#include "fileutils.h"

#include <iostream>

namespace utils
{

std::string readFileString(const std::string &filePath)
{
    std::ifstream fileStream(filePath.c_str());
    if (!fileStream.is_open())
    {
        std::cout << "Error opening: " << filePath << std::endl;
        return "";
    }

    std::stringstream fileStringstream;
    fileStringstream << fileStream.rdbuf();

    fileStream.close();

    return fileStringstream.str();
}

} // namespace utils
