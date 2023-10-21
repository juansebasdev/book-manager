#include "FileManager.h"

void FileManager::WriteFile(std::vector<std::shared_ptr<Book>> books)
{
    nlohmann::json jsonBooks = nlohmann::json::array();
    nlohmann::json j;

    Utils utils = Utils();

    for (auto &book : books)
    {
        j = utils.ToJson(book);
        jsonBooks.push_back(j);
    }

    std::ofstream DataFile(FILENAME);
    DataFile << std::setw(4) << jsonBooks << std::endl;
}

std::vector<std::shared_ptr<Book>> FileManager::ReadFile()
{
    Utils utils = Utils();
    nlohmann::json content;
    std::ifstream DataFile(FILENAME);
    content = nlohmann::json::parse(DataFile);

    std::vector<std::shared_ptr<Book>> books;

    for (auto object : content)
    {
        std::shared_ptr<Book> book = utils.FromJson(object);
        books.push_back(book);
    }

    return books;
}