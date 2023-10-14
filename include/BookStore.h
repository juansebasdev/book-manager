#pragma once

#include <vector>
#include <algorithm>
#include "Book.h"
#include "FileManager.h"

class BookStore
{
private:
    std::vector<Book *> books;
    FileManager fileManager;
    void UpdateDataFile();

public:
    BookStore()
    {
        fileManager = FileManager();
        books = fileManager.ReadFile();
    }

    void AddBook(Book *book);
    Book *GetBook(int id);
    std::vector<Book *> GetBooks() { return books; }
    void DeleteBook(int id);
};