#pragma once

#include <nlohmann/json.hpp>
#include <memory>
#include "Book.h"

class Utils
{
public:
    std::shared_ptr<Book> FromJson(nlohmann::json &obj);
    nlohmann::json ToJson(std::shared_ptr<Book> &book);
};