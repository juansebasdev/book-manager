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
    void WriteFile(std::vector<std::shared_ptr<Book>> books);
    std::vector<std::shared_ptr<Book>> ReadFile();
};