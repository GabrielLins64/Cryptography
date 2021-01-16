#pragma once

#include <fstream>
#include <iostream>

std::string ReadFromFile(const std::string filePath)
{
    std::string text;
    std::ifstream file(filePath);
    text.assign( (std::istreambuf_iterator<char>(file)),
                 (std::istreambuf_iterator<char>()));
    file.close();
    return text;
}

void WriteToFile(const std::string filePath, const std::string text, bool append = false)
{
    std::ofstream file;
    if(append) file.open(filePath, std::ios_base::app);
    else file.open(filePath);
    file << text;
    file.close();
}
