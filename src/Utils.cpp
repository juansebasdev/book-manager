#include "Utils.h"

Book* Utils::FromJson(nlohmann::json &obj)
{
    Book *book = new Book();

    book->SetId(obj["id"]);
    book->SetTitle(obj["title"]);
    book->SetDescription(obj["description"]);

    return book;
}

nlohmann::json Utils::ToJson(Book &book)
{
    nlohmann::json j;

    j["id"] = book.GetId();
    j["title"] = book.GetTitle();
    j["description"] = book.GetDescription();

    return j;
}