#pragma once

#include <nlohmann/json.hpp>
#include "Book.h"

class Utils
{
public:
    Book* FromJson(nlohmann::json &obj);
    nlohmann::json ToJson(Book &book);
};