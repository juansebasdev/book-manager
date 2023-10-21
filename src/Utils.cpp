#include "Utils.h"

std::shared_ptr<Book> Utils::FromJson(nlohmann::json &obj)
{
    std::shared_ptr<Book> book = std::make_unique<Book>(Book());

    book->SetId(obj["id"]);
    book->SetTitle(obj["title"]);
    book->SetDescription(obj["description"]);

    return book;
}

nlohmann::json Utils::ToJson(std::shared_ptr<Book> &book)
{
    nlohmann::json j;

    j["id"] = book->GetId();
    j["title"] = book->GetTitle();
    j["description"] = book->GetDescription();

    return j;
}