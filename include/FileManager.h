#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Book.h"
#include "Utils.h"

class FileManager
{
private:
    std::string FILENAME = "data.json";

public:
    void WriteFile(std::vector<Book *> books);
    std::vector<Book *> ReadFile();
};