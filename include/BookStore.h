#pragma once

#include <vector>
#include <algorithm>
#include "Book.h"
#include "FileManager.h"

class BookStore
{
private:
    std::vector<std::shared_ptr<Book>> books;
    FileManager fileManager;
    void UpdateDataFile();

public:
    BookStore()
    {
        fileManager = FileManager();
        books = fileManager.ReadFile();
    }

    void AddBook(std::shared_ptr<Book> book);
    std::shared_ptr<Book> GetBook(int id);
    std::vector<std::shared_ptr<Book>> GetBooks() { return books; }
    void DeleteBook(int id);
};